/**********************************************
 * Filename:TMR0_Interface.h                  *
 * Description:Timer0 functions declarations  *
 * Created on: Nov 16, 2023                   *
 * Author: Zeyad Ossama                       *
 **********************************************/

#ifndef MCAL_TIMER0_TMR0_INTERFACE_H_
#define MCAL_TIMER0_TMR0_INTERFACE_H_
#include"LIB_STD.h"
void TMR0_voidInit();
void TMR0_voidStart();
void TMR0_voidStop();
void TMR0_voidSetCallBackOVF(void (*ptrfun)(void));
void TMR0_voidSetCallBackCTC(void (*ptrfun)(void));
void TMR0_voidSetCompareMatchvalue(u8 copy_u8CompareValue);
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);
void TMR0_voidSetDutycycle(u8 copy_u8Duty);


#endif /* MCAL_TIMER0_TMR0_INTERFACE_H_ */
