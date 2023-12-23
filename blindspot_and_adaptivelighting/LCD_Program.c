/************************************************************************************************************/
/*Author	            : Mohamad Abdo Maklad	 ************************************************************/
/*Date		            : 16-11-2023			 ************************************************************/
/*Last Modification		: 16-11-2023			 ************************************************************/
/*Version	            : V01				   	 ************************************************************/
/************************************************************************************************************/
/*Controller			: ATMEGA128				 ************************************************************/
/*SWC					: LCD					 ************************************************************/
/************************************************************************************************************/
/****************(LCD_Program.c)*****************************************************************************/
/************************************************************************************************************/

/*STD IO - String LIB ICLUDES*/
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STD LIB ICLUDES*/
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
/*Required MCAL FILEs ICLUDES*/
#include "DIO_Interface.h"
/*SWC INTERFACE FILE ICLUDES*/
#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"


/*Array Of Data DIO Channels According to Configuration {LCD_Cfg.h}*/
static Dio_ChannelType LCD_DataPinsArr[4]={Data0,Data1,Data2,Data3};
	
/*******************************************************************************************************/
/*Function Name: LCD_Init()*****************************************************************************/
/*Function inputs: No Inputs****************************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Init The Lcd HWC including DIO Channels Acoording To {LCD_Cfg.h}"*/
/*******************************************************************************************************/

void LCD_Init(void)
{
	Dio_SetChannelDirection(Data0,OUTPUT);
	Dio_SetChannelDirection(Data1,OUTPUT);
	Dio_SetChannelDirection(Data2,OUTPUT);
	Dio_SetChannelDirection(Data3,OUTPUT);
	
	Dio_SetChannelDirection(LCD_RS,OUTPUT);
	Dio_SetChannelDirection(LCD_E,OUTPUT);
	#if RWChannel == ENABLE_Macro
		Dio_SetChannelDirection(LCD_RW,OUTPUT);
	#endif
	Dio_WriteChannel(LCD_E,STD_HIGH);
	
	_delay_ms(20);
	LCD_Cmd(0x02);
	LCD_Cmd(0x28);
	LCD_Cmd(0x0C);		//Set Function 4Bit - 2Line - 5*8
	LCD_Cmd(0x06);		//Entry Mode Move Right
	LCD_Cmd(0x01);		//Display ON & courser OFF & No Blinking
	_delay_ms(2);
}

/*******************************************************************************************************/
/*Function Name: LCD_Enable()***************************************************************************/
/*Function inputs: No Inputs****************************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "Static Function To Make Enable Pulse"******************************************/
/*******************************************************************************************************/

void LCD_Enable(void)
{
	Dio_WriteChannel(LCD_E,STD_LOW);
	_delay_us(1);
	Dio_WriteChannel(LCD_E,STD_HIGH);
}

/*******************************************************************************************************/
/*Function Name: LCD_Cmd(u8 Cmd)************************************************************************/
/*Function inputs:**************************************************************************************/
/*	Cmd		{{LCD DataSheet DOC}}***********************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function Send Command to LCD"*********************************************/
/*******************************************************************************************************/

void LCD_Cmd(u8 Cmd)
{
	Dio_WriteChannel(LCD_RS,STD_LOW);
	/*for (u8 i = 0 ;i<4 ; i++)
	{
		Dio_WriteChannel(LCD_DataPinsArr[i],GET_BIT(Cmd,i));
	}*/
	Dio_WriteChannel(LCD_DataPinsArr[0],GET_BIT(Cmd,4));
	Dio_WriteChannel(LCD_DataPinsArr[1],GET_BIT(Cmd,5));
	Dio_WriteChannel(LCD_DataPinsArr[2],GET_BIT(Cmd,6));
	Dio_WriteChannel(LCD_DataPinsArr[3],GET_BIT(Cmd,7));
	
	LCD_Enable();
	_delay_us(200);
	/*for (u8 i = 0 ;i<4 ; i++)
	{
		Dio_WriteChannel(LCD_DataPinsArr[i],GET_BIT(Cmd,(i+4)));
	}*/
	Dio_WriteChannel(LCD_DataPinsArr[0],GET_BIT(Cmd,0));
	Dio_WriteChannel(LCD_DataPinsArr[1],GET_BIT(Cmd,1));
	Dio_WriteChannel(LCD_DataPinsArr[2],GET_BIT(Cmd,2));
	Dio_WriteChannel(LCD_DataPinsArr[3],GET_BIT(Cmd,3));
	LCD_Enable();
	_delay_ms(2);
}

