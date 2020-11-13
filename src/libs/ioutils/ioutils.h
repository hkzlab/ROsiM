#ifndef _IOUTILS_H_
#define _IOUTILS_H_

#include <stdint.h>

void ioutils_setLED(uint8_t status);
void ioutils_setRESET(uint8_t status);
void ioutils_setSRAM_CE(uint8_t status);
void ioutils_setSRAM_OE(uint8_t status);
void ioutils_setSRAM_WE(uint8_t status);
void ioutils_setEXT_OE(uint8_t status);

#endif /* _IOUTILS_H_ */