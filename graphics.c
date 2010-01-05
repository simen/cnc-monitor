/*
  graphics.c - Minimal client library for the SparkFun SerialGraphicsLCD-v2

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

// Based on information in this data sheet
// http://www.sparkfun.com/datasheets/LCD/Monochrome/Corrected-SFE-0016-DataSheet-08884-SerialGraphicLCD-v2.pdf

#include "graphics.h"
#include "wiring_serial.h"

void clear_screen(void) {
  serialWrite(0x7c); serialWrite(0x00);
}

void pixel(char S_R, char x, char y) {
  serialWrite(0x7c); serialWrite(0x10); 
  serialWrite(x); serialWrite(y); serialWrite(S_R);
}

void line(char S_R, char x1, char y1, char x2, char y2) {
  serialWrite(0x7c); serialWrite(0x0c); 
  serialWrite(x1); serialWrite(y1); serialWrite(x2); serialWrite(y2); serialWrite(S_R);
}

void circle(char S_R, int x, int y, int r) {
  serialWrite(0x7c); serialWrite(0x03);  
  serialWrite(x); serialWrite(y); serialWrite(r); serialWrite(S_R);
}

void erase_block(char x1, char y1, char x2, char y2) {
  serialWrite(0x7c); serialWrite(0x05); 
  serialWrite(x1); serialWrite(y1); serialWrite(x2); serialWrite(y2);
}

void box(char S_R, char x1, char y1, char x2, char y2) {
  // serialWrite(0x7c); serialWrite(0x0f); 
  // serialWrite(x1); serialWrite(y1); serialWrite(x2); serialWrite(y2); serialWrite(S_R);
  line(S_R, x1, y1, x2, y1);
  line(S_R, x2, y1, x2, y2);
  line(S_R, x1, y2, x2, y2);
  line(S_R, x1, y2, x1, y1);
}

void set_text_position(char x, char y) {
  serialWrite(0x7c); serialWrite(0x18); serialWrite(x); 
  serialWrite(0x7c); serialWrite(0x19); serialWrite(y);
}

