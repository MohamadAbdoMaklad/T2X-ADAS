/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "RCC_interface.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "PORT_config.h"
#include "PORT_interface.h"

extern Port_ConfigType Port_cngs[PORT_MAX_NUMBER_PINS];

void PORT_vInit(void)
{
	for(uint8 i=0 ; i<PORT_MAX_NUMBER_PINS ; i++)
	{
		if(Port_cngs[i].config==-1)
		{
			break;
		}
		switch(Port_cngs[i].Port)
		{
		case GPIO_PORT_A:
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, GPIOA_EN);
			switch(Port_cngs[i].config)
			{
			case GPIO_OUT_10_PP:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_10);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_2_PP:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_2);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_50_PP:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_50);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_10_OD:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_10);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_OUT_2_OD:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_2);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_OUT_50_OD:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_50);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_INP_ANALOG:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_IN_ANALOG_MODE);
				break;

			case GPIO_INP_FLOAT:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_IN_FLOATING);
				break;

			case GPIO_INP_PULL:
				GPIO_vSetPinMode(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_A, Port_cngs[i].Pin, GPIO_IN_PULL);
				break;

			}
			break;

		case GPIO_PORT_B:
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, GPIOB_EN);
			switch(Port_cngs[i].config)
			{
			case GPIO_OUT_10_PP:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_10);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_2_PP:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_2);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_50_PP:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_50);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_10_OD:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_10);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_OUT_2_OD:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_2);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_OUT_50_OD:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_50);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_INP_ANALOG:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_IN_ANALOG_MODE);
				break;

			case GPIO_INP_FLOAT:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_IN_FLOATING);
				break;

			case GPIO_INP_PULL:
				GPIO_vSetPinMode(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_B, Port_cngs[i].Pin, GPIO_IN_PULL);
				break;

			}
			break;

		case GPIO_PORT_C:
			RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, GPIOC_EN);
			switch(Port_cngs[i].config)
			{
			case GPIO_OUT_10_PP:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_10);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_2_PP:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_2);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_50_PP:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_50);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_OUT_PUSHPULL);
				break;

			case GPIO_OUT_10_OD:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_10);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_OUT_2_OD:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_2);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_OUT_50_OD:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_OUTPUT_SPD_50);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_OUT_OPENDRAIN);
				break;

			case GPIO_INP_ANALOG:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_IN_ANALOG_MODE);
				break;

			case GPIO_INP_FLOAT:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_IN_FLOATING);
				break;

			case GPIO_INP_PULL:
				GPIO_vSetPinMode(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_PIN_INPUT);
				GPIO_vSetPinConfig(GPIO_PORT_C, Port_cngs[i].Pin, GPIO_IN_PULL);
				break;

			}
			break;
		}
	}
}
