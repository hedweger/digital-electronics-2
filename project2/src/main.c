#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC

#define ANGLE1 1200 
#define ANGLE2 2400

volatile uint16_t pos_min = ANGLE1;
volatile uint16_t pos_max = ANGLE2;

int main(void)
{   
    // init timer
    TIM0_overflow_16ms();
    TIM0_overflow_interrupt_enable();

    // init adc converter
    ADMUX = (1 << REFS0);
    ADCSRA = (1 << ADEN) | (1 << ADIE);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    PORTC |= (1 << 2);

    // set the pwm output pins
    DDRB |= (1 << 1);
    DDRB |= (1 << 2);
    // set the comparator registers
    TCCR1A = (1 << COM1A1) | (1 << COM1B1);
    TCCR1A |= (1 << WGM11);
    TCCR1B = (1 << WGM13);
    // set prescaler
    TCCR1B |= (1 << CS11);
    // init servo pos. to default values
    ICR1 = 2000;
    OCR1A = pos_max;
    OCR1B = pos_min; 
    
    sei();
    while (1)
    
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}
void switch_channel(int channel) {
    // variable channel decides which admux channel we look at
    ADMUX &= ~0xF;
    ADMUX |= channel;
    ADCSRA |= (1 << ADSC);
}

ISR(TIMER0_OVF_vect)
{
    switch_channel(0);
}

ISR(ADC_vect)
{
  double value;
  value = 1200.0 + ((ADC / 1200.0) * 1200.0);

  if ((ADMUX & 0xF) == 0) {
    switch_channel(1);
    
    OCR1A = value;

  } else if ((ADMUX & 0xF) == 1) {
    switch_channel(0);
    OCR1B = value;

  }
}