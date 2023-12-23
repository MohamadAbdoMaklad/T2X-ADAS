/***********************************************
 * Filename:UART1_program.c                    *
 * Description:UART 0 function implementation  *
 * Created on: Nov 16, 2023                    *
 * Author: Zeyad Ossama                        *
 ***********************************************/
#include"LIB_BIT_MATH.h"
#include "UART0_interface.h"
#include "UART0_Register.h"
#include"UART0_Config.h"
#include"UART0_Private.h"
void UART0_init()
{
	//Enable RX and TX
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0);
#if  UART0_BAUDRATE==BAUDRATE_9600
	UBRR0L=103;
#elif UART0_BAUDRATE==BAUDRATE_115200
	UBRR0L=8;

#endif

#if UART0_PARITY==EVEN_PARITY
	SET_BIT(UCSR0C,UMP01);
	CLEAR_BIT(UCSR0C,UMP00);
#elif UART0_PARITY==ODD_PARTY
	SET_BIT(UCSR0C,UMP01);
	SET_BIT(UCSR0C,UMP00);
#elif UART0_PARITY==NO_PARITY
	CLEAR_BIT(UCSR0C,UMP01);
	CLEAR_BIT(UCSR0C,UMP00);
#endif
#if   UART0_STOP_BIT==ONE_STOPBIT
	CLEAR_BIT(UCSR0C,USBS0);
#elif UART0_STOP_BIT==TWO_STOPBIT
	SET_BIT(UCSR0C,USBS0);
#endif
	/*8 BIT mode*/
	SET_BIT(UCSR0C,UCSZ00);
	SET_BIT(UCSR0C,UCSZ01);
}
void UART0_SendByte(u8 copyu8Data)
{
	while(!GET_BIT(UCSR0A,UDRE0));
	UDR0=copyu8Data;

}
u8 UART0_RecieveByte()
{
	while(!GET_BIT(UCSR0A,RXC0));
	return UDR0;

}


