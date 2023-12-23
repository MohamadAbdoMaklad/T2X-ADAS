/***********************************************
 * Filename:UART1_Register.h                   *
 * Description:UART 0 Register file            *
 * Created on: Nov 16, 2023                    *
 * Author: Zeyad Ossama                        *
 ***********************************************/

#ifndef MCAL_UART0_UART0_REGISTER_H_
#define MCAL_UART0_UART0_REGISTER_H_
#include"LIB_STD.h"
/*USART Control and Status Register A*/
#define UCSR0A  (*((volatile u8 *)(0x2B)))

#define MPCM0    0
#define U2X0     1
#define UPE0     2
#define DOR0     3
#define FE0      4
#define UDRE0    5
#define TXC0     6
#define RXC0     7

/*USART Control and Status Register B*/
#define UCSR0B  (*((volatile u8 *)(0x2A)))

#define TXB80       0
#define RXB80       1
#define UCSZ02      2
#define TXEN0       3
#define RXEN0       4
#define UDRIE0      5
#define TXCIE0      6
#define RXCIE0      7
/*USART Control and Status Register C*/
#define UCSR0C  (*((volatile u8 *)(0x95)))

#define UCPOL0      0
#define UCSZ00      1
#define UCSZ01      2
#define USBS0       3
#define UMP00       4
#define UMP01       5
#define UMSEL0      6

/*USART Baud Rate Registers*/
#define UBRR0H (*((volatile u8 *)(0x90)))
#define UBRR0L  (*((volatile u8 *)(0x29)))

/*USART I/O Data Register*/

#define UDR0    (*(volatile u8 *)(0x2C))


#endif /* MCAL_UART_UART_REGISTER_H_ */
