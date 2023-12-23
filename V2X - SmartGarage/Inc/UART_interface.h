/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

/************************************************* Macros *************************************************/
/* Uart ID */
#define UART_1					1
#define UART_2					2



/**/
#define UART_ENABLE				1
#define UART_DISABLE			0

/* Uart data length */
#define UART_LENGTH_8			0
#define UART_LENGTH_9			1

/* parity control */
#define UART_PARITY_ENABLE		1
#define UART_PARITY_DISABLE		0

#define UART_EVEN_PARITY		0
#define UART_ODD_PARITY			1

/* Transmitter Enable */
#define UART_TX_ENABLE			1
#define UART_TX_DISABLE			0

/* Receiver Enable */
#define UART_RX_ENABLE			1
#define UART_RX_DISABLE			0

/* stop bits number */
#define UART_ONE_STOP_BIT			0b00
#define UART_HALF_STOP_BIT			0b01
#define UART_TWO_STOP_BIT			0b10
#define UART_ONE_HALF_STOP_BIT		0b11


/* UART Registers */
/* USART_SR Register */
#define UART_SR_PE				0  // Parity error
#define UART_SR_FE				1  // Framing Error
#define UART_SR_NE				2  // Noise Error flag
#define UART_SR_ORE				3  // Overrun error
#define UART_SR_IDLE			4  // IDLE line detected
#define UART_SR_RXNE			5  // Read data register not empty
#define UART_SR_TC				6  // Transmission complete
#define UART_SR_TXE				7  // Transmit data register empty
#define UART_SR_LBD				8  // LIN break detection flag
#define UART_SR_CTS				9  // CTS flag


/* USART_CR1 Register */
#define UART_CR1_SBK			0   // Send break
#define UART_CR1_RWU			1   // Receiver wakeup
#define UART_CR1_RE				2   // Receiver enable
#define UART_CR1_TE				3   // Transmitter enable
#define UART_CR1_IDLEIE			4   // IDLE interrupt enable
#define UART_CR1_RXNEIE			5   // RXNE interrupt enable
#define UART_CR1_TCIE			6   // Transmission complete interrupt enable
#define UART_CR1_TXEIE			7   // TXE interrupt enable
#define UART_CR1_PEIE			8   // PE interrupt enable
#define UART_CR1_PS				9   // Parity selection
#define UART_CR1_PCE			10  // Parity control enable
#define UART_CR1_WAKE			11  // Wakeup method
#define UART_CR1_M				12  // Word length
#define UART_CR1_UE				13  // USART enable


/* USART_CR2 Register */
//#define UART_CR2_ADD			0
//#define UART_CR2_LBDL			5  // lin break detection length
//#define UART_CR2_LBDIE		6  // LIN break detection interrupt enable
//#define UART_CR2_LBCL			8  // Last bit clock pulse
//#define UART_CR2_CPHA			9  // Clock phase
//#define UART_CR2_CPOL			10 // Clock polarity
#define UART_CR2_CLKEN			11 // Clock enable
#define UART_CR2_STOP			12 // STOP bits
#define UART_CR2_LINEN			14 // LIN mode enable

#define UART1_NVIC				37
#define UART2_NVIC				38


/************************************************ Prototypes ***********************************************/
/*
FUNCTION NAME        : UART_vInit
FUNCTION DESCRIPTION : initializes the enables UARTs by setting the configuration and control registers
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void UART_vInit(void);

/*
FUNCTION NAME        : UART_vSendData
FUNCTION DESCRIPTION : sends a character through Uart to the target
FUNCTION INPUTS      : Copy_u8UartID: selected UART , Copy_u8Data: ascii of the character
FUNCTION RETURN      : void
*/
void UART_vSendData(uint8 Copy_u8UartID , uint8 Copy_u8Data);

/*
FUNCTION NAME        : UART_vSendString
FUNCTION DESCRIPTION : sends a string through Uart to the target
FUNCTION INPUTS      : Copy_u8UartID: selected UART , Copy_u8String: pointer to string to be sent
FUNCTION RETURN      : void
*/
void UART_vSendString(uint8 Copy_u8UartID , uint8 *Copy_u8String);

/*
FUNCTION NAME        : UART_u8ReceiveData
FUNCTION DESCRIPTION : receives a character from the target
FUNCTION INPUTS      : Copy_u8UartID: selected UART
FUNCTION RETURN      : returns the received character
*/

void UART_vSendNumber(uint16 Copy_u16Number);


uint8 UART_u8ReceiveData(uint8 Copy_u8UartID);

uint8 UART_u8ReturnData(uint8 Copy_u8UartID);

void UART_SetCallBack(uint8 Copy_u8UartID , void (*ptr_function)(uint8));

#endif
