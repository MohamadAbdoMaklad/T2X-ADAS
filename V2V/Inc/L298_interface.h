/*
 * L298_interface.h
 *
 *  Created on: Dec 12, 2023
 *      Author: MERNA
 */

#ifndef L298_INTERFACE_H_
#define L298_INTERFACE_H_

/***************************************** Macros **************************************/
/* Speeds */
#define L298_HIGH_SPEED			1
#define L298_MID_SPEED			2
#define L298_LOW_SPEED			3

/* Directions */
#define L298_CLOCKWISE			1
#define L298_ANTI_CLOCKWISE		2

#define L298_PWM_MAX			2000
#define L298_CRR_HIGH			1999
#define L298_CRR_MID			1000
#define L298_CRR_LOW			500
#define L298_CRR_STOP			1



/*************************************** Prototypes ************************************/
void L298_vInit(uint8 Copy_u8Port, uint8 Copy_u8Pin1, uint8 Copy_u8Pin2, uint8 Copy_u8Dir);

void L298_vCarMove(uint8 Copy_u8Speed);

void L298_vCarPWM(uint16 Copy_u8Comp);

void L298_vCarStop(void);

#endif /* L298_INTERFACE_H_ */
