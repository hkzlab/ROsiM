#include "data_buffer.h"

#include <string.h>

uint8_t sipo_buffer[SIPO_BUFFER_SIZE];

void clear_sipo_buffer(void) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);
}

void fill_sipo_buffer(uint32_t address, uint16_t data) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);
    int8_t idx, bit_cnt;

    // Address
    for(idx = 18, bit_cnt = 21; idx >= 0; idx--, bit_cnt++) { // We have A0-A18, thus we start with idx 18
        // The first 21 bits (0-20) in the buffer are for data lines and unused pins
        sipo_buffer[bit_cnt >> 3] |= ((address >> idx) & 0x01) << (bit_cnt & 7);
    }

    // Data
    for(idx = 15, bit_cnt = 5; idx >= 0; idx--, bit_cnt++) { // We have D0-A15, thus we start with idx 15
        // The first 5 bits in the buffer are unused pins
        sipo_buffer[bit_cnt >> 3] |= ((data >> idx) & 0x01) << (bit_cnt & 7);
    }  
}
