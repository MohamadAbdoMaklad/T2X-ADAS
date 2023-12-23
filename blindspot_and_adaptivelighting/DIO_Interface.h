/************************************************************************************************************/
/*Author	            : Mohamad Abdo Maklad	 ************************************************************/
/*Date		            : 15-11-2023			 ************************************************************/
/*Last Modification		: 15-11-2023			 ************************************************************/
/*Version	            : V01				   	 ************************************************************/
/************************************************************************************************************/
/*Controller			: ATMEGA128				 ************************************************************/
/*SWC					: DIO					 ************************************************************/
/************************************************************************************************************/
/****************(DIO_Interface.h)***************************************************************************/
/************************************************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*STANNDARAD LIB INCLUDE*/
#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"
/*PRIVATE FILES INCLUDE*/
#include "DIO_Private.h"

/*************************************/
/*ChannelID Type <<Dio_ChannelType>>**/
/*************************************/

typedef enum{
DIOA0 = 0,DIOA1,DIOA2,DIOA3,DIOA4,DIOA5,DIOA6,DIOA7,
	DIOB0,DIOB1,DIOB2,DIOB3,DIOB4,DIOB5,DIOB6,DIOB7,
	DIOC0,DIOC1,DIOC2,DIOC3,DIOC4,DIOC5,DIOC6,DIOC7,
	DIOD0,DIOD1,DIOD2,DIOD3,DIOD4,DIOD5,DIOD6,DIOD7,
	DIOE0,DIOE1,DIOE2,DIOE3,DIOE4,DIOE5,DIOE6,DIOE7,
	DIOF0,DIOF1,DIOF2,DIOF3,DIOF4,DIOF5,DIOF6,DIOF7,
	DIOG0,DIOG1,DIOG2,DIOG3,DIOG4,
Dio_PinMax,
}Dio_ChannelType;

/*************************************/
/*PortID Type <<Dio_PortType>>********/
/*************************************/

typedef enum{
	DIOA = 0,DIOB,DIOC,
	DIOD,DIOE,DIOF,DIOG,
	Dio_PortMax,
}Dio_PortType;

/***************************************************************/
/*PortID/ChannelID Direction Type <<Dio_DirectionTypes>>********/
/***************************************************************/

typedef enum{
	INPUT = 0,
	OUTPUT = 1,
}Dio_DirectionTypes;

/***************************************************************/
/*PortID/ChannelID Level Type <<Dio_LevelType>>*****************/
/***************************************************************/

typedef enum{
	STD_LOW = 0,
	STD_HIGH = 1,
}Dio_LevelType;


/*******************************************************************************************************/
/*Function Name: Dio_SetChannelDirection(Dio_ChannelType ChannelId , Dio_DirectionTypes Direction)******/
/*Function inputs:**************************************************************************************/
/*	ChannelId	<<Dio_PortType>>		DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4****/
/*	Direction	<<Dio_DirectionTypes>>	INPUT - OUTPUT**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set direction for single channel ID"*****************************/
/*******************************************************************************************************/		

void Dio_SetChannelDirection(Dio_ChannelType ChannelId , Dio_DirectionTypes Direction);

/*******************************************************************************************************/
/*Function Name: Dio_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level)**********************/
/*Function inputs:**************************************************************************************/
/*	ChannelId	<<Dio_ChannelType>>	DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4********/
/*	Level		<<Dio_LevelType>>	STD_LOW - STD_HIGH**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set level for single channel ID"*********************************/
/*******************************************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level);

/*******************************************************************************************************/
/*Function Name: Dio_ReadChannel(Dio_ChannelType ChannelId)*********************************************/
/*Function inputs:**************************************************************************************/
/*	ChannelId		<<Dio_ChannelType>>	DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4****/
/*Function return:**************************************************************************************/
/*	ChannelLevel	<<Dio_LevelType>>	STD_LOW - STD_HIGH**********************************************/
/*Function Description: "This function get level for single channel ID"*********************************/
/*******************************************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*******************************************************************************************************/
/*Function Name: Dio_FlipChannel(Dio_ChannelType ChannelId)*********************************************/
/*Function inputs:**************************************************************************************/
/*	ChannelId	<<Dio_ChannelType>> DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4********/
/*Function return: No return****************************************************************************/
/*Function Description: "This function toggle or flip level for single channel ID"**********************/
/*******************************************************************************************************/

void Dio_FlipChannel(Dio_ChannelType ChannelId);

/*******************************************************************************************************/
/*Function Name: Dio_SetPortDirection(Dio_PortType PortId , Dio_DirectionTypes Direction)***************/
/*Function inputs:**************************************************************************************/
/*	PortId		<<Dio_PortType>>		DIOp -- p(A,B,C,D,E,F,G)****************************************/
/*	Direction	<<Dio_DirectionTypes>>	INPUT - OUTPUT**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set direction for single Port ID"********************************/
/*******************************************************************************************************/

void Dio_SetPortDirection(Dio_PortType PortId , Dio_DirectionTypes Direction);

/*******************************************************************************************************/
/*Function Name: Dio_WritePort(Dio_PortType PortId , Dio_LevelType Level)*******************************/
/*Function inputs:**************************************************************************************/
/*	PortId		<<Dio_PortType>>	DIOp -- p(A,B,C,D,E,F,G)********************************************/
/*	Direction	<<Dio_LevelType>>	STD_LOW - STD_HIGH**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set level for single Port ID"************************************/
/*******************************************************************************************************/

void Dio_WritePort(Dio_PortType PortId , Dio_LevelType Level);

#endif /* DIO_INTERFACE_H_ */