/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _SYSTICK_INTERFACE_H
#define _SYSTICK_INTERFACE_H


/************************************************** Macros *****************************************************************/
/* Clock Source Selection */
#define SYSTICK_CLK_AHB					0
#define SYSTICK_CLK_AHB_8				1

/**/
#define SYSTICK_SINGLE					0
#define SYSTICK_PERIODIC				1

/* CTRL Register Pins */
#define STK_ENABLE						0
#define STK_TICKINT						1
#define STK_CLKSOURCE					2
#define STK_COUNTFLAG					16

/************************************************** Prototypes **************************************************************/
/*
FUNCTION NAME		 : SYSTICK_vInit
FUNCTION DESCRIPTION : Initializes the system timer by configuring the clock
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void SYSTICK_vInit(void);

/*
FUNCTION NAME		 : SYSTICK_vSetBusyWait
FUNCTION DESCRIPTION : a delay function
FUNCTION INPUTS      : Copy_u32Ticks: number of ticks loaded in the LOAD register
FUNCTION RETURN      : void
*/
void SYSTICK_vSetBusyWait(uint32 Copy_u32Ticks);

/*
FUNCTION NAME		 : SYSTICK_u32GetRemainingTime
FUNCTION DESCRIPTION : a function that returns the number of ticks remaining in the VAL register
FUNCTION INPUTS      : void
FUNCTION RETURN      : returns remaining ticks number
*/
uint32 SYSTICK_u32GetRemainingTime(void);

/*
FUNCTION NAME		 : SYSTICK_u32GetElapsedTime
FUNCTION DESCRIPTION : a function that returns the number of ticks elapsed so far
FUNCTION INPUTS      : void
FUNCTION RETURN      : returns the elapsed ticks number
*/
uint32 SYSTICK_u32GetElapsedTime(void);

/*
FUNCTION NAME		 : SYSTICK_vSetIntervalSingle
FUNCTION DESCRIPTION : 
FUNCTION INPUTS      :
FUNCTION RETURN      :
*/
void SYSTICK_vSetIntervalSingle(uint32 Copy_u32Ticks,void (*Copy_ptr)(void));

/*
FUNCTION NAME		 : SYSTICK_vSetIntervalPeriodic
FUNCTION DESCRIPTION :
FUNCTION INPUTS      :
FUNCTION RETURN      :
*/
void SYSTICK_vSetIntervalPeriodic(uint32 Copy_u32Ticks,void (*Copy_ptr)(void));

/*
FUNCTION NAME		 : _delay_us
FUNCTION DESCRIPTION : Busy wait in micro seconds
FUNCTION INPUTS      : Copy_u32Time: Wait time in micro seconds
FUNCTION RETURN      : void
*/
void _delay_us(uint32 Copy_u32Time);

/*
FUNCTION NAME		 : _delay_ms
FUNCTION DESCRIPTION : Busy wait in milli seconds
FUNCTION INPUTS      : Copy_u32Time: Wait time in milli seconds
FUNCTION RETURN      : void
*/
void _delay_ms(uint32 Copy_u32Time);
#endif