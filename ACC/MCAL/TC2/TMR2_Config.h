/*****************************************
 * Filename:TMR2_Config.h                 *
 * Description:Timer 2 configurations file*
 * Created on: Nov 16, 2023               *
 * Author: Zeyad Ossama                   *
 ******************************************/

#ifndef MCAL_TIMER2_TMR2_CONFIG_H_
#define MCAL_TIMER2_TMR2_CONFIG_H_

#define TMR2_PRELOAD_VALUE     113
#define TMR2_OVER_FLOW_COUNTER 977
#define TMR2_COMPARE_COUNTER   250
/*
 * 1-TMR2_NORMAL_MODE
 * 2-TMR2_CTC_MODE
 * 3-TMR2_FAST_PWM_MODE
 * 4-TMR2_PHASE_CORRECT_PWM_MODE
 * */
#define TMR2_MODE          TMR2_CTC_MODE
/*
 * 1-TMR2_PRESCALER_1
 * 2-TMR2_PRESCALER_8
 * 3-TMR2_PRESCALER_64
 * 4-TMR2_PRESCALER_256
 * 5-TMR2_PRESCALER_1024
 * 6-TMR2_EXTERNAL_CLOCK_FALLING
 * */
#define TMR2_PRESCALER     TMR2_EXTERNAL_CLOCK_FALLING
/*
 * 1-TMR2_PWM_NON_INVERTING
 * 2-TMR2_PWM_INVERTING
*/
#define TMR2_PWM_MODE      TMR2_PWM_NON_INVERTING


#endif /* MCAL_TIMER0_TMR2_CONFIG_H_ */
