/*
  graphics.h - Minimal client library for the SparkFun SerialGraphicsLCD-v2

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

#ifndef graphics_h
#define graphics_h

void clear_screen(void);

void print_char(char S_R, char txt);
void del_char(char endpoint);
void pixel(char S_R, char x, char y);
void line(char S_R, char x1, char y1, char x2, char y2);
void circle(char S_R, int x, int y, int r);
void demo(void);

void erase_block(char x1, char y1, char x2, char y2);
void box(char S_R, char x1, char y1, char x2, char y2);

#endif