/*******************************************************************************************************/
/*Function Name: LCD_Char(s8 Data)**********************************************************************/
/*Function inputs:**************************************************************************************/
/*	Data		<<s8>> any char can be input************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function Send Character to LCD"*******************************************/
/*******************************************************************************************************/

void LCD_Char(s8 Data)
{
	Dio_WriteChannel(LCD_RS,STD_HIGH);
	/*for (u8 i = 0 ;i<4 ; i++)
	{
		Dio_WriteChannel(LCD_DataPinsArr[i],GET_BIT(Cmd,i));
	}*/
	Dio_WriteChannel(LCD_DataPinsArr[0],GET_BIT(Data,4));
	Dio_WriteChannel(LCD_DataPinsArr[1],GET_BIT(Data,5));
	Dio_WriteChannel(LCD_DataPinsArr[2],GET_BIT(Data,6));
	Dio_WriteChannel(LCD_DataPinsArr[3],GET_BIT(Data,7));
	
	LCD_Enable();
	_delay_us(200);
	/*for (u8 i = 0 ;i<4 ; i++)
	{
		Dio_WriteChannel(LCD_DataPinsArr[i],GET_BIT(Cmd,(i+4)));
	}*/
	Dio_WriteChannel(LCD_DataPinsArr[0],GET_BIT(Data,0));
	Dio_WriteChannel(LCD_DataPinsArr[1],GET_BIT(Data,1));
	Dio_WriteChannel(LCD_DataPinsArr[2],GET_BIT(Data,2));
	Dio_WriteChannel(LCD_DataPinsArr[3],GET_BIT(Data,3));
	LCD_Enable();
	_delay_ms(2);
}

/*******************************************************************************************************/
/*Function Name: LCD_String(s8 * String)****************************************************************/
/*Function inputs:**************************************************************************************/
/*	String		<<s8 array>> array of s8 <<STD_t>>******************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function Display Array String terminated with '/0' "**********************/
/*******************************************************************************************************/

void LCD_String(s8 * String)
{
	u8 i;
	for (i=0;String[i] != '\0';i++)
	LCD_Char(String[i]);
}

/*******************************************************************************************************/
/*Function Name: LCD_SetPosition(u8 LineNo, u8 Position)************************************************/
/*Function inputs:**************************************************************************************/
/*	LineNo		<<STD_t>>	1 ... 4  <<u8>>*************************************************************/
/*	Position	<<STD_t>>	0 ... 19 <<u8>>*************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set cursor Position Through LCD "********************************/
/*******************************************************************************************************/

void LCD_SetPosition(u8 LineNo, u8 Position)
{
	switch (Position)
	{
		case 0 ... 19 :
		{
			switch(LineNo)
			{
				case 1: LCD_Cmd((0x80 | (Position & 0xFF)));break;
				case 2: LCD_Cmd((0xC0 | (Position & 0xFF)));break;
				case 3: LCD_Cmd((0x94 | (Position & 0xFF)));break;
				case 4: LCD_Cmd((0xD4 | (Position & 0xFF)));break;
			}
		}break;
	}
	
}

/*******************************************************************************************************/
/*Function Name: LCD_NUM(u32 IntVal)********************************************************************/
/*Function inputs:**************************************************************************************/
/*	String		<<STD_t>> unsigned Int VAl in range <<u32>>*********************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function Display Int Value "**********************************************/
/*******************************************************************************************************/

void LCD_NUM(u32 IntVal)
{
	s8 StrArr[12]; // Assuming a 32-bit integer can be up to 10 digits, plus one for the null terminator.
	sprintf((char *)StrArr, "%lu",(u32)IntVal);
	LCD_String((s8*)StrArr);
}

/*******************************************************************************************************/
/*Function Name: LCD_Clear()****************************************************************************/
/*Function inputs: No Inputs****************************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function Clear LCD "******************************************************/
/*******************************************************************************************************/

void LCD_Clear(void)
{
	LCD_Cmd(CLEAR_CMD);
}
