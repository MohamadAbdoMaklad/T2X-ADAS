/*
 * IR_Encoder.c
 *
 *  Created on: Nov 21, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "GPIO_interface.h"
#include "IR_interface.h"
/****************************************************************************/
extern GPIO_Pin_t IR_used_pins[35];


/****************************************************************************/

uint8 IR_vDetectObject(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	uint8 LOC_Ret = IR_OBJECT_FALSE;
	if(GPIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin) == HIGH)
	{
		LOC_Ret = IR_OBJECT_FALSE;
	}
	else
	{
		LOC_Ret = IR_OBJECT_TRUE;
	}
	return LOC_Ret;
}

/****************************************************************************/

uint8 IR_vNumberOfSlots(void)
{
	uint8 LOC_numberOfSlots = 0;
	for(uint8 i=0 ; i<35 ; i++)
	{
		if(IR_used_pins[i] == 0XFF)
		{
			break;
		}
		if(IR_vDetectObject(IR_used_pins[i]/16, IR_used_pins[i]%16) == IR_OBJECT_TRUE)
		{
			LOC_numberOfSlots ++;
		}
	}
	return LOC_numberOfSlots;
}

/****************************************************************************/

