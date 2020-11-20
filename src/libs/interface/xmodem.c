#include "xmodem.h"

#include <avr/wdt.h>
#include <util/delay.h>

#include <uart/uart.h>
#include <utils/crc.h>
#include <utils/millis.h>
#include <ioutils/ioutils.h>

#define SOH     0x01
#define EOT     0x04
#define ACK     0x06
#define NACK    0x15
#define SYNC    0x43

#define XMODEM_PKT_SIZE 133

#define XMODEM_DEFAULT_TRIES 10
#define XMODEM_XFER_TIMEOUT 1000 // 1 sec without transferred bytes
#define XMODEM_BYTE_TIMEOUT 100 // 100 ms without transferred bytes

static uint8_t packet_buf[XMODEM_PKT_SIZE];

static uint8_t xmodem_sync(uint8_t tries);
static uint8_t xmodem_recv_pkt(void);
static uint8_t xmodem_check_packet(void);
static void xmodem_upload_packet(XMODEM_Dump_Type dtype);

uint8_t xmodem_xfer(XMODEM_Dump_Type dtype) {
    uint8_t nack_retries = 0xFF;
    uint32_t last_packet = millis();
    uint32_t now = 0;

    if(!xmodem_sync(XMODEM_DEFAULT_TRIES)) return 0; // No SYNC, time to exit
    wdt_reset();
    while(nack_retries) {
        if(xmodem_recv_pkt()) {
            ioutils_setLED(1);

            last_packet = millis();

            switch(packet_buf[0]) {
                case SOH:
                    if(!xmodem_check_packet()) { uart_putchar(NACK); nack_retries--; }
                    else {
                        nack_retries = 0xFF;
                        xmodem_upload_packet(dtype);
                        uart_putchar(ACK);
                    }
                    break;
                case EOT: // Transfer completed
                    uart_putchar(ACK);
                    return 1;
                default: // Unknown packet...
                    uart_putchar(NACK);
                    nack_retries--;
                    break;
            }

            ioutils_setLED(0);
        } else uart_putchar(NACK);

        now = millis();
        if((now > last_packet) && ((now - last_packet) > (uint32_t)XMODEM_XFER_TIMEOUT)) { nack_retries--; uart_putchar(NACK); };

        wdt_reset();
    }

    return 0;
}

static uint8_t xmodem_sync(uint8_t tries) {
    uint32_t now;
    
    while(tries--) {
        now = millis();

        uart_putchar(SYNC);
        while((millis() - now) < 3000) { // Wait 3 seconds before putting out another SYNC
            wdt_reset();
            if(uart_charavail()) return 1; // Got something!!!
        }
    }

    return 0;
}

static uint8_t xmodem_check_packet(void) {
    uint16_t crc = crc_calc(&packet_buf[3], 128);
    uint16_t calc_crc = ((uint16_t)packet_buf[131]) << 8 | packet_buf[132];

    if(crc != calc_crc) return 0; // Corrupted

    return 1;
}

static uint8_t xmodem_recv_pkt(void) {
    uint8_t didx = 0;
    uint8_t data = 0;
    
    uint32_t last_data = millis();
    uint32_t now = 0;

    while(didx < XMODEM_PKT_SIZE) {
        if(uart_charavail()) {
            last_data = millis();

            data = uart_getchar();
            packet_buf[didx] = data;
            if(!didx && (data == EOT)) break;
            didx++;
        }

        now = millis();
        if((now > last_data) && ((now - last_data) > (uint32_t)XMODEM_BYTE_TIMEOUT)) return 0; // Transfer timed out

        wdt_reset();
    }

    return 1;
}

static void xmodem_upload_packet(XMODEM_Dump_Type dtype) {
    // TODO: Upload the packet to the SRAMs
}

