
/*******************************************************************************************************/
/*Author	            : Mohamad Abdo Maklad	 *******************************************************/
/*Date		            : 15-11-2023			 *******************************************************/
/*Last Modification		: 15-11-2023			 *******************************************************/
/*Version	            : V01				   	 *******************************************************/
/*******************************************************************************************************/
/*Controller			: ATMEGA128				 *******************************************************/
/*SWC					: DIO					 *******************************************************/
/*******************************************************************************************************/
/****************(DIO_Program.c)************************************************************************/
/*******************************************************************************************************/

/*INTERFACE FILE ICLUDES*/
#include "DIO_Interface.h"

/*******************************************************************************************************/
/*Function Name: Dio_SetChannelDirection(Dio_ChannelType ChannelId , Dio_DirectionTypes Direction)******/
/*Function inputs:**************************************************************************************/
/*	ChannelId	<<Dio_PortType>>		DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4****/
/*	Direction	<<Dio_DirectionTypes>>	INPUT - OUTPUT**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set direction for single channel ID"*****************************/
/*******************************************************************************************************/

void Dio_SetChannelDirection(Dio_ChannelType ChannelId , Dio_DirectionTypes Direction)
{
	Dio_PortType PoId = ChannelId/8;
	Dio_PortType ChId = ChannelId%8;
	switch(PoId)
	{
		case DIOA:MOD_BIT(_DIOA_.DDR,ChId,Direction);break;
		case DIOB:MOD_BIT(_DIOB_.DDR,ChId,Direction);break;
		case DIOC:MOD_BIT(_DIOC_.DDR,ChId,Direction);break;
		case DIOD:MOD_BIT(_DIOD_.DDR,ChId,Direction);break;
		case DIOE:MOD_BIT(_DIOE_.DDR,ChId,Direction);break;
		case DIOF:MOD_BIT(_DIOF_.DDR,ChId,Direction);break;
		case DIOG:MOD_BIT(_DIOG_.DDR,ChId,Direction);break;
		case Dio_PortMax:break;
		default:break;		
	}
}

/*******************************************************************************************************/
/*Function Name: Dio_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level)**********************/
/*Function inputs:**************************************************************************************/
/*	ChannelId	<<Dio_ChannelType>>	DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4********/
/*	Level		<<Dio_LevelType>>	STD_LOW - STD_HIGH**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set level for single channel ID"*********************************/
/*******************************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level)
{
	Dio_PortType PoId = ChannelId/8;
	Dio_PortType ChId = ChannelId%8;
	switch(PoId)
	{
		case DIOA:MOD_BIT(_DIOA_.PORT,ChId,Level);break;
		case DIOB:MOD_BIT(_DIOB_.PORT,ChId,Level);break;
		case DIOC:MOD_BIT(_DIOC_.PORT,ChId,Level);break;
		case DIOD:MOD_BIT(_DIOD_.PORT,ChId,Level);break;
		case DIOE:MOD_BIT(_DIOE_.PORT,ChId,Level);break;
		case DIOF:MOD_BIT(_DIOF_.PORT,ChId,Level);break;
		case DIOG:MOD_BIT(_DIOG_.PORT,ChId,Level);break;
		case Dio_PortMax:break;
		default:break;
	}
}

/*******************************************************************************************************/
/*Function Name: Dio_ReadChannel(Dio_ChannelType ChannelId)*********************************************/
/*Function inputs:**************************************************************************************/
/*	ChannelId		<<Dio_ChannelType>>	DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4****/
/*Function return:**************************************************************************************/
/*	ChannelLevel	<<Dio_LevelType>>	STD_LOW - STD_HIGH**********************************************/
/*Function Description: "This function get level for single channel ID"*********************************/
/*******************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType LocalPinVal = STD_LOW;
	Dio_PortType PoId = ChannelId/8;
	Dio_PortType ChId = ChannelId%8;
	switch(PoId)
	{
		case DIOA:LocalPinVal =  GET_BIT(_DIOA_.PIN,ChId);break;
		case DIOB:LocalPinVal =  GET_BIT(_DIOB_.PIN,ChId);break;
		case DIOC:LocalPinVal =  GET_BIT(_DIOC_.PIN,ChId);break;
		case DIOD:LocalPinVal =  GET_BIT(_DIOD_.PIN,ChId);break;
		case DIOE:LocalPinVal =  GET_BIT(_DIOE_.PIN,ChId);break;
		case DIOF:LocalPinVal =  GET_BIT(_DIOF_.PIN,ChId);break;
		case DIOG:LocalPinVal =  GET_BIT(_DIOG_.PIN,ChId);break;
		case Dio_PortMax:break;
		default:break;
	}
	return LocalPinVal;
}


/*******************************************************************************************************/
/*Function Name: Dio_FlipChannel(Dio_ChannelType ChannelId)*********************************************/
/*Function inputs:**************************************************************************************/
/*	ChannelId	<<Dio_ChannelType>> DIOpc -- p(A,B,C,D,E,F,G) -- c(0...7) # Exp. Max PortG DIOG4********/
/*Function return: No return****************************************************************************/
/*Function Description: "This function toggle or flip level for single channel ID"**********************/
/*******************************************************************************************************/
void Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_PortType PoId = ChannelId/8;
	Dio_PortType ChId = ChannelId%8;
	switch(PoId)
	{
		case DIOA:TOGGLE_BIT(_DIOA_.PORT,ChId);break;
		case DIOB:TOGGLE_BIT(_DIOB_.PORT,ChId);break;
		case DIOC:TOGGLE_BIT(_DIOC_.PORT,ChId);break;
		case DIOD:TOGGLE_BIT(_DIOD_.PORT,ChId);break;
		case DIOE:TOGGLE_BIT(_DIOE_.PORT,ChId);break;
		case DIOF:TOGGLE_BIT(_DIOF_.PORT,ChId);break;
		case DIOG:TOGGLE_BIT(_DIOG_.PORT,ChId);break;
		case Dio_PortMax:break;
		default:break;
	}
}


