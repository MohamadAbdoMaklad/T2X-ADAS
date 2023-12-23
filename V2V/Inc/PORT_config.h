/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _PORT_CONFIG_H
#define _PORT_CONFIG_H

#define PORT_MAX_NUMBER_PINS			33
typedef enum{
	GPIO_OUT_10_PP,
	GPIO_OUT_2_PP,
	GPIO_OUT_50_PP,
	GPIO_OUT_10_OD,
	GPIO_OUT_2_OD,
	GPIO_OUT_50_OD,
	GPIO_INP_ANALOG,
	GPIO_INP_FLOAT,
	GPIO_INP_PULL,
}GPIO_config_t;


typedef struct{
	uint8 Port;
	uint8 Pin;
	GPIO_config_t config;
}Port_ConfigType;

#endif
