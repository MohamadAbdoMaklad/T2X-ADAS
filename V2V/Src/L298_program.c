/*
 * L298_program.c
 *
 *  Created on: Dec 12, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "GPIO_interface.h"
#include "TMR1_interface.h"

#include "L298_interface.h"

/************************************************************************************/

void L298_vInit(uint8 Copy_u8Port, uint8 Copy_u8Pin1, uint8 Copy_u8Pin2, uint8 Copy_u8Dir)
{
	switch(Copy_u8Dir)
	{
	default:
	case L298_CLOCKWISE:
		GPIO_vSetPinValue(Copy_u8Port, Copy_u8Pin1, 1);
		GPIO_vSetPinValue(Copy_u8Port, Copy_u8Pin2, 0);
		break;

	case L298_ANTI_CLOCKWISE:
		GPIO_vSetPinValue(Copy_u8Port, Copy_u8Pin1, 0);
		GPIO_vSetPinValue(Copy_u8Port, Copy_u8Pin2, 1);
		break;
	}
}

/************************************************************************************/

void L298_vCarMove(uint8 Copy_u8Speed)
{
	switch (Copy_u8Speed) {
	default:
	case L298_HIGH_SPEED:
		TMR1_vPWMInit(L298_PWM_MAX, L298_CRR_HIGH,TMR1_CHANNEL_1);
		break;

	case L298_MID_SPEED:
		TMR1_vPWMInit(L298_PWM_MAX, L298_CRR_MID,TMR1_CHANNEL_1);
		break;

	case L298_LOW_SPEED:
		TMR1_vPWMInit(L298_PWM_MAX, L298_CRR_LOW,TMR1_CHANNEL_1);
		break;
	}
}

/************************************************************************************/

void L298_vCarPWM(uint16 Copy_u8Comp)
{
	TMR1_vPWMInit(L298_PWM_MAX, Copy_u8Comp,TMR1_CHANNEL_1);
}

/************************************************************************************/
void L298_vCarStop(void)
{
	TMR1_vPWMInit(L298_PWM_MAX, L298_CRR_STOP,TMR1_CHANNEL_1);
}

/************************************************************************************/
