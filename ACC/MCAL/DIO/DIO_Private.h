/************************************************************************************************************/
/*Author	            : Mohamad Abdo Maklad	 ************************************************************/
/*Date		            : 15-11-2023			 ************************************************************/
/*Last Modification		: 15-11-2023			 ************************************************************/
/*Version	            : V01				   	 ************************************************************/
/************************************************************************************************************/
/*Controller			: ATMEGA128				 ************************************************************/
/*SWC					: DIO					 ************************************************************/
/************************************************************************************************************/
/****************(DIO_Private.h)*****************************************************************************/
/************************************************************************************************************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"

typedef struct
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 PORT;
}Port_t;
typedef struct
{
	volatile u8 PIN;
	volatile u8 Reserved[64];
	volatile u8 DDR;
	volatile u8 PORT;
}PortFExp_t;

#define _DIOA_ (*(volatile Port_t*)		0x39)
#define _DIOB_ (*(volatile Port_t*)		0x36)
#define _DIOC_ (*(volatile Port_t*)		0x33)
#define _DIOD_ (*(volatile Port_t*)		0x30)
#define _DIOE_ (*(volatile Port_t*)		0x21)
#define _DIOF_ (*(volatile PortFExp_t*)	0x20)
#define _DIOG_ (*(volatile Port_t*)		0x63)

#endif /* DIO_PRIVATE_H_ */