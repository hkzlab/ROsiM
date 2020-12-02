#include "data_buffer.h"

#include <string.h>

uint8_t sipo_buffer[SIPO_BUFFER_SIZE];

void clear_sipo_buffer(void) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);
}

void fill_sipo_buffer(uint32_t address, uint16_t data) {
    memset(sipo_buffer, 0, SIPO_BUFFER_SIZE);

    // Address
    // The first 21 bits (0-20) in the buffer are for data lines and unused pins
    sipo_buffer[21 >> 3] |= ((address >> 18) & 0x01) << (21 & 7);
    sipo_buffer[22 >> 3] |= ((address >> 17) & 0x01) << (22 & 7);
    sipo_buffer[23 >> 3] |= ((address >> 16) & 0x01) << (23 & 7);
    sipo_buffer[24 >> 3] |= ((address >> 15) & 0x01) << (24 & 7);
    sipo_buffer[25 >> 3] |= ((address >> 14) & 0x01) << (25 & 7);
    sipo_buffer[26 >> 3] |= ((address >> 13) & 0x01) << (26 & 7);
    sipo_buffer[27 >> 3] |= ((address >> 12) & 0x01) << (27 & 7);
    sipo_buffer[28 >> 3] |= ((address >> 11) & 0x01) << (28 & 7);
    sipo_buffer[29 >> 3] |= ((address >> 10) & 0x01) << (29 & 7);
    sipo_buffer[30 >> 3] |= ((address >> 9) & 0x01) << (30 & 7);
    sipo_buffer[31 >> 3] |= ((address >> 8) & 0x01) << (31 & 7);
    sipo_buffer[32 >> 3] |= ((address >> 7) & 0x01) << (32 & 7);
    sipo_buffer[33 >> 3] |= ((address >> 6) & 0x01) << (33 & 7);
    sipo_buffer[34 >> 3] |= ((address >> 5) & 0x01) << (34 & 7);
    sipo_buffer[35 >> 3] |= ((address >> 4) & 0x01) << (35 & 7);
    sipo_buffer[36 >> 3] |= ((address >> 3) & 0x01) << (36 & 7);
    sipo_buffer[37 >> 3] |= ((address >> 2) & 0x01) << (37 & 7);
    sipo_buffer[38 >> 3] |= ((address >> 1) & 0x01) << (38 & 7);
    sipo_buffer[39 >> 3] |= ((address >> 0) & 0x01) << (39 & 7);

    // Data
    // The first 5 bits in the buffer are unused pins, we have D0-A15, thus we start with idx 15
    sipo_buffer[5 >> 3] |= ((data >> 15) & 0x01) << (5 & 7);
    sipo_buffer[6 >> 3] |= ((data >> 14) & 0x01) << (6 & 7);
    sipo_buffer[7 >> 3] |= ((data >> 13) & 0x01) << (7 & 7);
    sipo_buffer[8 >> 3] |= ((data >> 12) & 0x01) << (8 & 7);
    sipo_buffer[9 >> 3] |= ((data >> 11) & 0x01) << (9 & 7);
    sipo_buffer[10 >> 3] |= ((data >> 10) & 0x01) << (10 & 7);
    sipo_buffer[11 >> 3] |= ((data >> 9) & 0x01) << (11 & 7);
    sipo_buffer[12 >> 3] |= ((data >> 8) & 0x01) << (12 & 7);
    sipo_buffer[13 >> 3] |= ((data >> 7) & 0x01) << (13 & 7);
    sipo_buffer[14 >> 3] |= ((data >> 6) & 0x01) << (14 & 7);
    sipo_buffer[15 >> 3] |= ((data >> 5) & 0x01) << (15 & 7);
    sipo_buffer[16 >> 3] |= ((data >> 4) & 0x01) << (16 & 7);
    sipo_buffer[17 >> 3] |= ((data >> 3) & 0x01) << (17 & 7);
    sipo_buffer[18 >> 3] |= ((data >> 2) & 0x01) << (18 & 7);
    sipo_buffer[19 >> 3] |= ((data >> 1) & 0x01) << (19 & 7);
    sipo_buffer[20 >> 3] |= ((data >> 0) & 0x01) << (20 & 7);
}
