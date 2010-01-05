/*
  main.c - A monitor to visualize and measure the performance of two dimensions of a cartesian 
           CNC stepper controller
           
  Part of Grbl

  Copyright (c) 2009 Simen Svale Skogsrud

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
#include <avr/sleep.h>
#include "wiring_serial.h"
#include "graphics.h"
#include "monitor.h"

// PB0 is step X, PB3 is direction X
// PB1 is step Y, PB4 is direction X
// The SparkFun 160x120 Huge LCD with serial backpack is connected to serial TX

int main(void)
{
  beginSerial(115200);  

  clear_screen();
  circle(1, 80, 60, 20);
  
  monitor_init();
  sei();
  
  for(;;){
    sleep_mode();
  }
  return 0;   /* never reached */
}
