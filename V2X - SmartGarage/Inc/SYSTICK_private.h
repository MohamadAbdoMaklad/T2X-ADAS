/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _SYSTICK_PRIVATE_H
#define _SYSTICK_PRIVATE_H


#define SYSTICK_BASE_ADDRESS		(0xE000E010)

typedef struct
{
	volatile uint32 CTRL;
	volatile uint32 LOAD;
	volatile uint32 VAL;
	volatile uint32 CALIB;
	
}STK_t;


#define STK 		((STK_t*)(SYSTICK_BASE_ADDRESS))




#endif
