/*  INPUT CAPTURE UNIT DRIVER SOURCE FILE
 *
 *  [FILE NANE] :icu.c
 *
 *  Created on 15/11/2023
 *
 *  Author: ZIAD ESMAIL
 */
#include "icu.h"
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
#include "ICU_reg.h"

#include <avr/interrupt.h>

/* a pointer to function to capture the passed address of call back function */
void (*callBack)(void);
ISR(TIMER3_CAPT_vect)
{
	/* call the call back function  */
	(*callBack)();
}

/*
 * Description : Function to initialize the ICU driver
 * 	1- Select the selected prescaler
 * 	2- Set the selected edge detection.
 * 	3- Enable the Input Capture Interrupt.
 * 	4- Initialize Timer3 Registers
 * 	5- enable global interrupts
 * 	INPUTS: required edge detection and prescaler
 * 	edge detection: 0 for falling edge an 1 for rising edge
 *  prescaler: 8,64,256,1024 and default 1
 *  RETURNS: none
 */
void ICU_init(u8 edge_select, u16 prescaler)
{
	TCCR3A=0;
	TCCR3B=0;
	ETIFR=0;
	ETIMSK=0;
    ICR3=0;
    TCNT3=0;

	DDRE &= ~(1<<7);             /* set ICP3/PE7 as i/p pin */

	/* select capture edge rising or falling */
	if (edge_select==HIGH)
		SET_BIT(TCCR3B,ICES3);   /* rising edge */
	else
		CLEAR_BIT(TCCR3B,ICES3); /* falling edge */


/* clear first three bits in TCCR1B Register to insert prescaler in them */
	TCCR3B &=(0xf8);
	TCNT3=0;               /* initialize timer3 value  */
	ICR3=0;                /* initialize input capture unit value  */

	SET_BIT(ETIMSK,TICIE3); /* enable input capture interrupt */
	SET_BIT(ETIFR,ICF3);    /* enable input capture interrupt flag */
	SET_BIT(SREG,7);       /* enable global interrupts */

	switch (prescaler)
	{
	case 8:
		TCCR3B |=(0x02);      /* set the prescaler of ICU 8 */
	break;

	case 64:
		TCCR3B |=(0x03);      /* set the prescaler of ICU 64 */
	break;

	case 256:
		TCCR3B |=(0x04);      /* set the prescaler of ICU 256 */
	break;

	case 1024:
		TCCR3B |=(0x05);      /* set the prescaler of ICU 1024 */
	break;
	default:
		TCCR3B |=(0x01);      /* set the prescaler of ICU 1 */
	break;

	}

}

/*
 * Description: Function to set the Call Back function address
 * INPUTS: a pointer to function
 * RETURNS: none
 */
void ICU_setCallBack(void(*a_ptr)(void))
{
/* load the given call back function in a global pointer to function */
 callBack=a_ptr;
}

/*
 * Description: Function to set the required edge detection type
 * 	INPUTS: required edge detection
 * 	edge detection: 0 for falling edge an 1 for rising edge
 * RETURNS: none
 */
void Icu_setEdgeDetectionType(u8 edge_select)
{
/* select capture edge rising or falling */
	if (edge_select==HIGH)
		SET_BIT(TCCR3B,ICES3);    /* rising edge */
	else
		CLEAR_BIT(TCCR3B,ICES3);  /* falling edge */
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 * The value stored at Input Capture Register ICR1
 * INPUTS: none
 * RETURNS: timer1 value
 */
u16 Icu_getInputCaptureValue(void)
{
	return ICR3;
}
/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 * INPUTS: none
 * RETURNS:none
 */
void Icu_clearTimerValue(void)
{
	TCNT3 = 0;                 /* clear timer1 value */
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Drive
 * INPUTS: none
 * RETURNS:none
 */
void Icu_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR3A = 0;
	TCCR3B = 0;
	TCNT3 = 0;
	ICR3 = 0;

	/* Disable the Input Capture interrupt */
	ETIMSK &= ~(1<<TICIE3);
}
