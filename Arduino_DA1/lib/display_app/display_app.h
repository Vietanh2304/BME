#ifndef DISPLAY_APP_H
#define DISPLAY_APP_H

#include "LiquidCrystal_I2C.h"

extern LiquidCrystal_I2C lcd;

void display_clear_rect(int x1, int y1, int x2, int y2);
void display_num(int x, int y, int num);
void display_text(int x, int y, String text);
void display_init();
void display_clear();


#endif
