/*
  monitor.h - A module to monitor the stepper pulses, keep track of the ideal position of the simulated
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

#ifndef monitor_h
#define monitor_h

#include <avr/io.h>

void monitor_init();

int32_t current_x_location();

int32_t current_y_location();

uint16_t read_and_reset_x_step_count();

uint16_t read_and_reset_y_step_count();

#endif

