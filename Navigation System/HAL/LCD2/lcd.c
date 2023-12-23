 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * 
 *
 *******************************************************************************/

#include "lcd.h"
#include"LCD_cfg.h"
#include"LCD_private.h"
#include<util/delay.h>
#include<stdlib.h>
#include"../../MCAL/Dio/Dio.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void LCD_init(void)
{
	Dio_SetChannel_Dir(PA_3, OUTPUT);//RS
	Dio_SetChannel_Dir(PA_2, OUTPUT);//EN
	#if DATA_BITS_MODE == FOUR_BIT_MODE
	    #if PORT_PINS_MODE == LOWER_PORT_PINS
			Dio_SetChannel_Dir(PB_0, OUTPUT);
			Dio_SetChannel_Dir(PB_1, OUTPUT);
			Dio_SetChannel_Dir(PB_2, OUTPUT);
			Dio_SetChannel_Dir(PB_4, OUTPUT);


		#elif PORT_PINS_MODE == UPPER_PORT_PINS
	        /*  */


		#endif
			LCD_sendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
			LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	#elif DATA_BITS_MODE == EIGHT_BIT_MODE
	/*       */
	#endif

	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_sendCommand(uint8_t command)
{
	Dio_WriteChannel(PA_3, STD_LOW); /* Instruction Mode RS=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	Dio_WriteChannel(PA_2, STD_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
#if (DATA_BITS_MODE == FOUR_BIT_MODE)
	/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
  #if PORT_PINS_MODE == LOWER_PORT_PINS
	      Dio_WriteChannel(PB_0, GET_BIT(command,4));
	      Dio_WriteChannel(PB_1, GET_BIT(command,5));
	      Dio_WriteChannel(PB_2, GET_BIT(command,6));
	      Dio_WriteChannel(PB_4, GET_BIT(command,7));
  #elif PORT_PINS_MODE == UPPER_PORT_PINS

  #endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	Dio_WriteChannel(PA_2, STD_LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	Dio_WriteChannel(PA_2, STD_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
  #if PORT_PINS_MODE == LOWER_PORT_PINS
		Dio_WriteChannel(PB_0, GET_BIT(command,0));
		Dio_WriteChannel(PB_1, GET_BIT(command,1));
		Dio_WriteChannel(PB_2, GET_BIT(command,2));
		Dio_WriteChannel(PB_4, GET_BIT(command,3));

  #elif PORT_PINS_MODE == UPPER_PORT_PINS
  #endif
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	Dio_WriteChannel(PA_2, STD_LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#elif (DATA_BITS_MODE == 8)
	LCD_DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

void LCD_displayCharacter(uint8_t data)
{
	Dio_WriteChannel(PA_3, STD_HIGH); /* data Mode RS=1 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	Dio_WriteChannel(PA_2, STD_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
#if (DATA_BITS_MODE == FOUR_BIT_MODE)
	/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
  #if PORT_PINS_MODE == LOWER_PORT_PINS
	      Dio_WriteChannel(PB_0, GET_BIT(data,4));
	      Dio_WriteChannel(PB_1, GET_BIT(data,5));
	      Dio_WriteChannel(PB_2, GET_BIT(data,6));
	      Dio_WriteChannel(PB_4, GET_BIT(data,7));
  #elif PORT_PINS_MODE == UPPER_PORT_PINS

  #endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	Dio_WriteChannel(PA_2, STD_LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	Dio_WriteChannel(PA_2, STD_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
  #if PORT_PINS_MODE == LOWER_PORT_PINS
		Dio_WriteChannel(PB_0, GET_BIT(data,0));
		Dio_WriteChannel(PB_1, GET_BIT(data,1));
		Dio_WriteChannel(PB_2, GET_BIT(data,2));
		Dio_WriteChannel(PB_4, GET_BIT(data,3));

  #elif PORT_PINS_MODE == UPPER_PORT_PINS
  #endif
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	Dio_WriteChannel(PA_2, STD_LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#elif (DATA_BITS_MODE == 8)
	LCD_DATA_PORT = data; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

void LCD_displayString(const char *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	*********************************************************/
}

void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
	uint8_t Address;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x14;
				break;
		case 3:
				Address=col+0x54;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION); 
}

void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}
