#include "lcd_gfx.h"
#include "lcd_font.h"
#include "lcd.h"

uint8_t abs(int8_t a);
void swap(uint8_t* a, uint8_t* b);

void LCD_GFX_lineText(char* string, uint8_t x, uint8_t line, LCD_Buffer buffer){
	uint8_t byte;
	uint8_t cx = x;

	while(*string != '\0'){
		if(*string == '\n'){
			++line;
			cx = x;
		}
		else{
			for(byte = 0 ; byte < LCD_GFX_FONT_WIDTH ; ++byte)
				LCD_drawByte(cx++, line, ASCII[(*string)-0x20][byte], buffer);
			++cx;
		}
		++string;
	}
}

void LCD_GFX_floatText(char* string, uint8_t x, uint8_t y, LCD_Buffer buffer){
	uint8_t byte,val;
	uint8_t cx = x;
	int8_t bit;

	while(*string != '\0'){
		if(*string == '\n'){
			y += 8;
			cx = x;
		}
		else{
			for(byte = 0 ; byte < LCD_GFX_FONT_WIDTH ; ++byte){
				val = ASCII[(*string)-0x20][byte];
				for(bit = 7 ; bit >= 0 ; --bit){
					LCD_drawPixel(cx, y+bit, 0x01 & (val>>bit), buffer);
				}
				++cx;
			}
			++cx;
		}
		++string;
	}
}

// Bresenham's algorithm
void LCD_GFX_drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, LCD_Buffer buffer){
	uint8_t dx  = abs((int8_t)(x1 - x0));
	uint8_t dy  = abs((int8_t)(y1 - y0));
	int8_t  sx  = x0 < x1 ? 1 : -1;
	int8_t  sy  = y0 < y1 ? 1 : -1;
	int8_t  err = (dx > dy ? dx : -dy) / 2;
	int8_t  e2;

	while (1) {
		LCD_drawPixel(x0, y0, 1, buffer);

		if (x0 == x1 && y0 == y1)
			break;

		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy) {
			err += dx;
			y0 += sy;
		}
	}
}

uint8_t abs(int8_t a){
	return a>0? a:-a;
}

void swap(uint8_t* a, uint8_t* b){
	uint8_t c = *a;
	*a = *b;
	*b = c;
}
