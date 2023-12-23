/*
 * SERVO_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: MERNA
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/************************* Macros *******************************/
#define SERVO_ZERO_SHIFT			1000
#define SERVO_PERIOD				20000

#define SERVO_CLOSE_ANGLE			0
#define SERVO_OPEN_ANGLE			180


/************************ Prototypes *****************************/
void SERVO_vSetAngle(uint8 Copy_u8Angle);


#endif /* SERVO_INTERFACE_H_ */
