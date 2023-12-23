/*
 * TMR3_private.h
 *
 *  Created on: Nov 18, 2023
 *      Author: MERNA
 */

#ifndef TMR3_PRIVATE_H_
#define TMR3_PRIVATE_H_

#define TMR3_BASE_ADDRESS			0x40000400


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
	volatile uint32 reserved1;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 reserved2;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}TMR3_type;

#define TMR3		((TMR3_type*)TMR3_BASE_ADDRESS)

#endif /* TMR3_PRIVATE_H_ */
