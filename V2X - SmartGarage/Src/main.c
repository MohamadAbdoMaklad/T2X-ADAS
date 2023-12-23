/* Smart Garage */
/* A Garage That has two Slots each has an IR sensor to detect if there is a vehicle in front
 * of it.
 * A Servo is used as a gate to open when there is a vehicle in front of the gate,
 * The vehicle is detected by an UltraSonic that uses a threshold value to open Gate.
 * An Application in mobile phone is used to send some characters via BlueTooth
 * to tell the Garage what to do.
 *
 * */

/** UTIL **/
#include "STD_types.h"

/** MCAL **/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PORT_interface.h"
#include "SYSTICK_interface.h"
#include "UART_interface.h"
#include "TMR1_interface.h"

/** HAL **/
#include "SERVO_interface.h"
#include "IR_interface.h"
#include "USNC_interface.h"

/********************************************************************************************/
//Global Variable with number of Current Available slots
volatile uint8 NumberOfSlots = 0;
//Global Variable with number of reserved Slots entered by the Mobile Application
volatile uint8 ReservedSlots = 0;
/********************************************************************************************/

//Pins Used for IR sensors -> PORT A pins 0,1
GPIO_Pin_t IR_used_pins[] = {PA_0,PA_1,0xFF};
//Global variable that is set when the servo needs to be opened
volatile uint8 global_flag = 0;
/********************************************************************************************/

/** Functions Prototypes **/

void CheckAvailableLocations(void);
void ReqToOpenServo(void);
void UART_InitMsgs(void);
void UART_ScreenMsgs(void);
void ReserveLocation(void);
/********************************************************************************************/


/*
 * UART_ISR: Function that occurs when an interrupt occurs by receiving data from UART1
 * Arguments: Copy_u8Data: Holds the received data
 *
 **/
void UART_ISR(uint8 Copy_u8Data)
{
	static uint8 flag = 0;
	// Ask if there is any available location in Garage
	if(Copy_u8Data == 'A' || Copy_u8Data=='a')
	{
		CheckAvailableLocations();
	}
	// Reserve a location
	else if(Copy_u8Data == 'R' || Copy_u8Data == 'r')
	{
		ReserveLocation();
	}
	//Ask to Open the servo
	else if(Copy_u8Data== 'O'|| Copy_u8Data == 'o')
	{
		ReqToOpenServo();
	}
	GPIO_vSetPinValue(GPIO_PORT_C, 13, flag);
	flag ^= 1;
}

/********************************************************************************************/

int main(void)
{
	/* Initializations */
	RCC_u8InitSysClk();
	PORT_vInit();
	UART_vInit();
	UART_SetCallBack(UART_1, UART_ISR);
	USNC_vInit();

	/* Initialize Servo with Close State */
	SERVO_vSetAngle(SERVO_CLOSE_ANGLE);
	UART_InitMsgs();


	while(1)
	{
		UART_ScreenMsgs();

		//Request to open Garage is Successful
		if(global_flag > 0)
		{
			// Open Garage with Servo
			SERVO_vSetAngle(SERVO_OPEN_ANGLE);

			// Check if the car is still in front of the Gate
			if(USNC_vGetDistance()>10)
			{
				// if the car moved the global_flag increments
				global_flag++;
			}
			else
			{
				// if the distance < 10, then the car hasn't moved so the flag would be 1
				// to indicate the system that the car is still in front of the Gate
				global_flag = 1;
			}
			// After 2 seconds from moving the car far from the gate, the servo is closed
			if(global_flag == 4)
			{
				SERVO_vSetAngle(SERVO_CLOSE_ANGLE);

				// Reset the global flag
				global_flag = 0;

				// Decrement the number of reserved Cars
				ReservedSlots--;
			}

		}
		_delay_ms(1000);
	}
}

/********************************************************************************************/

/************************************** Functions *******************************************/

/********************************************************************************************/
/*
 * Description:
 * A function that checks if there is available positions in Garage by detecting
 * Empty Locations and decreasing the Reserved Locations.
 * Inputs: void
 * Return: void
 * Notes:
 * The Function Sends the state using the characters 'Y' or 'N' via BlueTooth
 * */
void CheckAvailableLocations(void)
{
	if((NumberOfSlots-ReservedSlots) > 0)
	{
		UART_vSendData(UART_1, 'Y');
	}
	else
	{
		UART_vSendData(UART_1, 'N');
	}
}
/********************************************************************************************/
/*
 * Description:
 * A function that is used to Reserve a Location in the Garage by incrementing ReservedSlots value
 * Inputs: void
 * Return: void
 * Notes:
 * The function sends the character 'N' if there is No available Slots in the Garage
 * */
void ReserveLocation(void)
{
	if((NumberOfSlots-ReservedSlots)>0)
	{
		ReservedSlots++;
	}
	else
	{
		//indicate the user that there is no available space in the Garage
		UART_vSendData(UART_1, 'N');
	}
}
/********************************************************************************************/
/*
 * Description:
 * A function that is called when the User asks to open the Garage
 * It checks if there is available Slots and if the vehicle is in front of the Gate
 * Inputs: void
 * Return: void
 * Notes:
 * The function sends the character 'N' if there is No available Slots in the Garage.
 * */
void ReqToOpenServo(void)
{
	// There are available Slots in Garage and Distance < 10 (A Car is in front of the Gate)
	if((NumberOfSlots-ReservedSlots) > 0 && USNC_vGetDistance()<10)
	{
		global_flag = 1;
		ReservedSlots++;
	}
	// Send Character 'N' if no available locations in the Garage
	else if(NumberOfSlots == 0)
	{
		UART_vSendData(UART_1, 'N');
	}
}
/********************************************************************************************/
/*
 * Description:
 * Initialization messages that appears when opening the terminal
 * Inputs: void
 * Return: void
 * */
void UART_InitMsgs(void)
{
	_delay_ms(5000);
	UART_vSendString(UART_2,(uint8*) "****************************************************************************\r\n");
	UART_vSendString(UART_2,(uint8*) "************************************ WELCOME *******************************\r\n");
	UART_vSendString(UART_2,(uint8*) "********************************** SMART GARAGE ****************************\r\n");
	UART_vSendString(UART_2,(uint8*) "****************************************************************************\r\n");

}
/********************************************************************************************/
/*
 * Description:
 * Display Messages that is modified Every second to check state of the garage
 * Inputs: void
 * Return: void
 * */
void UART_ScreenMsgs(void)
{
	/*	for(uint8 i=0 ; i<72 ; i++)
	{
		UART_vSendData(UART_2, 8);
	}*/
	// Check Number of Available Slots
	NumberOfSlots = IR_vNumberOfSlots();
	UART_vSendString(UART_2, (uint8*)"Number of Available Slots: ");
	UART_vSendNumber(NumberOfSlots-ReservedSlots);
	UART_vSendString(UART_2, (uint8*)" Slot\r\n");

	UART_vSendString(UART_2, (uint8*)"Number of Reserved Slots: ");
	UART_vSendNumber(ReservedSlots);
	UART_vSendString(UART_2, (uint8*)" Slot\r\n\r\n");
}

/********************************************************************************************/
