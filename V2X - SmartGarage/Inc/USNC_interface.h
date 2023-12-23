/*
 * USNC_interface.h
 *
 *  Created on: Dec 11, 2023
 *      Author: MERNA
 */

#ifndef USNC_INTERFACE_H_
#define USNC_INTERFACE_H_

#define USNC_SOUND_SPEED			34400
#define USNC_MAX_PERIOD				60000
#define USNC_TRIGGER_PERIOD			50
#define USND_START_TIME				18400


void USNC_vInit(void);

uint16 USNC_vGetDistance(void);

#endif /* USNC_INTERFACE_H_ */
