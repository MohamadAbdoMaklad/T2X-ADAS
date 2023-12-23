/*
 * SERVO_program.c
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "TMR1_interface.h"
#include "SERVO_interface.h"


void SERVO_vSetAngle(uint8 Copy_u8Angle)
{
	if(Copy_u8Angle <= SERVO_OPEN_ANGLE)
	{
		uint16 LOC_Compare = SERVO_ZERO_SHIFT + (Copy_u8Angle*1000ul)/180ul;
		TMR1_vPWMInit(SERVO_PERIOD , LOC_Compare , TMR1_CHANNEL_1);
	}
}
