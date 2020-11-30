#ifndef _IOUTILS_H_
#define _IOUTILS_H_

#include <stdint.h>
#include <ioutils/mcu_io.h>

#define ioutils_setLED(S) if(S) (ACT_LEDPORT |= _BV(ACT_LED_P)); else (ACT_LEDPORT &= ~(_BV(ACT_LED_P)));
#define ioutils_setSRAM_CE(S) if(S) (SRAM_PORT |= _BV(SRAM_CE)); else (SRAM_PORT &= ~(_BV(SRAM_CE)));

void ioutils_setRESET(uint8_t status);
void ioutils_setSRAM_OE(uint8_t status);
void ioutils_setSRAM_WE(uint8_t status);
void ioutils_setEXT_OE(uint8_t status);

#endif /* _IOUTILS_H_ */