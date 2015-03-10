#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>
#include "lcd_buffer.h"
#include "lcd_constants.h"

void LCD_init();

void LCD_drawPixel(uint8_t x, uint8_t y, uint8_t val, LCD_Buffer buffer);
void LCD_drawByte(uint8_t x, uint8_t y, uint8_t val, LCD_Buffer buffer);
void LCD_sendBuffer(LCD_Buffer buffer);
void LCD_clear();

void LCD_setCursor(uint8_t x, uint8_t y);
void LCD_setDisplayMode(uint8_t powerMode);

void LCD_setTempCtrl(uint8_t mode);
void LCD_setContrast(uint8_t contrast);
void LCD_setBias(uint8_t bias);

#endif

