/* V2V */
/*
 * It Takes input from BlueTooth module and Simply Stops the vehicle using PWM
 * To indicate that there is an Emergency Break and Returns the Vehicle
 * to the ON state when the Emergency is stopped
 * */

/** UTIL **/
#include "STD_types.h"

/** MCAL **/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PORT_interface.h"
#include "SYSTICK_interface.h"
#include "UART_interface.h"

/** HAL **/
#include "L298_interface.h"

//Global flag to indicate if there is an emergency break
uint8 global_flag = 0;

/*
 * UART1_ISR: Function that occurs when an interrupt occurs by receiving data from UART1
 * Arguments: Copy_u8Data: Holds the received data
 *
 **/
void UART1_ISR(uint8 Copy_u8Data)
{
	// Led toggles to indicate the reception of Data
	static uint8 flag = 0;
	GPIO_vSetPinValue(GPIO_PORT_C, 13, flag);
	flag ^= 1;

	// check that the received data is from Emergency Break
	if(Copy_u8Data == 'G' || Copy_u8Data == 'g')
	{
		// flag set == Emergency Break
		global_flag = 1;
	}
	// check that the received data is to indicate that the Emergency break has stopped
	else if(Copy_u8Data == 'H' || Copy_u8Data == 'h')
	{
		//Return the motor to its Full speed
		L298_vCarMove(L298_HIGH_SPEED);
	}
}



int main(void)
{
	/* Initializations */
	RCC_u8InitSysClk();
	PORT_vInit();
	UART_vInit();
	UART_SetCallBack(UART_1, UART1_ISR);
	L298_vInit(GPIO_PORT_A, GPIO_PIN_0, GPIO_PIN_1, L298_CLOCKWISE);
	L298_vCarMove(L298_HIGH_SPEED);

	while(1)
	{
		//checking the state of flag to know if there is an emergency break or not
		if(global_flag == 1)
		{
			// A loop that decreases the value of PWM to stop the vehicle
			for(uint16 i=L298_CRR_HIGH ; i>=L298_CRR_STOP ; i--)
			{
				L298_vCarPWM(i);
				_delay_ms(1);
			}
			//Return the flag to 0
			global_flag = 0;
		}
	}
}
