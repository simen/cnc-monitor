#include <avr/io.h>
#include <util/delay.h>
#include "gui.h"
#include "graphics.h"
#include "wiring_serial.h"

#define TEXT_LINES 2
#define BOTTOM_GRAPHICS_AREA_Y (TEXT_LINES*8+2)

char divider;
int32_t center_x;
int32_t center_y;


void rewrite_line(char line) {
  char y = (TEXT_LINES-line)*8;
  erase_block(0,y+1,MAX_X,y+8);
  set_text_position(0,y+8);
}

void clear_text_area() {
  rewrite_line(2);
  rewrite_line(1);
}

void gui_clear() {
  clear_screen();
  line(1, 0, BOTTOM_GRAPHICS_AREA_Y, MAX_X, BOTTOM_GRAPHICS_AREA_Y);
}

void gui_init() {
  divider = 1;
  gui_clear();
}

void gui_set_scale(char _divider) {
  divider = _divider;
  gui_clear();
}

void gui_set_tool_point(int32_t x, int32_t y) {
  int16_t screen_x = ((x-center_x)>>divider)+(MAX_X/2);
  int16_t screen_y = ((y-center_y)>>divider)+(MAX_Y/2);
  if ((screen_x < 0) || (screen_x > MAX_X) || (screen_y < BOTTOM_GRAPHICS_AREA_Y) || (screen_y > MAX_Y)) {
    center_x = x;
    center_y = y;
    gui_clear();
    screen_x = 0;
    screen_y = 0;
  }  
  pixel(1, screen_x, screen_y);
}
