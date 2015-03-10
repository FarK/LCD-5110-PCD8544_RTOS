LCD-5110-PCD8544_RTOS
======================

This library is a generic driver for the Nokia 5110 LCD (PCD8544 controller)
with RTOS support.

You only need provide 6 hardware-specific functions to control signals and to
transmit data. Besides you must implement two wait functions, where you can
include RTOS task switching.

BSP Functions
-------------

```c
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
```

References
----------
I have relied on others libraries which you can find in these repositories:

* [https://github.com/andygock/glcd](https://github.com/andygock/glcd "GLCD")
* [https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library "Adafruit")
* [https://github.com/adafruit/Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library "Adafruit GFX")
