/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

#define RCC_u8_HSI		1
#define RCC_u8_HSE		2
#define RCC_u8_PLL		3

#define RCC_u32_BASE_ADDRESS		0x40021000

typedef struct
{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 APB2ENR;
	volatile uint32 APB1ENR;
	volatile uint32 BDCR;
	volatile uint32 CSR;
}RCC_RegDef_t;

#define RCC			((RCC_RegDef_t*)RCC_u32_BASE_ADDRESS)

#endif
