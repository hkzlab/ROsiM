#include "remote_control.h"

#include <avr/wdt.h>

#include <stdint.h>
#include <string.h>

#include <uart/uart.h>
#include <utils/strutils.h>
#include <ioutils/ioutils.h>

#include <shifter/sipo_shifter.h>
#include <shifter/piso_shifter.h>

#define PKT_BUFFER_SIZE 32
#define PKT_START '>'
#define PKT_END '<'
#define RESP_START '['
#define RESP_END ']'

#define SIPO_BUFFER_SIZE 5

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
static char resp_buffer[PKT_BUFFER_SIZE];

static uint8_t iosw_state = 0; // 0 -> internal, 1 -> external
static uint8_t rwsw_state = 0; // 0 -> read, 1 -> write
static uint8_t erst_state = 0; // 0 -> inactive, 1 -> active
static uint32_t address = 0;

static uint8_t sipo_buffer[SIPO_BUFFER_SIZE];

static uint8_t receive_pkt(void);

void remote_control(void) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);

    // Setting up the initial state
    ioutils_setEXT_OE(1); // Disable external->internal drivers
    sipo_shifter_set(sipo_buffer, SIPO_BUFFER_SIZE); // Start with everything at 0
    ioutils_setSRAM_WE(1); // Disable /WE on the SRAMs: read mode
    ioutils_setSRAM_CE(0); // Enable /CE on the SRAMs
    ioutils_setSRAM_OE(0); // Enable /OE on the SRAMs
    sipo_shifter_OE(0); // Enable the outputs of the SIPO shifters
    ioutils_setRESET(1); // Disable the external reset line 

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
                case CMD_VIEW: {
                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_VIEW;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u32_to_str(resp_buffer, address); buf_idx += 8;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u8_to_str(resp_buffer, (iosw_state | (rwsw_state << 1) | (erst_state << 2))); buf_idx += 2;
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        uart_puts(resp_buffer);
                    }
                    break;
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