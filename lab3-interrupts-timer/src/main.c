#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#define LED_GREEN PB5
#define LED_RED PB0
#define BUTTON PD0

#define PB5 5
#define PB0 0
#define PD0 0



int main(void)
{
    DDRB |= (1<<LED_GREEN); 
    DDRB |= (1<<LED_RED);
    DDRB &= ~(1<<BUTTON);

    TIM1_overflow_1s();
    // Enable overflow interrupt
    TIM1_overflow_interrupt_enable();
   
    // Enables interrupts by setting the global interrupt mask
    sei();
    while (1)
    {
        
    }
    

}

// Interrupt service routines
ISR(TIMER1_OVF_vect)
{

  if (PIND & (1<<BUTTON)) 
  {
    PORTB ^= (1<<LED_GREEN);
    PORTB ^= (1<<LED_RED);
  }
  

}