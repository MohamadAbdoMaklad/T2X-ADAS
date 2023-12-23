/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H


#define NVIC_BASE_ADDRESS		0xE000E100

/* Interrupt Set Enable Registers */
#define NVIC_ISER0				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x00)))
#define NVIC_ISER1				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x04)))
#define NVIC_ISER2				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x08)))


/* Interrupt Clear Enable Registers */
#define NVIC_ICER0				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x80)))
#define NVIC_ICER1				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x84)))
//#define NVIC_ICER2				*((volatile u32*)(NVIC_BASE_ADDRESS+(0x88)))


/* Interrupt Set Pending Registers */
#define NVIC_ISPR0				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x100)))
#define NVIC_ISPR1				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x104)))
//#define NVIC_ISPR2				*((volatile u32*)(NVIC_BASE_ADDRESS+(0x108)))


/* Interrupt Clear Pending Registers */
#define NVIC_ICPR0				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x180)))
#define NVIC_ICPR1				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x184)))
//#define NVIC_ICPR2				*((volatile u32*)(NVIC_BASE_ADDRESS+(0x188)))


/* Interrupt Active Bit Registers */
#define NVIC_IABR0				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x200)))
#define NVIC_IABR1				*((volatile uint32*)(NVIC_BASE_ADDRESS+(0x204)))
//#define NVIC_IABR2				*((volatile u32*)(NVIC_BASE_ADDRESS+(0x208)))


/* Interrupt Priority Registers */
//a poiter to point to a register according to its number (each is a byte)
#define NVIC_IPR				((volatile uint8*)(NVIC_BASE_ADDRESS+(0x300)))	

/* System Control Block */
#define SCB_BASE_ADDRESS				(0xE000E008)

/* Application interrupt and reset control register */
#define SCB_AIRCR				*((volatile uint32*)(SCB_BASE_ADDRESS+(0x0C)))

#endif