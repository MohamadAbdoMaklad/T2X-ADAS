/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

/* STK gobal pointer to function for call back */
void (*STK_CallBack)(void)= '\0';
/**/
/*
1. SYSTICK_SINGLE
2. SYSTICK_PERIODIC
*/
static volatile uint32 STK_Mode=0;	//static as it remains in this file - volatile as it enters ISR

void SysTick_Handler(void);

/***********************************************************************************************************************************************/
void SYSTICK_vInit(void)
{
	#if SYSTICK_CLK_SRC == SYSTICK_CLK_AHB
	SET_BIT(STK->CTRL,STK_CLKSOURCE);
	
	#elif SYSTICK_CLK_SRC == SYSTICK_CLK_AHB_8
	STK->CTRL=0;
	
	#endif
}

/***********************************************************************************************************************************************/
/* A function to put a value at the the STK_LOAD register and wait till the STK_VAL reaches 0 (delay) */
void SYSTICK_vSetBusyWait(uint32 Copy_u32Ticks)
{
	//load value at the STK_LOAD register
	STK->LOAD = Copy_u32Ticks;
	
	//start timer
	SET_BIT(STK->CTRL,STK_ENABLE);
	
	//wait till the STK_VAL reaches 0
	while(GET_BIT(STK->CTRL,STK_COUNTFLAG)==0);
	
	//stop timer
	CLR_BIT(STK->CTRL,STK_ENABLE);
	STK->LOAD=0;
	STK->VAL=0;
}

/***********************************************************************************************************************************************/

uint32 SYSTICK_u32GetRemainingTime(void)
{
	uint32 Local_RemainingTime=0;
	Local_RemainingTime = STK->VAL;
	return Local_RemainingTime;
}

/***********************************************************************************************************************************************/

uint32 SYSTICK_u32GetElapsedTime(void)
{
	uint32 Local_ElapsedTime=0;
	Local_ElapsedTime = STK->LOAD - STK->VAL;
	return Local_ElapsedTime;
}


/***********************************************************************************************************************************************/

void SYSTICK_vSetIntervalSingle(uint32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	//load ticks to load register
	STK->LOAD = Copy_u32Ticks;
	
	//set callback
	STK_CallBack = Copy_ptr;
	
	//set mode to single
	STK_Mode = SYSTICK_SINGLE;
	
	//Enable STK interrupt
	SET_BIT(STK->CTRL,STK_TICKINT);
	
	//start timer
	SET_BIT(STK->CTRL,STK_ENABLE);
}

/***********************************************************************************************************************************************/

void SYSTICK_vSetIntervalPeriodic(uint32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	//load ticks to load register
	STK->LOAD = Copy_u32Ticks;
	
	//set callback
	STK_CallBack = Copy_ptr;
	
	//set mode to periodeic
	STK_Mode = SYSTICK_PERIODIC;
	
	//Enable STK interrupt
	SET_BIT(STK->CTRL,STK_TICKINT);
	
	//start timer
	SET_BIT(STK->CTRL,STK_ENABLE);
}

/***********************************************************************************************************************************************/

void SysTick_Handler(void)
{
	uint8 Local_Temp; // a variable used to read the flag
	if(STK_Mode == SYSTICK_SINGLE)
	{
		/* Disable Interrupt */
		CLR_BIT(STK->CTRL,STK_TICKINT);
		
		/* stop timer */
		CLR_BIT(STK->CTRL,STK_ENABLE);
		STK->LOAD = 0;
		STK->VAL =0;
	}
	
	STK_CallBack();
	/* clear the flag by reading its value */
	Local_Temp = GET_BIT(STK->CTRL,STK_COUNTFLAG);
}


/***********************************************************************************************************************************************/

void _delay_us(uint32 Copy_u32Time)
{
	#if SYSTICK_CLK_SRC == SYSTICK_CLK_AHB
	SYSTICK_vSetBusyWait(Copy_u32Time);
	
	#elif SYSTICK_CLK_SRC == SYSTICK_CLK_AHB_8
	SYSTICK_vSetBusyWait(Copy_u32Time);
	#endif
	
}


/***********************************************************************************************************************************************/

void _delay_ms(uint32 Copy_u32Time)
{
	#if SYSTICK_CLK_SRC == SYSTICK_CLK_AHB
	SYSTICK_vSetBusyWait(Copy_u32Time*1000);
	
	#elif SYSTICK_CLK_SRC == SYSTICK_CLK_AHB_8
	SYSTICK_vSetBusyWait(Copy_u32Time*1000);
	#endif
}
