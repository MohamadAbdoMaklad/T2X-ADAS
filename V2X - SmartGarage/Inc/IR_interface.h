/*
 * IR_interface.h
 *
 *  Created on: Nov 21, 2023
 *      Author: MERNA
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_


#define IR_OBJECT_TRUE					1
#define IR_OBJECT_FALSE					2


uint8 IR_vDetectObject(uint8 Copy_u8Port , uint8 Copy_u8Pin);

uint8 IR_vNumberOfSlots(void);


#endif /* IR_INTERFACE_H_ */
