#include "sipo_shifter.h"

#include <util/delay.h>
#include <mcu_io.h>

static inline void toggle_SRCLK(void);
static inline void toggle_RCLK(void);

void sipo_shifter_init(void) {
    SIPO_PORT_2 |= _BV(SIPO_2_OE); // Disable the outputs (/OE high)
    SIPO_PORT_1 &= ~(_BV(SIPO_1_SER)); // Set SER low for now
    SIPO_PORT_2 &= ~(_BV(SIPO_2_RCLK)); // Set SRCLK low for now

    SIPO_PORT_1 &= ~(_BV(SIPO_1_RST)); // Reset the shift registers (/SRCLR low)
    _delay_ms(5);
    SIPO_PORT_1 |= _BV(SIPO_1_RST); // /SRCLR high
}

void sipo_shifter_set(uint8_t *data, uint8_t len) {
    uint16_t bitCount = 8 * len;

    for(uint8_t i = 0; i < bitCount; i++) {
        if((data[i/8] >> (i%8)) & 0x01) SIPO_PORT_1 |= _BV(SIPO_1_SER); // High
        else SIPO_PORT_1 &= ~(_BV(SIPO_1_SER)); // Low

        toggle_SRCLK();
    }

    toggle_RCLK(); // Send out the values 
}

static inline void toggle_SRCLK(void) {
    SIPO_PORT_1 |= _BV(SIPO_1_CLK); // Set CLK high
    _delay_us(1);
    SIPO_PORT_1 &= ~(_BV(SIPO_1_CLK)); // Set CLK low
}

static inline void toggle_RCLK(void) {
    SIPO_PORT_2 |= _BV(SIPO_2_RCLK); // Set RCLK high
    _delay_us(1);
    SIPO_PORT_2 &= ~(_BV(SIPO_2_RCLK)); // Set RCLK low
}

void sipo_shifter_OE(uint8_t status) {
    if(status) SIPO_PORT_2 |= _BV(SIPO_2_OE); // High, disable the outputs
    else SIPO_PORT_2 &= ~_BV(SIPO_2_OE); // Low, Enable the outputs
}