#include "remote_control.h"
#include "xmodem.h"
#include "data_buffer.h"

#include <avr/wdt.h>

#include <stdint.h>
#include <string.h>

#include <util/delay.h>

#include <common/defines.h>

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

#define CMD_RESET 'K' // Reset the board
#define CMD_MODEL 'M' // Returns model of the board

#define CMD_ADDRESS 'A' // Set the current address for the RAM
#define CMD_WRITE   'W' // Write data at the current address and increment it
#define CMD_READ    'R' // Read data at current address and increment it

#define CMD_ERST    'E' // Enables or disables the internal reset
#define CMD_IOSW    'S' // Switches SRAM access between internal/external
#define CMD_RWSW    'X' // Switches SRAM between Write and Read mode (when in internal access)

#define CMD_VIEW    'V' // Returns current state
#define CMD_DEFAULT 'D' // Set everything back to defaults, except for the reset logic inversion
#define CMD_TEST    'T' // Test the SRAMs

#define CMD_XMODEM  'O' // XMODEM transfer

#define CMD_ERROR "CMD_ERR\n"
#define CMD_INVALID "CMD_INV\n"
#define RESP_MODEL "[M 01]\n"

static char pkt_buffer[PKT_BUFFER_SIZE];
static char resp_buffer[PKT_BUFFER_SIZE];

static uint8_t iosw_state = 0; // 0 -> internal, 1 -> external
static uint8_t rwsw_state = 0; // 0 -> read, 1 -> write
static uint8_t erst_state = 0; // 0 -> inactive, 1 -> active
static uint32_t address = 0;


static uint8_t receive_pkt(void);

static void restore_defaults(uint8_t reset); // Restores all the IOs to defaults, except the /RESET signal (unless reset is 1)
static uint8_t test_sram(void);
static void format_test_error(char *buf, uint32_t addr, uint16_t data);
static void set_external_reset(uint8_t state);

