#ifndef LCD_GFX_
#define LCD_GFX_

#include "lcd_buffer.h"
#include <stdint.h>

void LCD_GFX_lineText(char* string, uint8_t x, uint8_t line, LCD_Buffer buffer);
void LCD_GFX_floatText(char* string, uint8_t x, uint8_t y, LCD_Buffer buffer);

void LCD_GFX_drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, LCD_Buffer buffer);

#endif
