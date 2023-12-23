/***********************************************
 * Filename:UART1_program.c                    *
 * Description:UART 0 function implementation  *
 * Created on: Nov 16, 2023                    *
 * Author: Zeyad Ossama                        *
 ***********************************************/
#include "LIB_BIT_MATH.h"
#include "UART0_interface.h"
#include "UART0_Register.h"
#include"UART0_Config.h"
#include"UART0_Private.h"
#if UART0_TRASMISSION_MODE==UART0_ASYNC_TRASMISSION_MODE
void (*Transmission_complete_CallBack)(void)=NULL;
#endif
#if UART0_RECEPTION_MODE==UART0_ASYNC_RECEPTION_MODE
void (*Reception_complete_CallBack)(void)=NULL;
#endif
u8 g_u8ReceiveBuffer;
void UART0_init()
{
	//Enable RX and TX
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0);
#if  UART0_BAUDRATE==BAUDRATE_9600
	UBRR0L=103;
#elif UART0_BAUDRATE==BAUDRATE_115200
	UBRR0L=8;

#endif
#if UART0_TRASMISSION_MODE==UART0_ASYNC_TRASMISSION_MODE
    SET_BIT(UCSR0B,TXCIE0);
#endif
#if UART0_RECEPTION_MODE==UART0_ASYNC_RECEPTION_MODE
    SET_BIT(UCSR0B,RXCIE0);
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
void UART0_AsyncSendByte(u8 copyu8Data)
{
	UDR0=copyu8Data;
}
u8 UART0_RecieveByte()
{
	while(!GET_BIT(UCSR0A,RXC0));
	return UDR0;

}
u8 UART0_ReadDataReceived()
{
	return g_u8ReceiveBuffer;
}
#if UART0_TRASMISSION_MODE==UART0_ASYNC_TRASMISSION_MODE
void UART0_SetTransmissionCompleteCallBack(void (*ptrfunc)(void))
{
	if(ptrfunc!=NULL)
	{
		Transmission_complete_CallBack=ptrfunc;
	}
}
#endif
#if UART0_RECEPTION_MODE==UART0_ASYNC_RECEPTION_MODE
void UART0_SetReceptionCompleteCallBack(void (*ptrfunc)(void))
{
	if(ptrfunc!=NULL)
	{
		Reception_complete_CallBack=ptrfunc;
	}
}
#endif
/*
 * Description:ISR for UART0 Transmit complete ISR
 */
void __vector_20(void) __attribute__((signal));
void __vector_20(void)
{
	if(Transmission_complete_CallBack!=NULL)
	{
		(*Transmission_complete_CallBack)();
	}
}
/*
 * Description:ISR for UART0 Receive complete ISR
 */
void __vector_18(void) __attribute__((signal));
void __vector_18(void)
{
		if(Reception_complete_CallBack!=NULL)
		{
			g_u8ReceiveBuffer=UDR0;
			(*Reception_complete_CallBack)();
		}
}