/*******************************************************************************************************/
/*Function Name: Dio_SetPortDirection(Dio_PortType PortId , Dio_DirectionTypes Direction)***************/
/*Function inputs:**************************************************************************************/
/*	PortId		<<Dio_PortType>>		DIOp -- p(A,B,C,D,E,F,G)****************************************/
/*	Direction	<<Dio_DirectionTypes>>	INPUT - OUTPUT**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set direction for single Port ID"********************************/
/*******************************************************************************************************/	
void Dio_SetPortDirection(Dio_PortType PortId , Dio_DirectionTypes Direction)
{
	u8 DirectionVal = 0;
	switch(Direction)
	{
		case INPUT: DirectionVal = 0	;break;
		case OUTPUT:DirectionVal = 255	;break;
		default:DirectionVal = 0		;break;
	}
	switch(PortId)
	{
		case DIOA:_DIOA_.DDR = DirectionVal;break;
		case DIOB:_DIOB_.DDR = DirectionVal;break;
		case DIOC:_DIOC_.DDR = DirectionVal;break;
		case DIOD:_DIOD_.DDR = DirectionVal;break;
		case DIOE:_DIOE_.DDR = DirectionVal;break;
		case DIOF:_DIOF_.DDR = DirectionVal;break;
		case DIOG:_DIOG_.DDR = DirectionVal;break;
		case Dio_PortMax:break;
		default:break;
	}
	
}

/*******************************************************************************************************/
/*Function Name: Dio_WritePort(Dio_PortType PortId , Dio_LevelType Level)*******************************/
/*Function inputs:**************************************************************************************/
/*	PortId		<<Dio_PortType>>	DIOp -- p(A,B,C,D,E,F,G)********************************************/
/*	Direction	<<Dio_LevelType>>	STD_LOW - STD_HIGH**************************************************/
/*Function return: No return****************************************************************************/
/*Function Description: "This function set level for single Port ID"************************************/
/*******************************************************************************************************/
void Dio_WritePort(Dio_PortType PortId , Dio_LevelType Level)
{
	u8 LevelVal = 0;
	switch(Level)
	{
		case STD_LOW: LevelVal = 0		;break;
		case STD_HIGH:LevelVal = 255	;break;
		default:LevelVal = 0			;break;
	}
	switch(PortId)
	{
		case DIOA:_DIOA_.PORT = LevelVal;break;
		case DIOB:_DIOB_.PORT = LevelVal;break;
		case DIOC:_DIOC_.PORT = LevelVal;break;
		case DIOD:_DIOD_.PORT = LevelVal;break;
		case DIOE:_DIOE_.PORT = LevelVal;break;
		case DIOF:_DIOF_.PORT = LevelVal;break;
		case DIOG:_DIOG_.PORT = LevelVal;break;
		case Dio_PortMax:break;
		default:break;
	}
}