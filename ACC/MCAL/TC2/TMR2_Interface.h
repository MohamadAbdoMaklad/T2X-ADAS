/**********************************************
 * Filename:TMR2_Interface.h                  *
 * Description:Timer2 functions declarations  *
 * Created on: Nov 16, 2023                   *
 * Author: Zeyad Ossama                       *
 **********************************************/


#ifndef MCAL_TIMER2_TMR2_INTERFACE_H_
#define MCAL_TIMER2_TMR2_INTERFACE_H_
#include "LIB_STD.h"
void TMR2_voidInit();
void TMR2_voidStart();
void TMR2_voidStop();
void TMR2_voidSetCallBackOVF(void (*ptrfun)(void));
void TMR2_voidSetCallBackCTC(void (*ptrfun)(void));
void TMR2_voidSetCompareMatchvalue(u8 copy_u8CompareValue);
void TMR2_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);
void TMR2_voidSetDutycycle(u8 copy_u8Duty);


#endif /* MCAL_TIMER2_TMR2_INTERFACE_H_ */
