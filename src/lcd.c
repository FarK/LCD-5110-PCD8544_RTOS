#include "lcd.h"
#include "lcd_bsp.h"

//Auxiliary functions
void static setD_C(uint8_t state);
void static send(uint8_t* data, uint16_t size); // Blocking send
void static sendCommand(uint8_t command);       // Blocking send
void static setInstructionMode(uint8_t mode);


void LCD_init(){
	LCD_BSP_init();

	LCD_BSP_setCE(LCD_BSP_CE_DIS);
	LCD_BSP_RST();
	LCD_BSP_setCE(LCD_BSP_CE_EN);	// Enable SPI

	// Power on, addressing mode and extended instruction set
	sendCommand(LCD_CMD_FUNCSET | LCD_ADDR_MODE | LCD_EXTENDED_INST);
	sendCommand(LCD_CMDX_VOP | LCD_INIT_CONTRAST);  // Initial contrast
	sendCommand(LCD_CMDX_BIAS | LCD_INIT_BIAS);     // Bias
	sendCommand(LCD_CMDX_TMP | LCD_TMP_NORMAL);	    // Temperature coefficient

	// Normal mode
	sendCommand(LCD_CMD_FUNCSET | LCD_ADDR_MODE | LCD_BASIC_INST);
	// Normal display configuration
	sendCommand(LCD_CMD_DISPCTR | LCD_DISP_NORM);
}

/***********************
 * AUXILIARY FUNCTIONS *
 ***********************/

void setD_C(uint8_t state){
	LCD_BSP_waitUntilTXC();
	LCD_BSP_setD_C(state);
}

void send(uint8_t* data, uint16_t size){
	LCD_BSP_waitUntilTXA();
	LCD_BSP_send(data, size);
}

void sendCommand(uint8_t command){
	setD_C(LCD_BSP_COMMAND);
	send(&command, 1);
}

/*********************
 * DISPLAY FUNCTIONS *
 *********************/
void LCD_drawPixel(uint8_t x, uint8_t y, uint8_t val, LCD_Buffer buffer){
	uint8_t byte = y/8;
	uint8_t bit = y%8;
	uint8_t mask = 1 << bit;

	/* Set bit. Like:
		if(val == 1) buffer[byte][x] |= mask;
		else         buffer[byte][x] &= ~mask;
	*/
	buffer[x][byte] ^= (-val ^ buffer[x][byte]) & mask;
}

void LCD_drawByte(uint8_t x, uint8_t byteY, uint8_t val, LCD_Buffer buffer){
	buffer[x][byteY] = val;
}

void LCD_sendBuffer(LCD_Buffer buffer){
	LCD_setCursor(0,0);
	setD_C(LCD_BSP_DATA);
	send(&buffer[0][0], LCD_BUFF_SIZE);
}

// TODO: Optimize?
void LCD_clear(){
	int i,j;
	static uint8_t zero = 0;

	for(i = 0 ; i < LCD_XBYTES ; ++i)
		for(j = 0 ; j < LCD_YBYTES ; ++j)
			send(&zero, 1);
}

/*********************
 * COMMAND FUNCTIONS *
 *********************/

void setInstructionMode(uint8_t mode){
	sendCommand(LCD_CMD_FUNCSET | LCD_ADDR_MODE | mode);
}

void LCD_setDisplayMode(uint8_t mode){
	sendCommand(LCD_CMD_DISPCTR | mode);
}

void LCD_setCursor(uint8_t x, uint8_t y){
	/*
	sendCommand(LCD_CMD_XADDR | x);
	sendCommand(LCD_CMD_YADDR | y);
	*/
	//Optimized:
	static uint8_t cmd_x = LCD_CMD_XADDR;
	static uint8_t cmd_y = LCD_CMD_YADDR;

	setD_C(LCD_BSP_COMMAND);
	cmd_x |= x;
	cmd_y |= y;
	send(&cmd_x, 1);
	send(&cmd_y, 1);
}

void LCD_setTempCtrl(uint8_t mode){
	setInstructionMode(LCD_EXTENDED_INST);
	sendCommand(LCD_CMDX_TMP | mode);
	setInstructionMode(LCD_BASIC_INST);
}

void LCD_setContrast(uint8_t contrast){
	setInstructionMode(LCD_EXTENDED_INST);
	sendCommand(LCD_CMDX_VOP | contrast);
	setInstructionMode(LCD_BASIC_INST);
}

void LCD_setBias(uint8_t bias){
	setInstructionMode(LCD_EXTENDED_INST);
	sendCommand(LCD_CMDX_BIAS | bias);
	setInstructionMode(LCD_BASIC_INST);
}

