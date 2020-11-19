#include "xmodem.h"

#include <avr/wdt.h>
#include <util/delay.h>

#include <millis.h>
#include <uart.h>
#include <crc.h>

#define SOH     0x01
#define EOT     0x04
#define ACK     0x06
#define NACK    0x15
#define SYNC    0x43

#define XMODEM_PKT_SIZE 133

#define XMODEM_DEFAULT_TRIES 4

static uint8_t packet_buf[XMODEM_PKT_SIZE];
static int16_t last_pkt = -1;

static uint8_t xmodem_sync(uint8_t tries);
static uint8_t xmodem_recv_pkt(void);
static uint8_t xmodem_check_packet(void);
static void xmodem_upload_packet(XMODEM_Dump_Type dtype);

uint8_t xmodem_xfer(XMODEM_Dump_Type dtype) {
    uint8_t nack_retries = 0xFF;

    if(!xmodem_sync(XMODEM_DEFAULT_TRIES)) return 0; // No SYNC, time to exit
    wdt_reset();
    while(nack_retries) {
        if(xmodem_recv_pkt()) {
            switch(packet_buf[0]) {
                case SOH:
                    if(!xmodem_check_packet()) { uart_putchar(NACK); nack_retries--; }
                    else {
                        nack_retries = 0xFF;
                        last_pkt = packet_buf[1];
                        xmodem_upload_packet(dtype);
                        uart_putchar(ACK);
                    }
                    break;
                case EOT: // Transfer completed
                    return 1;
                default: // Unknown packet...
                    uart_putchar(NACK);
                    nack_retries--;
                    break;
            }

        } else uart_putchar(NACK);

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
            _delay_ms(100);
            if(uart_charavail()) return 1; // Got something!!!
        }
    }

    return 0;
}

static uint8_t xmodem_check_packet(void) {
    uint16_t crc = crc_calc(&packet_buf[3], 128);
    uint16_t calc_crc = ((uint16_t)packet_buf[131]) << 8 | packet_buf[132];
    uint8_t expected_packet = (last_pkt + 1) & 0xFF;

    if(crc != calc_crc) return 0; // Corrupted
    if(packet_buf[1] != expected_packet) return 0; // Have missed a packet?

    return 1;
}

static uint8_t xmodem_recv_pkt(void) {
    uint8_t didx = 0;

    while(didx < XMODEM_PKT_SIZE) {
        if(uart_charavail()) packet_buf[didx++] = uart_getchar();
        else _delay_ms(5);

        wdt_reset();
    }

    return 1;
}

static void xmodem_upload_packet(XMODEM_Dump_Type dtype) {
    // TODO: Upload the packet to the SRAMs
}

