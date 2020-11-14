#include "remote_control.h"

#include <avr/wdt.h>

#include <stdint.h>
#include <string.h>

#include <uart/uart.h>
#include <utils/strutils.h>
#include <ioutils/ioutils.h>

#define PKT_BUFFER_SIZE 32
#define PKT_START '>'
#define PKT_END '<'
#define RESP_START '['
#define RESP_END ']'

#define SIPO_BUF_SIZE 5

#define CMD_RESET 'K' // Reset the board
#define CMD_MODEL 'M' // Returns model of the board

#define CMD_ADDRESS 'A' // Set the current address for the RAM
#define CMD_ADRINCR 'I' // Increment the current address by one
#define CMD_WRITE   'W' // Write data at the current address
#define CMD_READ    'R' // Read data at current address

#define CMD_ERST    'E' // Enables or disables the internal reset
#define CMD_IOSW    'S' // Switches SRAM access between internal/external
#define CMD_RWSW    'X' // Switches SRAM between Write and Read mode (when in internal access)

#define CMD_VIEW    'V' // Returns current state

#define CMD_ERROR "CMD_ERR\n"
#define RESP_MODEL "[M 01]\n"

static char pkt_buffer[PKT_BUFFER_SIZE];

static uint8_t iosw_state = 0;
static uint8_t erst_state = 0;
static uint8_t rwsw_state = 0;
static uint32_t address = 0;

static uint8_t sipo_buffer[SIPO_BUF_SIZE];

static uint8_t receive_pkt(void);

void remote_control(void) {
    uart_puts("REMOTE_CONTROL_ENABLED\n");

    while(1) {
        if(receive_pkt()) {
            ioutils_setLED(1);

            switch(pkt_buffer[0]) {
                case CMD_MODEL: {
                        uart_puts(RESP_MODEL);
                    }
                    break;
                case CMD_RESET:
                    while(1); // Will reset the program via watchdog
                default:
                    uart_puts(CMD_ERROR);
                    break;
            }

            ioutils_setLED(0);
        }

        wdt_reset();
    }
}

static uint8_t receive_pkt(void) {
    uint8_t idx = 0, receiving_pkt = 0;
    char c;

    while(1) {
        wdt_reset();

        if(uart_charavail()) {
            c = uart_getchar();
            switch(c) {
                case PKT_START:
                    memset(pkt_buffer, 0, PKT_BUFFER_SIZE);
                    idx = 0;
                    receiving_pkt = 1;                    
                    break;
                case PKT_END:
                    if(receiving_pkt && idx) return 1;
                    else {
                        receiving_pkt = 0;
                        idx = 0;
                    }
                    break;
                default:
                    if(receiving_pkt && (idx < (PKT_BUFFER_SIZE - 1))) { // Leave one empty space for a null
                        pkt_buffer[idx++] = c;
                    }
                    break;
            }
        }
    }
}