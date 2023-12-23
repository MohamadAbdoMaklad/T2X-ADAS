/*  ULTRASONIC DRIVER HEADE FILE
 *
 *  [FILE NANE] :ultrasonic.h
 *
 *  Created on 15/11/2023
 *
 *  Author: ZIAD ESMAIL
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "LIB_STD.h"


/*
 * Description : Initialize the Ultra_sonic driver
 * 1- set the Trigger pin as output pin
 * 2- Initialize the ICU driver and Its Call back function.
 */
void Ultrasonic_init(void);
/*
 * Description :Function calculates the distance measured by the Ultra_sonic
 * 1- Trigger the Ultra_sonic by call Ultrasonic_Trigger function
 * 2. Calculate the distance in Centimeter and returns its value (uint16)
 */
u16 Ultrasonic_1_readDistance(void);
u16 Ultrasonic_2_readDistance(void);




#endif /* ULTRASONIC_H_ */
