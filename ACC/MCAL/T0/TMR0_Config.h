/*****************************************
 * Filename:TMR0_Config.h                 *
 * Description:Timer 0 configurations file  *
 * Created on: Nov 16, 2023               *
 * Author: Zeyad Ossama                   *
 ******************************************/

#ifndef MCAL_TIMER0_TMR0_CONFIG_H_
#define MCAL_TIMER0_TMR0_CONFIG_H_

#define TMRO_PRELOAD_VALUE     113
#define TMR0_OVER_FLOW_COUNTER 977
#define TMR0_COMPARE_COUNTER   250
/*
 * 1-TMR0_NORMAL_MODE
 * 2-TMR0_CTC_MODE
 * 3-TMR0_FAST_PWM_MODE
 * 4-TMR0_PHASE_CORRECT_PWM_MODE
 * */
#define TMR0_MODE          TMR0_FAST_PWM_MODE
/*
 * 1-TMR0_PRESCALER_1
 * 2-TMR0_PRESCALER_8
 * 3-TMR0_PRESCALER_64
 * 4-TMR0_PRESCALER_256
 * 5-TMR0_PRESCALER_1024
 * */
#define TMR0_PRESCALER     TMR0_PRESCALER_64
/*
 * 1-TMR0_PWM_NON_INVERTING
 * 2-TMR0_PWM_INVERTING
*/
#define TMR0_PWM_MODE      TMR0_PWM_NON_INVERTING


#endif /* MCAL_TIMER0_TMR0_CONFIG_H_ */
