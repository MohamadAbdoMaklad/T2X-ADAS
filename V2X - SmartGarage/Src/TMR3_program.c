/*
 * TMR3_program.c
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PORT_interface.h"
#include "TMR3_interface.h"
#include "TMR3_private.h"


/**********************************************************************************/
void TMR3_vStartTimerMicros(uint32 Copy_u32Delay)
{
	//Enable TMR3
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, TIM1EN);
	//Setup counter to 0
	TMR3->CNT = 0;
	TMR3->PSC = 7;
	TMR3->ARR = Copy_u32Delay;
	TMR3->CR1 = 0x01; // Enable Timer
}
/**********************************************************************************/

void TMR3_vDelayMicros(uint32 Copy_u32Delay)
{
	TMR3_vStartTimerMicros(Copy_u32Delay);
	TMR3->CR1 = 9;
	while(GET_BIT(TMR3->CR1,0)==1);
}
/**********************************************************************************/

void TMR3_vDelayMillis(uint32 Copy_u32Delay)
{
	for(uint32 i=0 ; i<Copy_u32Delay ; i++)
	{
		TMR3_vDelayMicros(1000);
	}
}
/**********************************************************************************/
void TMR3_vPWMInit(uint32 Copy_u32ARR , uint32 Copy_u32Compare,uint8 Copy_u8Channel)
{
	if(GET_BIT(TMR3->CCER,(4*(Copy_u8Channel-1)))==0){
		//Initialize Timer
		//Enable TMR3
		RCC_u8EnablePeripheralClk(RCC_u8_APB1_BUS, TIM3EN);
		RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 0);

		if(Copy_u8Channel==1 || Copy_u8Channel==2)
		{
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 2);
			GPIO_vSetPinMode(GPIO_PORT_A  , (6+(Copy_u8Channel-1)) , GPIO_PIN_OUTPUT_SPD_50);
			GPIO_vSetPinConfig(GPIO_PORT_A, (6+(Copy_u8Channel-1)) , AFIO_PUSHPULL);
		}
		else if(Copy_u8Channel==3 || Copy_u8Channel==4)
		{
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 3);
			GPIO_vSetPinMode(GPIO_PORT_B  , (0+(Copy_u8Channel-3)) , GPIO_PIN_OUTPUT_SPD_50);
			GPIO_vSetPinConfig(GPIO_PORT_B, (0+(Copy_u8Channel-3)) , AFIO_PUSHPULL);
		}


		//Setup counter to 0
		TMR3->PSC = 7;
		TMR3->CCMR1 |= 0x70  ;

		//Enable Capture/Compare
		SET_BIT(TMR3->CCER,((4*(Copy_u8Channel-1))+1));
		SET_BIT(TMR3->CCER,(4*(Copy_u8Channel-1)));

		//SET_BIT(TMR3->EGR,0);
		//Timer Enable
		SET_BIT(TMR3->CR1,0);
		CLR_BIT(TMR3->CR1,3);
	}
	TMR3->ARR = Copy_u32ARR-1;
	TMR3->CCR1=Copy_u32Compare;

}
/**********************************************************************************/

void TMR3_vCapture(uint32 Copy_u32ARR , uint8 Copy_u8Edge ,uint8 Copy_u8Channel)
{
	if(GET_BIT(TMR3->CCER,(4*(Copy_u8Channel-1)))==0){
		//Initialize Timer
		//Enable TMR3
		RCC_u8EnablePeripheralClk(RCC_u8_APB1_BUS, TIM3EN);
		RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 0);

		if(Copy_u8Channel==1 || Copy_u8Channel==2)
		{
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 2);
			GPIO_vSetPinMode(GPIO_PORT_A  , (6+(Copy_u8Channel-1)) , GPIO_PIN_INPUT);
			GPIO_vSetPinConfig(GPIO_PORT_A, (6+(Copy_u8Channel-1)) , GPIO_IN_PULL);
		}
		else if(Copy_u8Channel==3 || Copy_u8Channel==4)
		{
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 3);
			GPIO_vSetPinMode(GPIO_PORT_B  , (0+(Copy_u8Channel-3)) , GPIO_PIN_INPUT);
			GPIO_vSetPinConfig(GPIO_PORT_B, (0+(Copy_u8Channel-3)) , GPIO_IN_PULL);
		}

		//Setup counter to 0
		TMR3->PSC = 7;
		if(Copy_u8Channel==1 || Copy_u8Channel==2)
		{
			SET_BIT(TMR3->CCMR1,(Copy_u8Channel-1)*8);
		}
		else if(Copy_u8Channel==3 || Copy_u8Channel==4)
		{
			SET_BIT(TMR3->CCMR1,(Copy_u8Channel-3)*8);
		}

		SET_BIT(TMR3->CCER,(4*(Copy_u8Channel-1)));

		//TMR3->BDTR |= 0x8000;

		SET_BIT(TMR3->CR1,0);
		CLR_BIT(TMR3->CR1,3);
	}

	// select an Edge
	if(Copy_u8Edge == TMR3_RISING_EDGE)
	{
		CLR_BIT(TMR3->CCER,((4*(Copy_u8Channel-1))+1));
	}
	else if(Copy_u8Edge == TMR3_FALLING_EDGE)
	{
		SET_BIT(TMR3->CCER,(4*(Copy_u8Channel-1)));
		SET_BIT(TMR3->CCER,((4*(Copy_u8Channel-1))+1));
	}

	TMR3->ARR = Copy_u32ARR-1;
}
/**********************************************************************************/

uint32 TMR3_u32GetCapture(void)
{
	uint32 Loc_Capture = TMR3->CCR2;
	return Loc_Capture;
}
/**********************************************************************************/
void TMR3_vWaitFlag(void)
{
	while(GET_BIT(TMR3->SR,2)==0);
}
/**********************************************************************************/