void remote_control(void) {
    clear_sipo_buffer();

    // Setting up the initial state
    restore_defaults(1);

    uart_puts("REMOTE_CONTROL_ENABLED\n");

    while(1) {
        if(receive_pkt()) {
            ioutils_setLED(1);

            switch(pkt_buffer[0]) {
                case CMD_MODEL: {
                        uart_puts(RESP_MODEL);
                    }
                    break;
                case CMD_RESET: {
                        restore_defaults(1); // So we'll force the board in a safe state
                        while(1); // Will reset the program via watchdog
                    }
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
                        } else if (pkt_buffer[2] == '1') { // Disable write on SRAM, enables read
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

                        if (pkt_buffer[2] == '0') {  // Reset disabled
                            set_external_reset(0);
                            uart_puts(resp_buffer);
                        } else if (pkt_buffer[2] == '1') { // Reset enabled
                            set_external_reset(1);
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
                            ioutils_setSRAM_WE(1); // Make double-sure that the write mode is disabled
                            ioutils_setSRAM_CE(1); // And that the chip itself is disabled
                            _delay_us(250);
                            sipo_shifter_OE(1); // Disable the internal SIPO shifters, this MUST be the FIRST thing we do
                            _delay_us(250);
                            ioutils_setEXT_OE(0); // Enable external -> internal drivers
                            _delay_us(250);
                            ioutils_setSRAM_CE(0); // Enable the SRAM
                            rwsw_state = 0; 
                            iosw_state = 1; 
                            uart_puts(resp_buffer);
                        } else if (pkt_buffer[2] == '1') { // Internal mode
                            ioutils_setSRAM_CE(1); // Disable the SRAM
                            _delay_us(250);
                            ioutils_setEXT_OE(1); // Disable external -> internal drivers
                            _delay_us(250);
                            sipo_shifter_OE(0); // Enable the SIPO shifters, this MUST be the LAST thing we do
                            iosw_state = 0; 
                            uart_puts(resp_buffer);
                        } else uart_puts(CMD_ERROR); 
                    }
                    break;
                case CMD_READ: {
                        if(rwsw_state || iosw_state) uart_puts(CMD_INVALID); // Must be internal with write disabled
                        else {
                            fill_sipo_buffer(address, 0);

                            sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
                            ioutils_setSRAM_CE(0); // Enable the SRAM
                            _NOP();
                            uint16_t data = piso_shifter_get();
                            ioutils_setSRAM_CE(1); // Disable the SRAM

                            address++; address &= 0x7FFFF;

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
                case CMD_XMODEM: {
                        restore_defaults(0); // Reset everything back to default
                        _delay_us(100);
                        ioutils_setSRAM_WE(0); // Enable write mode 

                        uint8_t xfer_stat = 0;
                        switch(pkt_buffer[2]) {
                            case '0':
                            case '1':
                            case '2':
                                xfer_stat = xmodem_xfer(pkt_buffer[2]-0x30);
                                break;
                            default:
                                break;
                        }

                        restore_defaults(0); // Defaults again
                        _delay_us(100);

                        uart_putchar('\n');
                                
                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_XMODEM;
                        resp_buffer[buf_idx++] = ' ';
                        resp_buffer[buf_idx++] = xfer_stat + 0x30;
                        resp_buffer[buf_idx++] = ']';
                        resp_buffer[buf_idx++] = '\n';
                        resp_buffer[buf_idx++] = 0;

                        uart_puts(resp_buffer);                              
                    }
                    break;
                case CMD_WRITE: {
                            if(!rwsw_state || iosw_state) uart_puts(CMD_INVALID);
                            else {
                                uint16_t data = strutils_str_to_u16(pkt_buffer+2);
                                fill_sipo_buffer(address, data);
                                sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
                                ioutils_setSRAM_CE(0); // Enable the SRAM
                                _NOP();
                                ioutils_setSRAM_CE(1); // Disable the SRAM

                                address++; address &= 0x7FFFF;

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
                        restore_defaults(1);

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
                        restore_defaults(1);
                        uint8_t status =  test_sram();
                        restore_defaults(1);

                        uint8_t buf_idx = 0;
                        resp_buffer[buf_idx++] = '[';
                        resp_buffer[buf_idx++] = CMD_TEST;
                        resp_buffer[buf_idx++] = ' ';
                        strutils_u8_to_str(resp_buffer + buf_idx, status); buf_idx += 2;
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

static void restore_defaults(uint8_t reset) {
    // Resetting the default state

    iosw_state = 0; // 0 -> internal, 1 -> external
    rwsw_state = 0; // 0 -> read, 1 -> write
    address = 0;

    clear_sipo_buffer();

    sipo_shifter_OE(1); // Disable the outputs of the SIPO shifters
    ioutils_setEXT_OE(1); // Disable external->internal drivers
    ioutils_setSRAM_CE(1); // Disable /CE on the SRAMs
    ioutils_setSRAM_WE(1); // Disable /WE on the SRAMs: read mode
    ioutils_setSRAM_OE(0); // Enable /OE on the SRAMs
    
    sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE); // Start with everything at 0, address and data

    sipo_shifter_OE(0); // Enable the outputs of the SIPO shifters
    
    if(reset) {
        erst_state = 0; // 0 -> inactive, 1 -> active
        ioutils_setRESET(0); // Disable the external reset line
    }
}

static uint8_t test_sram(void) {
    uint16_t data;
    ioutils_setSRAM_CE(1); // Disable the SRAM
    ioutils_setEXT_OE(1); // Disable external -> internal drivers
    sipo_shifter_OE(0); // Enable the SIPO shifters, this MUST be the LAST thing we do

    uart_puts("# TEST: Started SRAM test.\n");
    
    // Test with 0xAA55
    ioutils_setSRAM_WE(0);
    for(uint32_t addr = 0; addr <= 0x7FFFF; addr++) {
        wdt_reset();
        ioutils_setLED(1);
        fill_sipo_buffer(addr, 0xAA55);
        sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
        ioutils_setSRAM_CE(0); // Enable the SRAM
        _NOP();
        ioutils_setSRAM_CE(1); // Disable the SRAM
    }
    
    uart_puts("# TEST: Written 0xAA55 ...\n");
    
    ioutils_setSRAM_WE(1);
    for(uint32_t addr = 0; addr <= 0x7FFFF; addr++) {
        wdt_reset();
        ioutils_setLED(1);
        fill_sipo_buffer(addr, 0);
        sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
        ioutils_setSRAM_CE(0); // Enable the SRAM
        _NOP();
        data = piso_shifter_get();
        ioutils_setSRAM_CE(1);
        ioutils_setLED(0);
        if(data != 0xAA55) {
            format_test_error(resp_buffer, addr, data);
            uart_puts(resp_buffer);
            return 1;
        }
    }

    uart_puts("# TEST: 0xAA55 OK!\n");

    // Test with 0x55AA    
    ioutils_setSRAM_WE(0);
    for(uint32_t addr = 0; addr <= 0x7FFFF; addr++) {
        wdt_reset();
        ioutils_setLED(1);
        fill_sipo_buffer(addr, 0x55AA);
        sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
        ioutils_setSRAM_CE(0); // Enable the SRAM
        _NOP();
        ioutils_setSRAM_CE(1); // Disable the SRAM
        ioutils_setLED(0);
    }
    
    uart_puts("# TEST: Written 0x55AA ...\n");
    
    ioutils_setSRAM_WE(1);
    for(uint32_t addr = 0; addr <= 0x7FFFF; addr++) {
        wdt_reset();
        ioutils_setLED(1);
        fill_sipo_buffer(addr, 0);
        sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
        ioutils_setSRAM_CE(0); // Enable the SRAM
        _NOP();
        data = piso_shifter_get();
        ioutils_setSRAM_CE(1);
        ioutils_setLED(0);
        if(data != 0x55AA) {
            format_test_error(resp_buffer, addr, data);
            uart_puts(resp_buffer);
            return 1;
        }
    }
    
    uart_puts("# TEST: 0x55AA OK!\n");

    // Incremental test    
    ioutils_setSRAM_WE(0);
    for(uint32_t addr = 0; addr <= 0x7FFFF; addr++) {
        wdt_reset();
        ioutils_setLED(1);
        fill_sipo_buffer(addr, addr & 0xFFFF);
        sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
        ioutils_setSRAM_CE(0); // Enable the SRAM
        _NOP();
        ioutils_setSRAM_CE(1); // Disable the SRAM
        ioutils_setLED(0);
    }
    
    uart_puts("# TEST: Written Incremental ...\n");
    
    ioutils_setSRAM_WE(1);
    for(uint32_t addr = 0; addr <= 0x7FFFF; addr++) {
        wdt_reset();
        ioutils_setLED(1);
        fill_sipo_buffer(addr, 0);
        sipo_shifter_set(get_sipo_buffer(), SIPO_BUFFER_SIZE);
        ioutils_setSRAM_CE(0); // Enable the SRAM
        _NOP();
        data = piso_shifter_get();
        ioutils_setSRAM_CE(1);
        ioutils_setLED(0);
        if(data != (addr & 0xFFFF)) {
            format_test_error(resp_buffer, addr, data);
            uart_puts(resp_buffer);
            return 3;
        }
    }
    
    uart_puts("# TEST: Incremental OK!\n");

    return 0;
}

static void format_test_error(char *buf, uint32_t addr, uint16_t data) {
    uint8_t buf_idx = 0;
    buf[buf_idx++] = '#';
    buf[buf_idx++] = ' ';
    strutils_u32_to_str(buf + buf_idx, addr); buf_idx += 8;
    buf[buf_idx++] = ':';
    strutils_u16_to_str(buf + buf_idx, data); buf_idx += 4;
    buf[buf_idx++] = '\n';
    buf[buf_idx++] = 0;
}

static void set_external_reset(uint8_t state) {
    ioutils_setRESET(state);
    erst_state = state;    
}
