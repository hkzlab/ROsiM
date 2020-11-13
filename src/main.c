#include "main.h"

#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#include <interface/remote_control.h>

#include <ioutils/mcu_io.h>
#include <ioutils/ioutils.h>

#include <utils/millis.h>

#include <uart/uart.h> 
#include <shifter/sipo_shifter.h>
#include <shifter/piso_shifter.h>


#define VERSION "0.0.1"
#define SOFT_HEADER "\nROsiM - " VERSION "\n\n"

int main(void) {
#if defined (__AVR_ATmega328P__)
    wdt_enable(WDTO_4S); // Enable the watchdog to reset in 4 seconds...
#elif defined (__AVR_ATmega8A__)
    wdt_enable(WDTO_2S); // Enable the watchdog to reset in 2 seconds...
#endif

    // Initialize the I/O and communications
    io_init();

    // First watchdog kick
    wdt_reset();

    // Initialize serial port
    uart_init();
    
    // Prepare the shifters
    sipo_shifter_init();
    piso_shifter_init();
    
    // Initialize the millisecond library
    millis_init();

    // Enable interrupts
    sei();

    uart_puts(SOFT_HEADER); // Print the header

    ioutils_setLED(0); // Turn off the activity LED

    remote_control();

    uart_puts("DONE.\n");

    // We're done, blink the led at 1Hz and wait for a watchdog reset
    while(1) {
        _delay_ms(1000);
        ioutils_setLED(0);
        _delay_ms(1000);
    }


    return 0;
}
