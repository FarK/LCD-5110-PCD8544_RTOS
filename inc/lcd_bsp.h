#ifndef LCD_BSP_H_
#define LCD_BSP_H_

#include <stdint.h>

#define LCD_BSP_CE_EN  0
#define LCD_BSP_CE_DIS 1

#define LCD_BSP_DATA    1
#define LCD_BSP_COMMAND 0

#define LCD_BSP_LIGHT_EN  1
#define LCD_BSP_LIGHT_DIS 0

void LCD_BSP_init();
void LCD_BSP_RST();
void LCD_BSP_setCE(uint8_t state);
void LCD_BSP_setD_C(uint8_t state);
void LCD_BSP_setLIGHT(uint8_t state);

// Non-bloking send
void LCD_BSP_send(uint8_t* data, uint16_t size);
// It waits until a new transmission is allowed
void LCD_BSP_waitUntilTXA();
// It waits until the transmission is completed
void LCD_BSP_waitUntilTXC();

#endif
