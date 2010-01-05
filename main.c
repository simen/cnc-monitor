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
#include <util/delay.h>
#include "wiring_serial.h"
#include "graphics.h"
#include "monitor.h"
#include "gui.h"

// PB0 is step X, PB4 is direction X
// PB1 is step Y, PB5 is direction X
// The SparkFun 160x120 Huge LCD with serial backpack is connected to serial TX

int main(void)
{
  beginSerial(115200);  

  _delay_ms(1000);
  gui_init();
  gui_set_scale(7); // 128 steps/pixel
  gui_set_tool_point(0,0);
  
  monitor_init();
  sei();
  
  for(;;){
    sleep_mode();
    gui_set_tool_point(monitor_current_x_location(),monitor_current_y_location());
  }
  return 0;   /* never reached */
}
