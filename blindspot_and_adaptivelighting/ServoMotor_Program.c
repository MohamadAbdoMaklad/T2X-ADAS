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

#define F_CPU 16000000UL
#include <util/delay.h>
#include "ServoMotor_Interface.h"
#include "LIB_STD.h"
#include "DIO_Interface.h"
void ServoMotor_voidInit(void)
{
	// Make the OCIA Pin output
	Dio_SetChannelDirection(DIOB5, OUTPUT);
	/* Init Timer 1 with
	T1_FastPWM_M14
	T1_PWM_NONINVERTING
	T1_PRESCALER_64
	*/
	T1_voidInit();
	//Set The frequency 50Hz ("According to SG90 Motor Data sheet")
	T1_SetFreq_Mode14(50);
}
void ServoMotor_SetAngle(u8 copy_u8Angle)
{
	//input range chick 0 -- 180 degree
	switch (copy_u8Angle)
	{
		case 0 ... 180:
		{
			/*Take angle and make the mapping equation to get 
			the corresponding duty cycle */
			T1_SetDyty_Mode14((f32)(((copy_u8Angle)*((f32)11/180))+2));
			//Start Timer 1 To Operate
			T1_voidStart();	
		}break;
		default:
		{
			
		}
	}
}

void ServoMotor_Off(void)
{
	//Delay to avoid cutting timer operation
	_delay_ms(400);
	//stop the timer
	T1_voidStop();
}
