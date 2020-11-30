#include "piso_shifter.h"

#include <util/delay.h>
#include <mcu_io.h>

#include <common/defines.h>

void piso_shifter_init(void) {
    PISO_PORT |= (_BV(PISO_CE) | _BV(PISO_PE)); // Disable the clock (/CE high) and disable the inputs (/PE high)
    PISO_PORT &= ~(_BV(PISO_CLK) | _BV(PISO_CLR)); // CLK and /CLR to low
    _delay_ms(5);
    PISO_PORT |= _BV(PISO_CLR); // Set /CLR high again
}

uint16_t piso_shifter_get(void) {
    uint16_t data = 0;

    PISO_PORT &= ~(_BV(PISO_CE) | _BV(PISO_PE) | _BV(PISO_CLK)); // Enable the clock and the inputs, set clock to low
    _NOP(); _NOP(); _NOP();
    PISO_PORT |= _BV(PISO_CLK); // Clock to high
    _NOP(); _NOP(); _NOP();
    PISO_PORT |= _BV(PISO_PE); // Disable the inputs

    for(uint8_t idx = 0; idx < 16; idx++) {
        _NOP(); _NOP(); _NOP();
        PISO_PORT |= _BV(PISO_CLK); // Clock to high, shift out the data
        _NOP(); _NOP(); _NOP();
        data |= (PIND & _BV(PISO_SER)) ? (1 << idx) : 0;
        PISO_PORT &= ~(_BV(PISO_CLK)); // Clock to low
    }

    PISO_PORT |= (_BV(PISO_CE) | _BV(PISO_PE)); // Disable the clock (/CE high) and disable the inputs (/PE high)
    
    return data;
}