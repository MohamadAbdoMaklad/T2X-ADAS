/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _GPIO_PRIVATE
#define _GPIO_PRIVATE


#define GPIOA_BASE_ADDRESS			0x40010800
#define GPIOB_BASE_ADDRESS			0x40010C00
#define GPIOC_BASE_ADDRESS      	0x40011000


typedef struct 
{
	volatile uint32 CRL;	//CONFIGURATION RGISTER LOW
	volatile uint32 CRH;	//CONFIGURATION RGISTER HIGH
	volatile uint32 IDR;	//INPUT DATA REGISTER
	volatile uint32 ODR;	//OUTPUT DATA REGISTER
	volatile uint32 BSRR;	//BIT SET/RESET REGISTER
	volatile uint32 BRR;	//BIT RESET REGISTER
	volatile uint32 LCKR;	//port configuration LOCK REGISTER
}GPIO_RegDef_t;



#define GPIOA		((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB		((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC		((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)



#endif
