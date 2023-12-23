/******************************************
 * Filename:TMR2_Register.h               *
 * Description: Timer 2 Register file     *
 * Created on: Nov 16, 2023               *
 * Author: Zeyad Ossama                   *
 *****************************************/

#ifndef MCAL_TIMER2_TMR2_REGISTER_H_
#define MCAL_TIMER2_TMR2_REGISTER_H_
#include "LIB_STD.h"

/*Timer/Counter 2 control register*/

#define TCCR2  (*(u8 *)(0x45))
#define CS20   0
#define CS21   1
#define CS22   2
#define WGM21  3
#define COM20  4
#define COM21  5
#define WGM20  6
#define FOC2   7

/*Timer/Counter 2  register*/

#define TCNT2  (*(volatile u8 *)(0x44))

/*Output Compare Register*/

#define OCR2   (*(volatile u8 *)(0x43))

/*Timer/Counter Interrupt Mask Register*/

#define TIMSK   (*(volatile u8 *)(0x57))
#define TOIE2   6
#define OCIE2   7

/*Timer/Counter Interrupt Flag Register*/
#define TIFR    (*(volatile const  u8 *)(0x56))
#define TOV2    6
#define OCF2    7

#endif /* MCAL_TIMER2_TMR2_REGISTER_H_ */
