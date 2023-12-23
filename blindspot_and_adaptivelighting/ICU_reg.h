/* HEADER FILE FOR INPUT CAPTURE UNIT REGISTERS
 *
 *  [FILE NANE] :ICU_reg.h
 *
 *  Created on 15/11/2023
 *
 *  Author: ZIAD ESMAIL
 */
#ifndef ICU_REG_H_
#define ICU_REG_H_

#include "LIB_STD.h"

#define TCCR3A (*(volatile u8 *)(0x8B))
#define TCCR3B (*(volatile u8 *)(0x8A))
#define ETIFR (*(volatile u8 *)(0x7C))
#define ETIMSK (*(volatile u8 *)(0x7D))
#define ICR3 (*(volatile u16 *)(0x80))
#define TCNT3 (*(volatile u16 *)(0x88))
#define DDRE (*(volatile u8 *)((0x02) + 0x20))
#define SREG (*(volatile uint8_t *)((0x3F) + 0x20))

#define ICES3 6
#define TICIE3 5
#define  ICF3 5


#endif /* ICU_REG_H_ */
