/*******************************************
 * Filename:UART0_Config.h                 *
 * Description:UART 0 configuration file   *
 * Created on: Nov 16, 2023                *
 * Author: Zeyad  Ossama                   *
 *******************************************/

#ifndef MCAL_UART0_UART0_CONFIG_H_
#define MCAL_UART0_UART0_CONFIG_H_
/*
 * 1-UART0_ASYNC_TRASMISSION_MODE
 * 2-UART0_SYNC_TRASMISSION_MODE 
 **/
#define UART0_TRASMISSION_MODE   UART0_ASYNC_TRASMISSION_MODE
/*
 * 1-UART0_ASYNC_RECEPTION_MODE
 * 2-UART0_SYNC_RECEPTION_MODE 
 **/
#define UART0_RECEPTION_MODE   UART0_ASYNC_RECEPTION_MODE
/*
 * 1-BAUDRATE_9600
 * 2-BAUDRATE_115200
 * */
#define UART0_BAUDRATE    BAUDRATE_9600
/*
 * 1-EVEN_PARITY
 * 2-ODD_PARTY
 * 3-N0_PARITY
 * */
#define UART0_PARITY       ODD_PARTY
/*
 * 1-ONE_STOPBIT
 * 2-TWO_STOPBIT
 * */
#define UART0_STOP_BIT       ONE_STOPBIT

#endif /* MCAL_UART_UART_CONFIG_H_ */
