/*
 * uart.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include"../../Bit_Math.h"
#include"../../Std_Types.h"

#define RX_INT_ENABLE	1
#define RX_INT_DISABLE	2

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(void);

void UART_sendByte(const uint8_t data);

uint8_t UART_recieveByte(void);

void UART_sendString(const uint8_t *Str);

void UART_receiveString(uint8_t *Str); // Receive until #


#endif /* MCAL_UART_UART_H_ */
