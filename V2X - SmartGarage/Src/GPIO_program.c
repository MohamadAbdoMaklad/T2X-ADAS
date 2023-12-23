/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"


/*
Modes:
1. GPIO_PIN_INPUT
2. GPIO_PIN_OUTPUT_SPD_10
3. GPIO_PIN_OUTPUT_SPD_2
4. GPIO_PIN_OUTPUT_SPD_50
*/
void GPIO_vSetPinMode(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Mode)
{
	if (Copy_u8Pin >= 0 && Copy_u8Pin < 8)
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			GPIOA->CRL &=~(3 << (4*Copy_u8Pin)); // initialize with 0
			GPIOA->CRL |= (Copy_u8Mode << (4*Copy_u8Pin));
			break;
			
			case GPIO_PORT_B:
			GPIOB->CRL &=~(3 << (4*Copy_u8Pin)); // initialize with 0
			GPIOB->CRL |= (Copy_u8Mode << (4*Copy_u8Pin));
			break;
			
			case GPIO_PORT_C:
			GPIOC->CRL &=~(3 << (4*Copy_u8Pin)); // initialize with 0
			GPIOC->CRL |= (Copy_u8Mode << (4*Copy_u8Pin));
			break;
		}
	}
	else if(Copy_u8Pin >= 8 && Copy_u8Pin < 16)
	{
		Copy_u8Pin = Copy_u8Pin - 8;
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			GPIOA->CRH &=~(3 << (4*Copy_u8Pin)); // initialize with 0
			GPIOA->CRH |= (Copy_u8Mode << (4*Copy_u8Pin));
			break;
			
			case GPIO_PORT_B:
			GPIOB->CRH &=~(3 << (4*Copy_u8Pin)); // initialize with 0
			GPIOB->CRH |= (Copy_u8Mode << (4*Copy_u8Pin));
			break;
			
			case GPIO_PORT_C:
			GPIOC->CRH &=~(3 << (4*Copy_u8Pin)); // initialize with 0
			GPIOC->CRH |= (Copy_u8Mode << (4*Copy_u8Pin));
			break;
		}
	}
}

