#include "mcu_io.h"

void io_init() {    
    // Config the Activity LED port
    ACT_LEDDDR |= _BV(ACT_LED_P); // Make LED port an output
    ACT_LEDPORT &= ~(_BV(ACT_LED_P)); // Turn the LED off

    // Configure the external reset signal
    CRESET_DDR |= _BV(CRESET_RST); // Output
    CRESET_PORT |= _BV(CRESET_RST); // Set it to high 

    // Configure the SRAM controls
    SRAM_DDR |= _BV(SRAM_CE) | _BV(SRAM_EXTOE) | _BV(SRAM_OE) | _BV(SRAM_WE); // All outputs
    SRAM_PORT |= _BV(SRAM_CE) | _BV(SRAM_EXTOE) | _BV(SRAM_OE) | _BV(SRAM_WE); // Set them all to high

    // Config the SIPO shifter ports
    SIPO_DDR_1 |= (_BV(SIPO_1_SER) | _BV(SIPO_1_CLK) | _BV(SIPO_1_RST)); // Configure these pins as output
    SIPO_DDR_2 |= (_BV(SIPO_2_RCLK) | _BV(SIPO_2_OE));
    SIPO_PORT_2 |= _BV(SIPO_2_OE); // Make sure the /OE for the '595s is high
    
    // Config the PISO shifter ports
    PISO_DDR |= (_BV(PISO_CLK) | _BV(PISO_CLR) | _BV(PISO_PE) | _BV(PISO_CE)); // Outputs
    PISO_DDR  &= ~_BV(PISO_SER); // Inputs
    PISO_PORT &= ~_BV(PISO_SER); // Disable pullup on input

    // Set the other ports for PAL communication as IN or OUT
    DDRC &= ~(_BV(2) | _BV(3)); // PC2,3 as inputs
    DDRD &= ~_BV(7); // PD7 as input
    PORTC |= (_BV(2) | _BV(3)); // Enable PC2-5 internal pull-ups
    PORTD |= _BV(7); // Enable PD7 internal pull-up
}
