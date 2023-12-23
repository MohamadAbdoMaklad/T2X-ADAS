/*
 * TMR1_private.h
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_


#define TMR1_BASE_ADDRESS			0x40012C00


typedef struct{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMCR;
	volatile uint32 DIER;
	volatile uint32 SR;
	volatile uint32 EGR;
	volatile uint32 CCMR1;
	volatile uint32 CCMR2;
	volatile uint32 CCER;
	volatile uint32 CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
	volatile uint32 RCR;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 BDTR;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}TMR1_type;

#define TMR1		((TMR1_type*)TMR1_BASE_ADDRESS)


#endif /* TMR1_PRIVATE_H_ */
