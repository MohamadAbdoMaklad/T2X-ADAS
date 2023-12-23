/*
 * uart.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Lenovo
 */

#include<avr/io.h>
#include"uart.h"
static void (*g_ptrToFunOVF)(void)=NULL;

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)


void UART_init(void)
{
	UCSRA = (1 << U2X);
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE >> 8;
	UBRRL = BAUD_PRESCALE;
}

void UART_sendByte(const uint8_t data)
{
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	UDR = data;

}

uint8_t UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
    return UDR;
}

void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}

}

void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}
uint8_t USART_u8ReceiverInterruptControl(uint8_t Copy_u8Control)
{
	uint8_t Local_u8StateError = 1;

	if(Copy_u8Control == RX_INT_ENABLE)
	{
		SET_BIT(UCSRB,RXCIE);
	}
	else if (Copy_u8Control == RX_INT_DISABLE)
	{
		CLR_BIT(UCSRB,RXCIE);
	}
	else
	{
		Local_u8StateError = 0;
	}

	return Local_u8StateError;
}
void USART_voidSetRxCallBackFunc(void (*Copy_pvCallBackFunc)(void))
{
	if (Copy_pvCallBackFunc != NULL)
	{
		g_ptrToFunOVF = Copy_pvCallBackFunc;
	}
}
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
		if(g_ptrToFunOVF!=NULL){
			g_ptrToFunOVF();}
}
