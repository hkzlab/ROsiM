#include "data_buffer.h"

#include <string.h>

static uint8_t sipo_buffer[SIPO_BUFFER_SIZE];

void clear_sipo_buffer(void) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);
}

void data_to_sipo_buffer(uint16_t data) {
    // Clear the SIPO buffer so that contains data
    sipo_buffer[0] = sipo_buffer[1] = 0;
    sipo_buffer[2] &= 0xE0;

    for(int16_t idx = 15, bit_cnt = 0; idx >= 0; idx--, bit_cnt++) { // We have D0-A15, thus we start with idx 15
        // The first 5 bits in the buffer are unused pins
        sipo_buffer[(5 + bit_cnt)/8] |= ((data >> idx) & 0x01) << ((5 + bit_cnt) % 8);
    }   
}

void address_to_sipo_buffer(uint32_t address) {
    // Clear the SIPO buffer part that interests us, so we can write the address into it
    sipo_buffer[3] = sipo_buffer[4] = 0;
    sipo_buffer[2] &= 0x1F; 

    for(int16_t idx = 18, bit_cnt = 0; idx >= 0; idx--, bit_cnt++) { // We have A0-A18, thus we start with idx 18
        // The first 21 bits (0-20) in the buffer are for data lines and unused pins
        sipo_buffer[(21 + bit_cnt)/8] |= ((address >> idx) & 0x01) << ((21 + bit_cnt) % 8);
    }
}

uint8_t *get_sipo_buffer(void) {
    return sipo_buffer;
}