/*  INPUT CAPTURE UNIT DRIVER HEADER FILE
 *
 *  [FILE NANE] :icu.h
 *
 *  Created on 15/11/2023
 *
 *  Author: ZIAD ESMAIL
 */

#ifndef ICU_H_
#define ICU_H_


#include"LIB_STD.h"

/*
 * Description : Function to initialize the ICU driver
 * 	1- Select the selected prescaler
 * 	2- Set the selected edge detection.
 * 	3- Enable the Input Capture Interrupt.
 * 	4- Initialize Timer1 Registers
 * 	5- enable global interrupts
 * 	INPUTS: required edge detection and prescaler
 * 	edge detection: 0 for falling edge an 1 for rising edge
 *  prescaler: 8,64,256,1024 and default 1
 *  RETURNS: none
 */

void ICU_init(u8 edge_select,u16 prescaler);

/*
 * Description: Function to set the Call Back function address
 * INPUTS: a pointer to function
 * RETURNS: none
 */
void ICU_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection type
 * 	INPUTS: required edge detection
 * 	edge detection: 0 for falling edge an 1 for rising edge
 * RETURNS: none
 */
void Icu_setEdgeDetectionType(u8 edge_select);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 * The value stored at Input Capture Register ICR1
 * INPUTS: none
 * RETURNS: timer1 value
 */
u16 Icu_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 * INPUTS: none
 * RETURNS:none
 */
void Icu_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Drive
 * INPUTS: none
 * RETURNS:none
 */
void Icu_DeInit(void);



#endif /* ICU_H_ */
