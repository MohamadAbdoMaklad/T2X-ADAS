/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/********************************** Macros *****************************/


/* port IDs */
#define GPIO_PORT_A			0
#define GPIO_PORT_B			1
#define GPIO_PORT_C			2


/* pin IDs */
#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7
#define GPIO_PIN_8		8
#define GPIO_PIN_9		9
#define GPIO_PIN_10		10
#define GPIO_PIN_11		11
#define GPIO_PIN_12		12
#define GPIO_PIN_13		13
#define GPIO_PIN_14		14
#define GPIO_PIN_15		15

typedef enum{
	PA_0 , PA_1 , PA_2  , PA_3  , PA_4  , PA_5  , PA_6  , PA_7  ,
	PA_8 , PA_9 , PA_10 , PA_11 , PA_12 , PA_13 , PA_14 , PA_15 ,
	PB_0 , PB_1 , PB_2  , PB_3  , PB_4  , PB_5  , PB_6  , PB_7  ,
	PB_8 , PB_9 , PB_10 , PB_11 , PB_12 , PB_13 , PB_14 , PB_15 ,
	PC_0 , PC_1 , PC_2  , PC_3  , PC_4  , PC_5  , PC_6  , PC_7  ,
	PC_8 , PC_9 , PC_10 , PC_11 , PC_12 , PC_13 , PC_14 , PC_15 ,
}GPIO_Pin_t;

/* pin mode */
#define GPIO_PIN_INPUT				0
#define GPIO_PIN_OUTPUT_SPD_10		1
#define GPIO_PIN_OUTPUT_SPD_2		2
#define GPIO_PIN_OUTPUT_SPD_50		3


/* pin configuration */
//In Input Mode
#define GPIO_IN_ANALOG_MODE			0
#define GPIO_IN_FLOATING			1
#define GPIO_IN_PULL				2

//In output mode
#define GPIO_OUT_PUSHPULL			0
#define GPIO_OUT_OPENDRAIN			1

//Alternate Function
#define AFIO_PUSHPULL				2
#define AFIO_OPENDRAIN				3


#define HIGH						1
#define LOW							0

/* Locking a pin */
#define GPIO_LOCKED_PIN				16

/* Alternate Function */
#define ALTFN_PUSHPULL				2
#define ALTFN_OPENDRAIN				3


#define AFIO_REMAP					0
#define AFIO_NO_REMAP				1



/* AFIO RMAP register */
#define AFIO_SPI1_REMAP					0
#define AFIO_I2C1_REMAP					1
#define AFIO_USART1_REMAP				2
#define AFIO_USART2_REMAP				3
#define AFIO_USART3_REMAP				4
#define AFIO_TIM1_REMAP					6
#define AFIO_TIM2_REMAP					8
#define AFIO_TIM3_REMAP					10
#define AFIO_TIM4_REMAP					12
#define AFIO_CAN_REMAP					13
#define AFIO_PD01_REMAP					15
#define AFIO_TIM5CH4_REMAP				16
#define AFIO_ADC1_ETRGREG_REMAP			17
#define AFIO_ADC1_ETRGINJ_REMAP			18
#define AFIO_ADC2_ETRGREG_REMAP			19
#define AFIO_ADC2_ETRGINJ_REMAP			20
#define AFIO_SWJ_CFG					24




/**************************** Prototypes *********************************/

/*
FUNCTION NAME        : GPIO_vSetPinMode
FUNCTION DESCRIPTION : selects a mode
FUNCTION INPUT       : Copy_u8Port: selected port , Copy_u8Pin: selected pin
modes :
1. GPIO_PIN_INPUT
2. GPIO_PIN_OUTPUT_SPD_10
3. GPIO_PIN_OUTPUT_SPD_2
4. GPIO_PIN_OUTPUT_SPD_50
FUNCTION OUTPUT      :
 */
void GPIO_vSetPinMode(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Mode);

/*
FUNCTION NAME        : GPIO_vSetPinConfig
FUNCTION DESCRIPTION : sets the configuration of the pin (input or output)
FUNCTION INPUT       : Copy_u8Port: selected port , Copy_u8Pin: selected pin
Config(input) :
1. GPIO_IN_ANALOG_MODE
2. GPIO_IN_FLOATING
3. GPIO_IN_PULL
config(output):
1. GPIO_OUT_PUSHPULL
2. GPIO_OUT_OPENDRAIN
3. AFIO_PUSHPULL
4. AFIO_OPENDRAIN
FUNCTION OUTPUT      : void
 */
void GPIO_vSetPinConfig(uint8 Copy_u8Port,uint8 Copy_u8Pin , uint8 Copy_u8ConfigType);

/*
FUNCTION NAME        : GPIO_vSetPinValue
FUNCTION DESCRIPTION : Puts the value to the output GPIO pin
FUNCTION INPUT       : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u8Value: 0 or 1
FUNCTION OUTPUT      : void
 */
void GPIO_vSetPinValue(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Value);

/*
FUNCTION NAME        : GPIO_u8GetPinValue
FUNCTION DESCRIPTION : Reads the value of the GPIO input
FUNCTION INPUT       : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION OUTPUT      : returns the pin value (0 or 1)
 */
uint8 GPIO_u8GetPinValue(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : GPIO_vPinLock
FUNCTION DESCRIPTION : Locks a pin
FUNCTION INPUT       : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION OUTPUT      : void
 */
void GPIO_vPinLock(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : GPIO_vSetPinAltFn
FUNCTION DESCRIPTION : sets a selected Alternate Function
FUNCTION INPUT       : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u9AltFn: selected Alternate Function
FUNCTION OUTPUT      : void
 */
void GPIO_vSetPinAltFn(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u9AltFn);



#endif
