/*
 * TMR1_program.c
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PORT_interface.h"
#include "TMR1_interface.h"
#include "TMR1_private.h"


/**********************************************************************************/
void TMR1_vStartTimerMicros(uint32 Copy_u32Delay)
{
	//Enable TMR3
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, TIM1EN);
	//Setup counter to 0
	TMR1->CNT = 0;
	TMR1->PSC = 7;
	TMR1->ARR = Copy_u32Delay;
	TMR1->CR1 = 0x01; // Enable Timer
}
/**********************************************************************************/

void TMR1_vDelayMicros(uint32 Copy_u32Delay)
{
	TMR1_vStartTimerMicros(Copy_u32Delay);
	TMR1->CR1 = 9;
	while(GET_BIT(TMR1->CR1,0)==1);
}
/**********************************************************************************/

void TMR1_vDelayMillis(uint32 Copy_u32Delay)
{
	for(uint32 i=0 ; i<Copy_u32Delay ; i++)
	{
		TMR1_vDelayMicros(1000);
	}
}
/**********************************************************************************/
void TMR1_vPWMInit(uint32 Copy_u32ARR , uint32 Copy_u32Compare,uint8 Copy_u8Channel)
{
	if(GET_BIT(TMR1->CCER,(4*(Copy_u8Channel-1)))==0){
		//Initialize Timer
		//Enable TMR1
		RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, TIM1EN);
		RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 0);

		//Enable Bus and channel pin
		RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 2);
		GPIO_vSetPinMode(GPIO_PORT_A  , (8+(Copy_u8Channel-1)) , GPIO_PIN_OUTPUT_SPD_50);
		GPIO_vSetPinConfig(GPIO_PORT_A, (8+(Copy_u8Channel-1)) , AFIO_PUSHPULL);

		//Setup counter to 0
		TMR1->PSC = 7;
		TMR1->CCMR1 |= 0x70  ;

		//Enable Capture/Compare
		SET_BIT(TMR1->CCER,((4*(Copy_u8Channel-1))+1));
		SET_BIT(TMR1->CCER,(4*(Copy_u8Channel-1)));
		//BDTR
		TMR1->BDTR |= 0x8000;

		//Timer Enable
		SET_BIT(TMR1->CR1,0);
		CLR_BIT(TMR1->CR1,3);
	}
	TMR1->ARR = Copy_u32ARR-1;
	TMR1->CCR1=Copy_u32Compare;
}

/**********************************************************************************/
