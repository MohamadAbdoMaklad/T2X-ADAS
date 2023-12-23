/************************************************************************************************************/
/*Author	            : Mohamad Abdo Maklad	 ************************************************************/
/*Date		            : 16-11-2023			 ************************************************************/
/*Last Modification		: 16-11-2023			 ************************************************************/
/*Version	            : V01				   	 ************************************************************/
/************************************************************************************************************/
/*Controller			: ATMEGA128				 ************************************************************/
/*SWC					: L298N					 ************************************************************/
/************************************************************************************************************/
/****************(L298N_Program.c)***************************************************************************/
/************************************************************************************************************/

/*STD IO - String LIB ICLUDES*/
#define F_CPU 16000000UL
#include <util/delay.h>
/*STD LIB ICLUDES*/
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
/*Required MCAL FILEs ICLUDES*/
#include "DIO_Interface.h"
#include "TMR0_Interface.h"
/*SWC INTERFACE FILE ICLUDES*/
#include "L298N_Cfg.h"
#include "L298N_Interface.h"

#if CHANNEL1STATE == ENABLE_Macro

/*******************************************************************************************************/
/*Function Name: DCM_CH1_voidInit()*********************************************************************/
/*Function inputs: No Inputs****************************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Init The L298N DC Motor Driver Channel 1"*************************/
/*******************************************************************************************************/

	void DCM_CH1_voidInit(void)
	{
		Dio_SetChannelDirection(DIRECTION1PIN_CH1,OUTPUT);
		Dio_SetChannelDirection(DIRECTION2PIN_CH1,OUTPUT);
		Dio_SetChannelDirection(ENABLE1PIN_PWMCH1,OUTPUT);
		TMR0_voidInit();
	}

/*******************************************************************************************************/
/*Function Name: DCM_CH1_voidSetMotorState(MotorState_t Copy_State)*************************************/
/*Function inputs: *************************************************************************************/
/*	Copy_State	<<MotorState_t>> MotorOFF - MotorCW - MotorCCW *****************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Set State Or Direction For L298N DC Motor Driver Channel 1"*******/
/*******************************************************************************************************/

	void DCM_CH1_voidSetMotorState(MotorState_t Copy_State)
	{
		switch(Copy_State)
		{
			case MotorOFF	:
			Dio_WriteChannel(DIRECTION1PIN_CH1,STD_LOW);
			Dio_WriteChannel(DIRECTION2PIN_CH1,STD_LOW);
			TMR0_voidStop();
			break;
			case MotorCW	:
			Dio_WriteChannel(DIRECTION1PIN_CH1,STD_HIGH);
			Dio_WriteChannel(DIRECTION2PIN_CH1,STD_LOW);
			break;
			case MotorCCW	:
			Dio_WriteChannel(DIRECTION1PIN_CH1,STD_LOW);
			Dio_WriteChannel(DIRECTION2PIN_CH1,STD_HIGH);
			break;
			default:
			Dio_WriteChannel(DIRECTION1PIN_CH1,STD_HIGH);
			Dio_WriteChannel(DIRECTION2PIN_CH1,STD_HIGH);
			TMR0_voidStop();
			break;
		}
	}
	
/*******************************************************************************************************/
/*Function Name: DCM_CH1_voidSetMotorSpeed(u8 copy_u8Speed)*********************************************/
/*Function inputs: *************************************************************************************/
/*	Copy_State	<<STD_t>> 0 ... 100 <<u8>>**************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Set Speed For L298N DC Motor Driver Channel 1"********************/
/*******************************************************************************************************/
	
	void DCM_CH1_voidSetMotorSpeed(u8 copy_u8Speed)
	{
		TMR0_voidSetDutycycle(copy_u8Speed);
		TMR0_voidStart();
	}
		
#endif



#if CHANNEL2STATE == ENABLE_Macro

/*******************************************************************************************************/
/*Function Name: DCM_CH2_voidInit()*********************************************************************/
/*Function inputs: No Inputs****************************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Init The L298N DC Motor Driver Channel 2"*************************/
/*******************************************************************************************************/

	void DCM_CH2_voidInit(void)
	{
		Dio_SetChannelDirection(DIRECTION1PIN_CH2,OUTPUT);
		Dio_SetChannelDirection(DIRECTION2PIN_CH2,OUTPUT);
		Dio_SetChannelDirection(ENABLE1PIN_PWMCH2,OUTPUT);
		TMR0_voidInit();
	}

/*******************************************************************************************************/
/*Function Name: DCM_CH2_voidSetMotorState(MotorState_t Copy_State)*************************************/
/*Function inputs: *************************************************************************************/
/*	Copy_State	<<MotorState_t>> MotorOFF - MotorCW - MotorCCW *****************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Set State Or Direction For L298N DC Motor Driver Channel 2"*******/
/*******************************************************************************************************/

	void DCM_CH2_voidSetMotorState(MotorState_t Copy_State)
	{
		switch(Copy_State)
		{
			case MotorOFF	:
			Dio_WriteChannel(DIRECTION1PIN_CH2,STD_LOW);
			Dio_WriteChannel(DIRECTION2PIN_CH2,STD_LOW);
			TMR0_voidStop();
			break;
			case MotorCW	:
			Dio_WriteChannel(DIRECTION1PIN_CH2,STD_HIGH);
			Dio_WriteChannel(DIRECTION2PIN_CH2,STD_LOW);
			break;
			case MotorCCW	:
			Dio_WriteChannel(DIRECTION1PIN_CH2,STD_LOW);
			Dio_WriteChannel(DIRECTION2PIN_CH2,STD_HIGH);
			break;
			default:
			Dio_WriteChannel(DIRECTION1PIN_CH2,STD_HIGH);
			Dio_WriteChannel(DIRECTION2PIN_CH2,STD_HIGH);
			TMR0_voidStop();
			break;
		}
	}
	
/*******************************************************************************************************/
/*Function Name: DCM_CH2_voidSetMotorSpeed(u8 copy_u8Speed)*********************************************/
/*Function inputs: *************************************************************************************/
/*	Copy_State	<<STD_t>> 0 ... 100 <<u8>>**************************************************************/
/*Function return: No return****************************************************************************/
/*Function Description:"This function Set Speed For L298N DC Motor Driver Channel 2"********************/
/*******************************************************************************************************/
	
	void DCM_CH2_voidSetMotorSpeed(u8 copy_u8Speed)
	{
		TMR0_voidSetDutycycle(copy_u8Speed);
		TMR0_voidStart();
	}
#endif
