/*
 * TMR3_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#ifndef TMR3_INTERFACE_H_
#define TMR3_INTERFACE_H_

#define TMR3_RISING_EDGE			1
#define TMR3_FALLING_EDGE			2


#define TMR3_CHANNEL_1			1
#define TMR3_CHANNEL_2			2
#define TMR3_CHANNEL_3			3
#define TMR3_CHANNEL_4			4


void TMR3_vStartTimerMicros(uint32 Copy_u32Delay);

void TMR3_vDelayMicros(uint32 Copy_u32Delay);

void TMR3_vDelayMillis(uint32 Copy_u32Delay);

void TMR3_vPWMInit(uint32 Copy_u32ARR , uint32 Copy_u32Compare,uint8 Copy_u8Channel);

void TMR3_vCapture(uint32 Copy_u32ARR , uint8 Copy_u8Edge ,uint8 Copy_u8Channel);

uint32 TMR3_u32GetCapture(void);

void TMR3_vWaitFlag(void);

#endif /* TMR3_INTERFACE_H_ */
