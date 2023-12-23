/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

/******************************************** Macros **************************************************************/





/******************************************** Prototypes **********************************************************/
/*
FUNCTION NAME        : 
FUNCTION DESCRIPTION :
FUNCTION INPUT       :
FUNCTION RETURN      :
*/
void NVIC_vEnableInterrupt(uint8 Copy_u8InterruptNum);

/*
FUNCTION NAME        : 
FUNCTION DESCRIPTION :
FUNCTION INPUT       :
FUNCTION RETURN      :
*/
void NVIC_vDisableInterrupt(uint8 Copy_u8InterruptNum);

/*
FUNCTION NAME        : 
FUNCTION DESCRIPTION :
FUNCTION INPUT       :
FUNCTION RETURN      :
*/
void NVIC_vSetPendingInterrupt(uint8 Copy_u8InterruptNum);
/*
FUNCTION NAME        :
FUNCTION DESCRIPTION :
FUNCTION INPUT       :
FUNCTION RETURN      :
*/
void NVIC_vClearPendingInterrupt(uint8 Copy_u8InterruptNum);

/*
FUNCTION NAME        : 
FUNCTION DESCRIPTION :
FUNCTION INPUT       :
FUNCTION RETURN      :
*/
uint8 NVIC_vGetActive(uint8 Copy_u8InterruptNum);

/*
FUNCTION NAME        : 
FUNCTION DESCRIPTION :
FUNCTION INPUT       :
FUNCTION RETURN      :
*/

#endif