/* pin configuration */
/* In Input Mode
1. GPIO_IN_ANALOG_MODE			
2. GPIO_IN_FLOATING			
3. GPIO_IN_PULL				

In Output Mode
1. GPIO_OUT_PUSHPULL			
2. GPIO_OUT_OPENDRAIN
3. AFIO_PUSHPULL
4. AFIO_OPENDRAIN			
*/
void GPIO_vSetPinConfig(uint8 Copy_u8Port,uint8 Copy_u8Pin , uint8 Copy_u8Config)
{
	if (Copy_u8Pin >= 0 && Copy_u8Pin < 8)
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			GPIOA->CRL &=~(3 << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOA->CRL |= (Copy_u8Config << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_B:
			GPIOB->CRL &=~(3 << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOB->CRL |= (Copy_u8Config << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_C:
			GPIOC->CRL &=~(3 << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOC->CRL |= (Copy_u8Config << (4*Copy_u8Pin+2));
			break;
		}
	}
	else if(Copy_u8Pin >= 8 && Copy_u8Pin < 16)
	{
		Copy_u8Pin = Copy_u8Pin -8;
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			GPIOA->CRH &=~(3 << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOA->CRH |= (Copy_u8Config << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_B:
			GPIOB->CRH &=~(3 << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOB->CRH |= (Copy_u8Config << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_C:
			GPIOC->CRH &=~(3 << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOC->CRH |= (Copy_u8Config << (4*Copy_u8Pin+2));
			break;
		}
	}
}

/*

*/


void GPIO_vSetPinValue(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Value)
{
	if(Copy_u8Value == HIGH)
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			SET_BIT(GPIOA->ODR,Copy_u8Pin);
			break;
			
			case GPIO_PORT_B:
			SET_BIT(GPIOB->ODR,Copy_u8Pin);
			break;
			
			case GPIO_PORT_C:
			SET_BIT(GPIOC->ODR,Copy_u8Pin);
			break;
		}
	}
	else
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
		CLR_BIT(GPIOA->ODR,Copy_u8Pin);
		break;
			
		case GPIO_PORT_B:
		CLR_BIT(GPIOB->ODR,Copy_u8Pin);
		break;
			
		case GPIO_PORT_C:
		CLR_BIT(GPIOC->ODR,Copy_u8Pin);
		break;
		}
	}
}

uint8 GPIO_u8GetPinValue(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	uint8 Return_value=0;
	switch(Copy_u8Port)
	{
		case GPIO_PORT_A:
		Return_value = GET_BIT(GPIOA->IDR,Copy_u8Pin);
		break;
		
		case GPIO_PORT_B:
		Return_value = GET_BIT(GPIOB->IDR,Copy_u8Pin);
		break;
		
		case GPIO_PORT_C:
		Return_value = GET_BIT(GPIOC->IDR,Copy_u8Pin);
		break;
	}
	return Return_value;
}


void GPIO_vPinLock(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORT_A:
		SET_BIT(GPIOA->LCKR,Copy_u8Pin);
		SET_BIT(GPIOA->LCKR,GPIO_LOCKED_PIN);
		while(GET_BIT(GPIOA->LCKR,GPIO_LOCKED_PIN)==0);
		break;
		
		case GPIO_PORT_B:
		SET_BIT(GPIOB->LCKR,Copy_u8Pin);
		SET_BIT(GPIOB->LCKR,GPIO_LOCKED_PIN);
		while(GET_BIT(GPIOB->LCKR,GPIO_LOCKED_PIN)==0);
		break;
		
		case GPIO_PORT_C:
		SET_BIT(GPIOC->LCKR,Copy_u8Pin);
		SET_BIT(GPIOC->LCKR,GPIO_LOCKED_PIN);
		while(GET_BIT(GPIOC->LCKR,GPIO_LOCKED_PIN)==0);
		break;
	}
}

/*
1. ALTFN_PUSHPULL
2. ALTFN_OPENDRIAN
*/
void GPIO_vSetPinAltFn(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u9AltFn)
{
	if(Copy_u8Pin>=0 && Copy_u8Pin<8)
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			GPIOA->CRL &=~(Copy_u9AltFn << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOA->CRL |= (Copy_u9AltFn << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_B:
			GPIOB->CRL &=~(Copy_u9AltFn << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOB->CRL |= (Copy_u9AltFn << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_C:
			GPIOC->CRL &=~(Copy_u9AltFn << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOC->CRL |= (Copy_u9AltFn << (4*Copy_u8Pin+2));
			break;
		}
	}
	else if(Copy_u8Pin >= 8 && Copy_u8Pin < 16)
	{
		Copy_u8Pin = Copy_u8Pin -8;
		switch(Copy_u8Port)
		{
			case GPIO_PORT_A:
			GPIOA->CRH &=~(Copy_u9AltFn << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOA->CRH |= (Copy_u9AltFn << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_B:
			GPIOB->CRH &=~(Copy_u9AltFn << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOB->CRH |= (Copy_u9AltFn << (4*Copy_u8Pin+2));
			break;
			
			case GPIO_PORT_C:
			GPIOC->CRH &=~(Copy_u9AltFn << (4*Copy_u8Pin+2)); // initialize with 0
			GPIOC->CRH |= (Copy_u9AltFn << (4*Copy_u8Pin+2));
			break;
		}
	}
	
}

/*
#if defined GPIO_ALTERNATE_FUNCTION

void GPIO_vAFMapper(uint8 Copy_u8MapRegister , uint32 Copy_u32Peripheral , uint8 Copy_u8RemState)
{
	if(Copy_u8RemState == AFIO_REMAP)
	{

	}
}

#endif

*/
