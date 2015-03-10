#ifndef LCD_CONSTANTS_H_
#define LCD_CONSTANTS_H_

#define LCD_ON  0
#define LCD_OFF 3

#define LCD_ADDR_H 0
#define LCD_ADDR_V 2

#define LCD_BASIC_INST    0
#define LCD_EXTENDED_INST 1

#define LCD_DISP_BLANK 0
#define LCD_DISP_BLACK 1
#define LCD_DISP_NORM  4
#define LCD_DISP_INV   5

#define LCD_TMP_UPPER  0
#define LCD_TMP_NORMAL 1
#define LCD_TMP_IC     2
#define LCD_TMP_LOWER  3

#define LCD_CMD_FUNCSET 0x20
#define LCD_CMD_DISPCTR 0x08
#define LCD_CMD_YADDR   0x40
#define LCD_CMD_XADDR   0x80

#define LCD_CMDX_TMP    0x04
#define LCD_CMDX_BIAS   0x10
#define LCD_CMDX_VOP    0x80

// Configuration
#define LCD_INIT_BIAS 4
#define LCD_INIT_CONTRAST 0x37
#define LCD_ADDR_MODE LCD_ADDR_V

#endif
