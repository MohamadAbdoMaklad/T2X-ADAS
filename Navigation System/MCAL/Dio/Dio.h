/*
 * Dio.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

typedef enum Dio_ChannelType{
	PA_0, //MCU Channels(32 Dio Pins)
	PA_1,
	PA_2,
	PA_3,
	PA_4,
	PA_5,
	PA_6,
	PA_7,
	PB_0,
	PB_1,
	PB_2,
	PB_3,
	PB_4,
	PB_5,
	PB_6,
	PB_7,
	PC_0,
	PC_1,
	PC_2,
	PC_3,
	PC_4,
	PC_5,
	PC_6,
	PC_7,
	PD_0,
	PD_1,
	PD_2,
	PD_3,
	PD_4,
	PD_5,
	PD_6,
	PD_7,

}Dio_ChannelType;

typedef enum{
	STD_LOW,
	STD_HIGH
}Dio_LevelType;

typedef enum{
	Dio_PORTA,
	Dio_PORTB,
	Dio_PORTC,
	Dio_PORTD
}Dio_PortType;

typedef enum{
	Dio_Pin0, //pins for each port
	Dio_Pin1,
	Dio_Pin2,
	Dio_Pin3,
	Dio_Pin4,
	Dio_Pin5,
	Dio_Pin6,
	Dio_Pin7,
}Dio_PinType;

typedef enum{
	INPUT,
	OUTPUT
}Dio_DirctionType;


void Dio_SetChannel_Dir(Dio_ChannelType ChannelId, Dio_DirctionType dir);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId);
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);

#endif /* MCAL_DIO_DIO_H_ */
