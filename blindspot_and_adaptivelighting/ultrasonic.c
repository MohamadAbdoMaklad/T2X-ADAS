/*  ULTRASONIC DRIVER SOURCE FILE
 *
 *  [FILE NANE] :ziad_ultra_sonic.c
 *
 *  Created on 26/2/2023
 *
 *  Author: ZIAD ESMAIL
 */
#include "ultrasonic.h"
#include "LIB_BIT_MATH.h"
#include "icu.h"
#include "DIO_Interface.h"
#include "ULTRASONIC_confiq.h"
#include <util/delay.h>

/* global variable to count number of capturing events */
u8 g_number_of_calling_call_back_function=0;
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
	Dio_SetChannelDirection(TRIGGER_1_PIN_CHANNEL_ID   , OUTPUT);
	Dio_SetChannelDirection(TRIGGER_2_PIN_CHANNEL_ID   , OUTPUT);
}

/*
 * Description :Function to send trigger pulse for Ultra_sonic to start working
 */
static void Ultrasonic_1_Trigger(void)
{
	/* write logic high on the Trigger pin */
	Dio_WriteChannel(TRIGGER_1_PIN_CHANNEL_ID   , STD_HIGH);
	_delay_us(15); /* the required time for triggering the Ultra_sonic  */
	/* write logic low on the Trigger pin */
	Dio_WriteChannel(TRIGGER_1_PIN_CHANNEL_ID   ,STD_LOW);
}
static void Ultrasonic_2_Trigger(void)
{
	/* write logic high on the Trigger pin */
	Dio_WriteChannel(TRIGGER_2_PIN_CHANNEL_ID   , STD_HIGH);
	_delay_us(15); /* the required time for triggering the Ultra_sonic  */
	/* write logic low on the Trigger pin */
	Dio_WriteChannel(TRIGGER_2_PIN_CHANNEL_ID   ,STD_LOW);
}
/*
 * Description :Function calculates the distance measured by the Ultra_sonic
 * 1- Trigger the Ultra_sonic by call Ultrasonic_Trigger function
 * 2. Calculate the distance in Centimeter and returns its value (uint16)
 */
u16 Ultrasonic_1_readDistance(void)
{
	/* clear used variables value to make sure that their values are not old */
	g_number_of_calling_call_back_function=0;
	g_InputCaptureValue=0;
	Icu_clearTimerValue(); /* clear timer value to start counting from 0 */
	Ultrasonic_1_Trigger();  /* call Ultrasonic_Trigger function */
	/* wait the measuring process to be completed it needs two edges one rising and another falling*/
	while(g_number_of_calling_call_back_function!=2);
#if(F_CPU==16000000UL)
	if(((g_InputCaptureValue/58)+1)/2>400)
		return 500;
	return (((g_InputCaptureValue/58)+1)/2);  /* return the distance value in Centimeter */
#endif
	if(((g_InputCaptureValue/58)+1)>400)
		return 500;
	return ((g_InputCaptureValue/58)+1);  /* return the distance value in Centimeter */
}
u16 Ultrasonic_2_readDistance(void)
{
	/* clear used variables value to make sure that their values are not old */
	g_number_of_calling_call_back_function=0;
	g_InputCaptureValue=0;
	Icu_clearTimerValue(); /* clear timer value to start counting from 0 */
	Ultrasonic_2_Trigger();  /* call Ultrasonic_Trigger function */
	/* wait the measuring process to be completed it needs two edges one rising and another falling*/
	while(g_number_of_calling_call_back_function!=2);
#if(F_CPU==16000000UL)
	if(((g_InputCaptureValue/58)+1)/2>400)
		return 500;
	return (((g_InputCaptureValue/58)+1)/2);  /* return the distance value in Centimeter */
#endif
	if(((g_InputCaptureValue/58)+1)>400)
		return 500;
	return ((g_InputCaptureValue/58)+1);  /* return the distance value in Centimeter */
}



