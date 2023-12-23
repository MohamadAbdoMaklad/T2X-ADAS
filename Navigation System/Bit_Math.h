/*
 * Bit_Math.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SET_BIT(reg,bit_n) reg|=(1<<bit_n)
#define CLR_BIT(reg,bit_n) reg&=~(1<<bit_n)
#define TGL_BIT(reg,bit_n) reg^=(1<<bit_n)
#define GET_BIT(reg,bit_n) ((((reg)>>(bit_n))&0x01))
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

#endif /* BIT_MATH_H_ */
