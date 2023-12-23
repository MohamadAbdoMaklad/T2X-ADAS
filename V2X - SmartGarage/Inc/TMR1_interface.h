/*
 * TMR1_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_

#define TMR1_CHANNEL_1			1
#define TMR1_CHANNEL_2			2
#define TMR1_CHANNEL_3			3
#define TMR1_CHANNEL_4			4

void TMR1_vStartTimerMicros(uint32 Copy_u32Delay);

void TMR1_vDelayMicros(uint32 Copy_u32Delay);

void TMR1_vDelayMillis(uint32 Copy_u32Delay);

void TMR1_vPWMInit(uint32 Copy_u32ARR , uint32 Copy_u32Compare,uint8 Copy_u8Channel);

#endif /* TMR1_INTERFACE_H_ */
