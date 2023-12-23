/************************************************
 * Filename:UART0_interface.h                   *
 * Description:UART 0 functions declaration     *
 * Created on: Nov 16, 2023                     *
 * Author: Zeyad Ossama                         *
 ************************************************/

#ifndef MCAL_UART0_UART0_H_
#define MCAL_UART0_UART0_H_
#include "LIB_STD.h"
void UART0_init();
void UART0_SendByte(u8 Byte);
u8 UART0_RecieveByte();
u8 UART0_ReadDataReceived();
void UART0_AsyncSendByte(u8 copyu8Data);
#if UART0_TRASMISSION_MODE==UART0_ASYNC_TRASMISSION_MODE
void UART0_SetReceptionCompleteCallBack(void (*ptrfunc)(void));
#endif
#if UART0_TRASMISSION_MODE==UART0_ASYNC_TRASMISSION_MODE
void UART0_SetTransmissionCompleteCallBack(void (*ptrfunc)(void));
#endif

#endif /* MCAL_UART_UART_H_ */
