#include "ioutils.h"

#include <shifter/sipo_shifter.h>
#include <shifter/piso_shifter.h>

void ioutils_setRESET(uint8_t status) {
    if(!status) CRESET_PORT &= ~(_BV(CRESET_RST));
    else CRESET_PORT |= _BV(CRESET_RST);
}

void ioutils_setSRAM_OE(uint8_t status) {
    if(!status) SRAM_PORT &= ~(_BV(SRAM_OE));
    else SRAM_PORT |= _BV(SRAM_OE);
}

void ioutils_setSRAM_WE(uint8_t status) {
    if(!status) SRAM_PORT &= ~(_BV(SRAM_WE));
    else SRAM_PORT |= _BV(SRAM_WE);
}

void ioutils_setEXT_OE(uint8_t status) {
    if(!status) SRAM_PORT &= ~(_BV(SRAM_EXTOE));
    else SRAM_PORT |= _BV(SRAM_EXTOE);
}
