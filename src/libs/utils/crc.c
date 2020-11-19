#include "crc.h"

// Taken from AVR350

uint16_t crc_calc(uint8_t *ptr, int16_t count) {
    uint16_t crc;
    uint8_t i;

    crc = 0;
    while (--count >= 0) {
        crc = crc ^ (uint16_t) *ptr++ << 8;
        i = 8;
        do {
            if (crc & 0x8000) crc = crc << 1 ^ 0x1021;
            else crc = crc << 1;
        } while(--i);
    }

    return crc;
}