#ifndef LCD_BUFFER_H_
#define LCD_BUFFER_H_

#include <stdint.h>

#define LCD_XRES 84
#define LCD_YRES 48
#define LCD_XBYTES 84
#define LCD_YBYTES 6
#define LCD_BUFF_SIZE (LCD_XBYTES * LCD_YBYTES)

typedef uint8_t LCD_Buffer[LCD_XBYTES][LCD_YBYTES];

#endif
