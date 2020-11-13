#include "ioutils.h"

#include <ioutils/mcu_io.h>
#include <shifter/sipo_shifter.h>
#include <shifter/piso_shifter.h>

void ioutils_setLED(uint8_t status) {
    if(!status) ACT_LEDPORT &= ~(_BV(ACT_LED_P));
    else ACT_LEDPORT |= _BV(ACT_LED_P);
}