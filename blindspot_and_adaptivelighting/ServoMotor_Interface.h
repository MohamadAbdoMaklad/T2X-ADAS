/********************************************************/
/*Author	            : Mohamad Abdo Maklad			*/
/*Date		            : 28-10-2023					*/
/*Last Modification		: 28-10-2023					*/
/*Version	            : V01.00			   			*/
/********************************************************/
/*Controller            :ATMEGA32						*/
/*SWC                   :Servo Motor SG90				*/
/*Description           :HAL SWC Dependant (DIO/Timer1)	*/
/********************************************************/

#ifndef SERVOMOTOR_INTERFACE_H_
#define SERVOMOTOR_INTERFACE_H_
// Standard Lib Includes
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
//MCAL Includes
#include "DIO_Interface.h"
#include "Timer1_Interface.h"
/*||||||||||{ Servo Motor API Functions }||||||||||*/
/*Function to Init the motor before using it*/
void ServoMotor_voidInit(void);
/*function to set angle for the motor 0 - 180 */
/*NOTE "Angles Out the range will take no action" */
void ServoMotor_SetAngle(u8 copy_u8Angle);
/*Function to stop the motor "stop timer1" */
/*NOTE: "This function have internally a 500msec delay to 
		avoid stopping timer leading to stopping the motor 
		before reaching the correct angle"*/
void ServoMotor_Off(void);

#endif /* SERVOMOTOR_INTERFACE_H_ */
