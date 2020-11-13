#include "millis.h"

#include <avr/interrupt.h>
#include <util/atomic.h>

static volatile uint32_t millis_counter;

void millis_init(void) {
    uint16_t ctc_match_overflow = ((F_CPU / 1000) / 8); // When this value gets matched, 1ms passed
    
    millis_counter = 0; // Clear the millisecond counter

    // Clear timer when the count matches ctc_match_overflow, and set clock divider by 8
    TCCR1B |= (1 << WGM12) | (1 << CS11);
  
    // Load the value for the timer
    OCR1AH = ctc_match_overflow >> 8;
    OCR1AL = ctc_match_overflow & 0xFF;
 
    // Enable compare-match interrupt
#if defined (__AVR_ATmega328P__)
    TIMSK1 |= (1 << OCIE1A);
#elif defined (__AVR_ATmega8A__)
    TIMSK |= (1 << OCIE1A);
#endif
}

uint32_t millis(void) {
    uint32_t rval;
 
    // Execute this atomically
    ATOMIC_BLOCK(ATOMIC_FORCEON) {
        rval = millis_counter;
    }

    return rval;
} 

// Handler for the timer interrupt
ISR(TIMER1_COMPA_vect) {
    millis_counter++;  
}