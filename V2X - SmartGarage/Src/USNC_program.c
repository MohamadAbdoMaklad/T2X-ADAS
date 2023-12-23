/*
 * USNC_program.c
 *
 *  Created on: Dec 11, 2023
 *      Author: MERNA
 */

#include "STD_types.h"

#include "TMR3_interface.h"
#include "USNC_interface.h"


void USNC_vInit(void)
{
	TMR3_vPWMInit(60000, 10 , TMR3_CHANNEL_1);
	TMR3_vCapture(60000, TMR3_RISING_EDGE,TMR3_CHANNEL_2);
}


uint16 USNC_vGetDistance(void)
{
	uint16 LOC_Cap;
	LOC_Cap = TMR3_u32GetCapture()-18400;

	uint16 LOC_Distance = (USNC_SOUND_SPEED*(uint32)(LOC_Cap)/(1000000*2));
	return LOC_Distance;
}
