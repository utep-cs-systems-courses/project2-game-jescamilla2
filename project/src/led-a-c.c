#include <msp430.h>
#include "led.h"

void alternate_leds(int blink_count)  /*  250 interrupts per second */
{
  if(blink_count >= 500){       // turn on both LEDs
    P1OUT |= LEDS;
  }else if(blink_count >= 250){    // red on, green
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
  }else if(blink_count >= 125){  // alternate the bits
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  }
}
