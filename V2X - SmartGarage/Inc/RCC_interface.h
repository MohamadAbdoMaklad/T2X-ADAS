/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

#include "STD_types.h"
/********** Macros for Buses ****************/
#define RCC_u8_AHB_BUS			1
#define RCC_u8_APB1_BUS			2
#define RCC_u8_APB2_BUS			3

/* AHB BUS */
#define DMA1EN					0
#define DMA2EN					1
#define SRAMEN					2
#define FLITFEN					4
#define CRCEN					6
#define FSMCEN					8
#define SDIOEN					10

/* APB1 BUS */
#define TIM2EN					0
#define TIM3EN					1
#define TIM4EN					2
#define TIM5EN					3
#define TIM6EN					4
#define TIM7EN					5
#define TIM12EN					6
#define TIM13EN					7
#define TIM14EN					8
#define WWDGEN					11
#define SPI2EN					14
#define SPI3EN					15
#define USART2EN				17
#define USART3EN				18
#define UART4EN					19
#define UART5EN					20
#define I2C1EN					21
#define I2C2EN					22
#define USBEN					23
#define CANEN					25
#define BKPEN					27
#define PWREN					28
#define DACEN					29

/* APB2 BUS */
#define AFIOEN					0
#define IOPAEN					2
#define IOPBEN					3
#define IOPCEN					4
#define IOPDEN					5
#define IOPEEN					6
#define IOPFEN					7
#define IOPGEN					8
#define ADC1EN					9
#define ADC2EN					10
#define TIM1EN					11
#define SPI1EN					12
#define TIM8EN					13
#define USART1EN				14
#define ADC3EN					15
#define TIM9EN					19
#define TIM10EN					20
#define TIM11EN					21

/* GPIO */
//BUS_APB2
#define GPIOA_EN				2
#define GPIOB_EN				3
#define GPIOC_EN				4
#define GPIOD_EN				5
#define GPIOE_EN				6
#define GPIOF_EN				7
#define GPIOG_EN				8

/* RCC_CR Register */
#define RCC_CR_HSION		0
#define RCC_CR_HSIRDY		1

#define RCC_CR_HSEON		16
#define RCC_CR_HSERDY		17

/* RCC_CFGR Register */
#define RCC_CFGR_SW0		0
#define RCC_CFGR_SW1		1

/*********** Prototypes *********************/

void RCC_u8InitSysClk				(void);

void RCC_u8EnablePeripheralClk	(uint8 Copy_u8BusID , uint8 Copy_u8PeripheralID);

void RCC_u8DisablePeripheralClk	(uint8 Copy_u8BusID , uint8 Copy_u8PeripheralID);



#endif
