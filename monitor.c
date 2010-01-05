/*
  monitor.c - A module to monitor the stepper pulses, keep track of the ideal position of the simulated
              tool and gather performance statistics
  
  Part of Grbl

  Copyright (c) 2010 Simen Svale Skogsrud

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include <avr/interrupt.h>

#define step_x_mask 1
#define step_y_mask 2
#define dir_x_mask 16
#define dir_y_mask 32


volatile int32_t x_position, y_position;
volatile uint16_t x_steps, y_steps;

void monitor_init() {
  // Configuring IO for the stepper monitor
  // PB0 is step X, PB4 is direction X
  // PB1 is step Y, PB5 is direction X

  // Cofigure entire port B as input
  DDRB = 0;
  // Enable pin change interrupts PCINT0 and PCINT1 (PB0 and PB1)
  PCMSK0 |= ((1<<PCINT0) | (1<<PCINT1));
  // Enable pin change interrupt group PCINT7..0
  PCICR |= (1 << PCIF0);
    
}

uint8_t reading;
uint8_t last_reading;
uint8_t changed;

SIGNAL(SIG_PIN_CHANGE0) {
  reading = PINB;
  changed = last_reading ^ reading;
  last_reading = reading;
  
  if ((reading & step_x_mask) && (changed & step_x_mask)) {
    x_steps++;
    if (reading & dir_x_mask) {
      x_position++;
    } else {
      x_position--;
    }
  }

  if ((reading & step_y_mask) && (changed & step_y_mask)) {
    y_steps++;
    if (reading & dir_y_mask) {
      y_position++;
    } else {
      y_position--;
    }
  }
}

int32_t monitor_current_x_location() {
  return(x_position);
}

int32_t monitor_current_y_location() {
  return(y_position);
}

uint16_t monitor_read_and_reset_x_step_count() {
  uint16_t count = x_steps;
  x_steps = 0;
  return(count);
}

uint16_t monitor_read_and_reset_y_step_count() {
  uint16_t count = y_steps;
  y_steps = 0;
  return(count);
}
