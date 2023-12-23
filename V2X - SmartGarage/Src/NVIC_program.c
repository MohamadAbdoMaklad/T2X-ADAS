/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"



/*********************************************************************************************************************/
void NVIC_vEnableInterrupt(uint8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		SET_BIT(NVIC_ISER0,Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <= 59)      //<- 43 maskable interrupt channels + 16 interrupts line of cortex m3
	{
		Copy_u8InterruptNum = Copy_u8InterruptNum - 32;
		SET_BIT(NVIC_ISER1,Copy_u8InterruptNum);
	}
}

/*********************************************************************************************************************/
void NVIC_vDisableInterrupt(uint8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		SET_BIT(NVIC_ICER0,Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <= 59)      //<- 43 maskable interrupt channels + 16 interrupts line of cortex m3
	{
		Copy_u8InterruptNum = Copy_u8InterruptNum - 32;
		SET_BIT(NVIC_ICER1,Copy_u8InterruptNum);
	}
}


/*********************************************************************************************************************/
void NVIC_vSetPendingInterrupt(uint8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		SET_BIT(NVIC_ISPR0,Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <= 59)      //<- 43 maskable interrupt channels + 16 interrupts line of cortex m3
	{
		Copy_u8InterruptNum = Copy_u8InterruptNum - 32;
		SET_BIT(NVIC_ISPR1,Copy_u8InterruptNum);
	}
}

/*********************************************************************************************************************/
void NVIC_vClearPendingInterrupt(uint8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		SET_BIT(NVIC_ICPR0,Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <= 59)      //<- 43 maskable interrupt channels + 16 interrupts line of cortex m3
	{
		Copy_u8InterruptNum = Copy_u8InterruptNum - 32;
		SET_BIT(NVIC_ICPR1,Copy_u8InterruptNum);
	}
}


/*********************************************************************************************************************/
uint8 NVIC_vGetActive(uint8 Copy_u8InterruptNum)
{
	uint8 Return_value=0;
	if(Copy_u8InterruptNum < 32)
	{
		Return_value = GET_BIT(NVIC_IABR0,Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <= 59)      //<- 43 maskable interrupt channels + 16 interrupts line of cortex m3
	{
		Copy_u8InterruptNum = Copy_u8InterruptNum - 32;
		Return_value = GET_BIT(NVIC_IABR1,Copy_u8InterruptNum);
	}
	return Return_value;
}


/*********************************************************************************************************************/
