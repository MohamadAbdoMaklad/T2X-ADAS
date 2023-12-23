/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/* UART1 Configuration */
/* status  (enable or disable) */
#define UART1_STATUS		UART_ENABLE
/* Baud Rate (UART_DIV value) */
#define UART1_BAUD_RATE			(0x341)
/* Parity enable */
#define UART1_PARITY		UART_PARITY_DISABLE
#define UART1_PARITY_MODE	UART_EVEN_PARITY
/* Transmitter Enable */
#define UART1_TX			UART_TX_ENABLE
/* Receiver Enable */
#define UART1_RX			UART_RX_ENABLE
/* number of stop bits */
#define UART1_STOP_BIT		UART_ONE_STOP_BIT
/* data length */
#define UART1_LENGTH		UART_LENGTH_8

#define UART1_INTERRUPT_ENABLE

#define UART1_INT_RX		UART_ENABLE
#define UART1_INT_TX		UART_DISABLE




/* UART2 Configuration*/

/* status  (enable or disable) */
#define UART2_STATUS		UART_DISABLE
/* Baud Rate (UART_DIV value) */
#define UART2_BAUD_RATE			(0x341)
/* Parity enable */
#define UART2_PARITY		UART_PARITY_DISABLE
/* Transmitter Enable */
#define UART2_TX			UART_TX_ENABLE
/* Receiver Enable */
#define UART2_RX			UART_RX_ENABLE
/* number of stop bits */
#define UART2_STOP_BIT		UART_ONE_STOP_BIT
/* data length */
#define UART2_LENGTH		UART_LENGTH_8

//#define UART2_INTERRUPT_ENABLE

#define UART2_INT_RX		UART_DISABLE
#define UART2_INT_TX		UART_DISABLE

#endif
