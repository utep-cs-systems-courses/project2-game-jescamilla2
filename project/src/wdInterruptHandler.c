#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "led-a.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  static int blink_count = 0;
  
  /*
  if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
    }*/

  if (switch1_state_down) {
    state_advance(blink_count);
    if (++blink_count >= 500) {
      blink_count = 0;
    }
  } else if (switch2_state_down) {
    buzzer_set_period(0);
    if (++blink_count >= 500) {
      blink_count = 0;
    }
  } else if (switch3_state_down) {
    alternate_leds(blink_count);
    if (++blink_count >= 500) {
      blink_count = 0;
    }
  } else if (switch4_state_down) {
    buzzer_set_period(0); // turn off buzzer
    led_off(); // turn off LEDs
    blink_count = 0;
  }
}



