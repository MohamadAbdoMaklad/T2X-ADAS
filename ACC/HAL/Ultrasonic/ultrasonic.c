/*  ULTRASONIC DRIVER SOURCE FILE
 *
 *  [FILE NANE] :ziad_ultra_sonic.c
 *
 *  Created on 26/2/2023
 *
 *  Author: ZIAD ESMAIL
 */
#define F_CPU 16000000UL
#include "icu.h"
#include "ultrasonic.h"
#include "LIB_BIT_MATH.h"
#include "DIO_Interface.h"
#include "ULTRASONIC_confiq.h"
#include "avr/io.h"

/* global variable to count number of capturing events */
u8 g_number_of_calling_call_back_function=0;
u8 g_readingReady=0;
/* global variable to store time taken by the ultra_sonic waves */
u16 g_InputCaptureValue=0;

/*
 * Description :Call-Back Function used to calculate g_InputCaptureValue (high time)
 * of the Ultra_sonic pulse
 */
static void Ultrasonic_edgeProcessing(void)
{
	/* increment g_number_of_calling_call_back_function variable by 1 */
	g_number_of_calling_call_back_function++;
	/* check if this is the first captured edge */
	if (g_number_of_calling_call_back_function==1)
	{
		/* clear timer value to start measuring high time from 0 */
		Icu_clearTimerValue();
		
		Icu_setEdgeDetectionType(0); /* set ICU to capture a falling edge */
	}
	/* check if this is the second captured edge */
	else if (g_number_of_calling_call_back_function==2)
	{
		/* store the high time in g_InputCaptureValue variable */
		g_InputCaptureValue=Icu_getInputCaptureValue();
		g_readingReady=1;
		
		g_number_of_calling_call_back_function=0;
		/* set ICU to capture a rising edge for the following measuring process */
		Icu_setEdgeDetectionType(1);
	}

}

/*
 * Description : Initialize the Ultra_sonic driver
 * 1- set the Trigger pin as output pin
 * 2- Initialize the ICU driver and Its Call back function.
 */
void Ultrasonic_init(void)
{
/* check on working frequency to choose the suitable prescaler */
#if(F_CPU==16000000UL)
	ICU_init(1,8);    /* Initialize the ICU with rising edge and suitable prescaler */
#elif(F_CPU==8000000UL)
	ICU_init(1,8);    /* Initialize the ICU with rising edge and suitable prescaler */
#elif(F_CPU==1000000UL)
	ICU_init(1,1);    /* Initialize the ICU with rising edge and suitable prescaler */
#endif
	/* set Call back function of ICU */
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	/* set the Trigger pin as output pin */
	Dio_SetChannelDirection(TRIGGER_PIN_CHANNEL_ID  , OUTPUT);
}

/*
 * Description :Function to send trigger pulse for Ultra_sonic to start working
 */
void Ultrasonic_Trigger_1(void)
{
	/*Clear ICU Value*/
	Icu_clearTimerValue();
	/* write logic high on the Trigger pin */
	Dio_WriteChannel(TRIGGER_PIN_CHANNEL_ID  , STD_HIGH);
}
void Ultrasonic_Trigger_2(void)
{
	/* write logic low on the Trigger pin */
	Dio_WriteChannel(TRIGGER_PIN_CHANNEL_ID  ,STD_LOW);
}
/*
 * Description :Function calculates the distance measured by the Ultra_sonic
 * 1- Trigger the Ultra_sonic by call Ultrasonic_Trigger function
 * 2. Calculate the distance in Centimeter and returns its value (uint16)
 */

u8 Ultrasonic_GetReading(u16 *Reading)
{
	u8 statues=0;
	if(1==g_readingReady)
	{
		*Reading=((u32)g_InputCaptureValue*34)/(4000);
		g_readingReady=0;
		statues=1;
	}
	return statues;
}


