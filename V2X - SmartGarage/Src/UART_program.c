/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"
#include "NVIC_interface.h"


#define UART_TIME_OUT	1000

/*********************************************************************************************************************************/
void (*GP_UART_1)(uint8)= NULL;
void (*GP_UART_2)(uint8)= NULL;
/*********************************************************************************************************************************/
void UART_vInit(void)
{
	#if UART1_STATUS == UART_ENABLE
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, USART1EN);
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 2);
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 0);
	GPIO_vSetPinMode(GPIO_PORT_A   , GPIO_PIN_9  , GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_A , GPIO_PIN_9  , AFIO_PUSHPULL);
	GPIO_vSetPinMode(GPIO_PORT_A   , GPIO_PIN_10 , GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(GPIO_PORT_A , GPIO_PIN_10 , GPIO_IN_PULL);

	CLR_BIT(UART1->CR1,UART_CR1_UE);
	UART1->SR = 0;
	/* data length */
	CLR_BIT(UART1->CR1,UART_CR1_M);
	/* stop bits */
	CLR_BIT(UART1->CR2,UART_CR2_STOP);
	CLR_BIT(UART1->CR2,(UART_CR2_STOP+1));
	//UART1->CR2 |= (UART1_STOP_BIT<<UART_CR2_STOP);
	/* Transmitter */
	SET_BIT(UART1->CR1,UART_CR1_TE);
	/* Receiver */
	SET_BIT(UART1->CR1,UART_CR1_RE);
	/* Parity */
	//UART1->CR1 |= (UART1_PARITY<<UART_CR1_PCE);
	# if UART1_PARITY == UART_PARITY_ENABLE
	UART1->CR1 |= (UART1_PARITY_MODE<<UART_CR1_PS);
	#endif
	UART1->BRR = UART1_BAUD_RATE;
	#if defined UART1_INTERRUPT_ENABLE
	NVIC_vEnableInterrupt(UART1_NVIC);
	#endif
	#if UART1_INT_RX == UART_ENABLE
	//Enable interrupt for reciever
	SET_BIT(UART1->CR1,UART_CR1_RXNEIE);
	#endif
	#if UART1_INT_TX == UART_ENABLE
	//Enable interrupt for transmitter
	SET_BIT(UART1->CR1,UART_CR1_TXEIE);
	#endif
	CLR_BIT(UART1->CR2,UART_CR2_CLKEN);
	CLR_BIT(UART1->CR2,UART_CR2_LINEN);
	CLR_BIT(UART1->CR3,5);
	CLR_BIT(UART1->CR3,3);
	CLR_BIT(UART1->CR3,1);
	SET_BIT(UART1->CR1,UART_CR1_UE);
	#endif
	
	#if UART2_STATUS == UART_ENABLE
	RCC_u8EnablePeripheralClk(RCC_u8_APB1_BUS, USART2EN);
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 2);
	RCC_u8EnablePeripheralClk(RCC_u8_APB2_BUS, 0);
	GPIO_vSetPinMode(GPIO_PORT_A   , GPIO_PIN_2  , GPIO_PIN_OUTPUT_SPD_50);
	GPIO_vSetPinConfig(GPIO_PORT_A , GPIO_PIN_2  , AFIO_PUSHPULL);
	GPIO_vSetPinMode(GPIO_PORT_A   , GPIO_PIN_3  , GPIO_PIN_INPUT);
	GPIO_vSetPinConfig(GPIO_PORT_A , GPIO_PIN_3  , GPIO_IN_FLOATING);

	CLR_BIT(UART2->CR1,UART_CR1_UE);
	UART2->SR = 0;

	/* data length */
	CLR_BIT(UART2->CR1,UART_CR1_M);
	/* stop bits */
	CLR_BIT(UART2->CR2,UART_CR2_STOP);
	CLR_BIT(UART2->CR2,(UART_CR2_STOP+1));
	/* Transmitter */
	SET_BIT(UART2->CR1,UART_CR1_TE);
	/* Receiver */
	SET_BIT(UART2->CR1,UART_CR1_RE);
	/* Parity */
	//UART2->CR1 |= (UART2_PARITY<<UART_CR1_PCE);
	# if UART1_PARITY == UART_PARITY_ENABLE
	UART2->CR1 |= (UART2_PARITY_MODE<<UART_CR1_PS);
	#endif
	UART2->BRR = UART2_BAUD_RATE;
	#if defined UART2_INTERRUPT_ENABLE
	NVIC_vEnableInterrupt(UART2_NVIC);
	#endif
	#if UART2_INT_RX == UART_ENABLE
	//Enable interrupt for reciever
	SET_BIT(UART2->CR1,UART_CR1_RXNEIE);
	#endif
	#if UART2_INT_TX == UART_ENABLE
	//Enable interrupt for transmitter
	SET_BIT(UART2->CR1,UART_CR1_TXEIE);
	#endif
	CLR_BIT(UART2->CR2,UART_CR2_CLKEN);
	CLR_BIT(UART2->CR2,UART_CR2_LINEN);
	CLR_BIT(UART2->CR3,5);
	CLR_BIT(UART2->CR3,3);
	CLR_BIT(UART2->CR3,1);
	SET_BIT(UART2->CR1,UART_CR1_UE);
	#endif
	
}
/*********************************************************************************************************************************/
void UART_vSendData(uint8 Copy_u8UartID , uint8 Copy_u8Data)
{
	if(Copy_u8UartID == UART_1)
	{
		//put the data in the data register
		UART1->DR = Copy_u8Data;
		// wait till the transmision is complete & reading when the flag turns to 1 to clear it
		while(GET_BIT(UART1->SR,UART_SR_TC)==0);
		//clear the TC flag
		CLR_BIT(UART1->SR,UART_SR_TC);
	}
	else if(Copy_u8UartID == UART_2)
	{
		//put the data in the data register
		UART2->DR = Copy_u8Data;
		// wait till the transmision is complete & reading when the flag turns to 1 to clear it
		while(GET_BIT(UART2->SR,UART_SR_TC)==0);
		//clear the TC flag
		CLR_BIT(UART2->SR,UART_SR_TC);
	}
}
/*********************************************************************************************************************************/
void UART_vSendString(uint8 Copy_u8UartID , uint8 *Copy_u8String)
{
	uint8 *Local_ptr = Copy_u8String;
	while(*Local_ptr != '\0')
	{
		UART_vSendData(Copy_u8UartID,*Local_ptr);
		Local_ptr++;
	}
}
/*********************************************************************************************************************************/

