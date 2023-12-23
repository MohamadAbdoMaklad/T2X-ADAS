/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

#define UART1_BASE_ADDRESS			(0x40013800)
#define UART2_BASE_ADDRESS			(0x40004400)

typedef struct
{
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 BRR;
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 CR3;
	volatile uint32 GTPR;
}UART_t;

#define UART1 				((UART_t*)(UART1_BASE_ADDRESS))
#define UART2 				((UART_t*)(UART2_BASE_ADDRESS))


#endif