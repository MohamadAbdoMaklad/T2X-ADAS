/******************************************
 * Filename:TMR0_Register.h               *
 * Description: Timer 0 Register file     *
 * Created on: Nov 16, 2023               *
 * Author: Zeyad Ossama                   *
 *****************************************/

#ifndef MCAL_TIMER0_TMR0_REGISTER_H_
#define MCAL_TIMER0_TMR0_REGISTER_H_
#include"LIB_STD.h"

/*Timer/Counter 0 control register*/

#define TCCR0  (*(u8 *)(0x53))
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7

/*Timer/Counter 0  register*/

#define TCNT0  (*(volatile u8 *)(0x52))

/*Output Compare Register*/

#define OCR0   (*(volatile u8 *)(0x51))

/*Timer/Counter Interrupt Mask Register*/

#define TIMSK   (*(volatile u8 *)(0x57))
#define TOIE0   0
#define OCIE0   1

/*Timer/Counter Interrupt Flag Register*/
#define TIFR    (*(volatile const  u8 *)(0x56))
#define TOV0    0
#define OCF0    1

#endif /* MCAL_TIMER0_TMR0_REGISTER_H_ */