void UART_vSendNumber(uint16 Copy_u16Number)
{
	sint8 i=0;// counter
	uint8 LOC_arr[8];//array holding numbers
	if(Copy_u16Number/10 == 0)
	{
		UART_vSendData(UART_2, Copy_u16Number+48);
	}
	else
	{
		while(Copy_u16Number != 0)
		{
			LOC_arr[i]=Copy_u16Number%10;
			Copy_u16Number = Copy_u16Number / 10;
			i++;
		}
		while(i > 0)
		{
			i--;
			UART_vSendData(UART_2, LOC_arr[i]+48);
		}
	}
}
/*********************************************************************************************************************************/
uint8 UART_u8ReceiveData(uint8 Copy_u8UartID)
{
	uint8 Local_Data=0 ;
	uint16 time = UART_TIME_OUT;
	if(Copy_u8UartID == UART_1)
	{
		CLR_BIT(UART1->SR,UART_SR_RXNE);
		//wait for the flag to set
		while(GET_BIT(UART1->SR,UART_SR_RXNE)==0 && time > 0)
		{
			time--;
		}

		Local_Data = UART1->DR;
		CLR_BIT(UART1->SR,UART_SR_RXNE);
	}
	else if(Copy_u8UartID == UART_2)
	{
		CLR_BIT(UART2->SR,UART_SR_RXNE);
		//wait for the flag to set
		while(GET_BIT(UART2->SR,UART_SR_RXNE)==0 && time > 0)
		{
			time--;
		}
		Local_Data = UART2->DR;
		CLR_BIT(UART2->SR,UART_SR_RXNE);
	}
	return Local_Data;
}
/*********************************************************************************************************************************/
uint8 UART_u8ReturnData(uint8 Copy_u8UartID)
{
	uint8 LOC_returnValue;
	if(Copy_u8UartID == UART_1)
	{
		LOC_returnValue = UART1->DR;
	}
	else if(Copy_u8UartID == UART_2)
	{
		LOC_returnValue = UART2->DR;
	}
	return LOC_returnValue;
}
/*********************************************************************************************************************************/
void UART_SetCallBack(uint8 Copy_u8UartID , void (*ptr_function)(uint8))
{
	if(Copy_u8UartID == UART_1)
	{
		GP_UART_1 = ptr_function;
	}
	else if(Copy_u8UartID == UART_2)
	{
		GP_UART_2 = ptr_function;
	}
	
}

/*********************************************************************************************************************************/
void USART1_IRQHandler(void)
{
	if(GP_UART_1 != NULL)
	{
		UART1->SR = 0;
		GP_UART_1(UART1->DR);
	}
}

/*********************************************************************************************************************************/
void USART2_IRQHandler(void)
{
	if(GP_UART_2 != NULL)
	{
		UART2->SR = 0;
		GP_UART_2(UART2->DR);
	}
}
/*********************************************************************************************************************************/
