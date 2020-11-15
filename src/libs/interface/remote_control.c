#include "remote_control.h"

#include <avr/wdt.h>

#include <stdint.h>
#include <string.h>

#include <util/delay.h>

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
#define CMD_DEFAULT 'D' // Set everything back to defaults
#define CMD_TEST    'T' // Test the SRAMs

#define CMD_ERROR "CMD_ERR\n"
#define CMD_INVALID "CMD_INV\n"
#define RESP_MODEL "[M 01]\n"

static char pkt_buffer[PKT_BUFFER_SIZE];
static char resp_buffer[PKT_BUFFER_SIZE];

static uint8_t iosw_state = 0; // 0 -> internal, 1 -> external
static uint8_t rwsw_state = 0; // 0 -> read, 1 -> write
static uint8_t erst_state = 0; // 0 -> inactive, 1 -> active
static uint32_t address = 0;

static uint8_t sipo_buffer[SIPO_BUFFER_SIZE];

static uint8_t receive_pkt(void);
static void address_to_sipo_buffer(uint32_t address);
static void data_to_sipo_buffer(uint16_t data);
static void restore_defaults(void);

void remote_control(void) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);

    // Setting up the initial state
    restore_defaults();

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
                case CMD_RWSW: {
                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_RWSW;
                        resp_buffer[buf_idx++] = ' ';
                        resp_buffer[buf_idx++] = pkt_buffer[2];
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        if(iosw_state) uart_puts(CMD_INVALID); // If in external mode, won't allow the switch between read and write
                        else if (pkt_buffer[2] == '0') { // Enable write on SRAM
                            ioutils_setSRAM_WE(0);
                            rwsw_state = 1;
                            uart_puts(resp_buffer);
                        } else if (pkt_buffer[2] == '1') { // Disable write on SRAM
                            ioutils_setSRAM_WE(1);
                            rwsw_state = 0;
                            uart_puts(resp_buffer);
                        } else uart_puts(CMD_ERROR); 
                    }
                    break;
                case CMD_ERST: {
                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_ERST;
                        resp_buffer[buf_idx++] = ' ';
                        resp_buffer[buf_idx++] = pkt_buffer[2];
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        if (pkt_buffer[2] == '1') {  // Reset disabled
                            ioutils_setRESET(0);
                            erst_state = 0;
                            uart_puts(resp_buffer);
                        } else if (pkt_buffer[2] == '0') { // Reset enabled
                            ioutils_setRESET(1);
                            erst_state = 1;
                            uart_puts(resp_buffer);
                        } else uart_puts(CMD_ERROR); 
                    }
                    break;
                case CMD_IOSW: {
                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_IOSW;
                        resp_buffer[buf_idx++] = ' ';
                        resp_buffer[buf_idx++] = pkt_buffer[2];
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        if(rwsw_state) uart_puts(CMD_INVALID); // If in write mode, won't allow the switch between internal and external
                        else if (pkt_buffer[2] == '0') { // External mode enabled
                            sipo_shifter_OE(1); // Disable the internal SIPO shifters, this MUST be the FIRST thing we do
                            ioutils_setEXT_OE(0); // Enable external -> internal drivers
                            ioutils_setSRAM_WE(1); // Make double-sure that the write mode is disabled
                            ioutils_setSRAM_CE(0); // Enable the SRAM
                            iosw_state = 1; 
                            uart_puts(resp_buffer);
                        } else if (pkt_buffer[2] == '1') { // Internal mode
                            ioutils_setSRAM_CE(1); // Disable the SRAM
                            ioutils_setEXT_OE(1); // Disable external -> internal drivers
                            sipo_shifter_OE(0); // Enable the SIPO shifters, this MUST be the LAST thing we do
                            iosw_state = 0; 
                            uart_puts(resp_buffer);
                        } else uart_puts(CMD_ERROR); 
                    }
                    break;
                case CMD_READ: {
                        if(rwsw_state || iosw_state) uart_puts(CMD_INVALID); // Must be internal with write disabled
                        else {
                            sipo_shifter_set(sipo_buffer, SIPO_BUFFER_SIZE);
                            ioutils_setSRAM_CE(0); // Enable the SRAM
                            _delay_us(1);
                            uint16_t data = piso_shifter_get();
                            ioutils_setSRAM_CE(1); // Disable the SRAM

                            uint8_t buf_idx = 0;
                            resp_buffer[buf_idx++] = '[';
                            resp_buffer[buf_idx++] = CMD_READ;
                            resp_buffer[buf_idx++] = ' ';
                            strutils_u16_to_str(resp_buffer + buf_idx, data); buf_idx += 4;
                            resp_buffer[buf_idx++] = ']';
                            resp_buffer[buf_idx++] = '\n';
                            resp_buffer[buf_idx++] = 0;

                            uart_puts(resp_buffer);                            
                        }
                    }
                    break;
                case CMD_WRITE: {
                            if(!rwsw_state || iosw_state) uart_puts(CMD_INVALID);
                            else {
                                uint16_t data = strutils_str_to_u16(pkt_buffer+2);
                                data_to_sipo_buffer(data);
                                sipo_shifter_set(sipo_buffer, SIPO_BUFFER_SIZE);
                                ioutils_setSRAM_CE(0); // Enable the SRAM
                                _delay_us(1);
                                ioutils_setSRAM_CE(1); // Disable the SRAM

                                uint8_t buf_idx = 0;
                                resp_buffer[buf_idx++] = '[';
                                resp_buffer[buf_idx++] = CMD_WRITE;
                                resp_buffer[buf_idx++] = ' ';
                                strutils_u16_to_str(resp_buffer + buf_idx, data); buf_idx += 4;
                                resp_buffer[buf_idx++] = ']';
                                resp_buffer[buf_idx++] = '\n';
                                resp_buffer[buf_idx++] = 0;

                                uart_puts(resp_buffer);    
                            }                    
                    }
                    break;
                case CMD_ADDRESS: {
                        address = strutils_str_to_u32(pkt_buffer+2); address &= 0x7FFFF;
                        address_to_sipo_buffer(address);

                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_ADDRESS;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u32_to_str(resp_buffer + buf_idx, address); buf_idx += 8;
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        uart_puts(resp_buffer);
                    }
                    break;
                case CMD_ADRINCR: {
                        address++; address &= 0x7FFFF;
                        address_to_sipo_buffer(address);

                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_ADRINCR;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u32_to_str(resp_buffer + buf_idx, address); buf_idx += 8;
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        uart_puts(resp_buffer);
                    }
                    break;
                case CMD_VIEW: {
                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_VIEW;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u32_to_str(resp_buffer + buf_idx, address); buf_idx += 8;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u8_to_str(resp_buffer + buf_idx, (iosw_state | (rwsw_state << 1) | (erst_state << 2))); buf_idx += 2;
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        uart_puts(resp_buffer);
                    }
                    break;
                case CMD_DEFAULT: {
                        restore_defaults();

                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_DEFAULT;
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        uart_puts(resp_buffer);
                    }
                    break;
                case CMD_TEST: {
                        // TODO: Implement
                        restore_defaults();
                        uart_puts(CMD_INVALID);
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

static void data_to_sipo_buffer(uint16_t data) {
    // Clear the SIPO buffer so that contaisn data
    sipo_buffer[0] = sipo_buffer[1] = 0;
    sipo_buffer[2] &= 0x07;

    for(int16_t idx = 15, bit_cnt = 0; idx >= 0; idx--, bit_cnt++) { // We have D0-A15, thus we start with idx 15
        // The first 5 bits in the buffer are unused pins
        sipo_buffer[(5 + bit_cnt)/8] |= ((data >> idx) & 0x01) << ((5 + bit_cnt) % 8);
    }   
}

static void address_to_sipo_buffer(uint32_t address) {
    // Clear the SIPO buffer part that interests us, so we can write the address into it
    sipo_buffer[3] = sipo_buffer[4] = 0;
    sipo_buffer[2] &= 0xF8; 

    for(int16_t idx = 18, bit_cnt = 0; idx >= 0; idx--, bit_cnt++) { // We have A0-A18, thus we start with idx 18
        // The first 21 bits (0-20) in the buffer are for data lines and unused pins
        sipo_buffer[(21 + bit_cnt)/8] |= ((address >> idx) & 0x01) << ((21 + bit_cnt) % 8);
    }
}

static void restore_defaults(void) {
    // Resetting the default state

    iosw_state = 0; // 0 -> internal, 1 -> external
    rwsw_state = 0; // 0 -> read, 1 -> write
    erst_state = 0; // 0 -> inactive, 1 -> active
    address = 0;

    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);

    sipo_shifter_OE(1); // Disable the outputs of the SIPO shifters
    ioutils_setEXT_OE(1); // Disable external->internal drivers
    ioutils_setSRAM_CE(1); // Disable /CE on the SRAMs
    ioutils_setSRAM_WE(1); // Disable /WE on the SRAMs: read mode
    ioutils_setSRAM_OE(0); // Enable /OE on the SRAMs
    
    sipo_shifter_set(sipo_buffer, SIPO_BUFFER_SIZE); // Start with everything at 0, address and data

    sipo_shifter_OE(0); // Enable the outputs of the SIPO shifters
    ioutils_setRESET(0); // Disable the external reset line     
}
