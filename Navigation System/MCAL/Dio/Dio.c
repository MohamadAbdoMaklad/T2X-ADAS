/*
 * Dio.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */
#include"Dio.h"
#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include<avr/io.h>

void Dio_SetChannel_Dir(Dio_ChannelType ChannelId, Dio_DirctionType dir)
{
	Dio_PortType port=ChannelId/8;
	switch(port)
	{
	case 0:
		if(dir==INPUT)
		{
			CLR_BIT(DDRA,ChannelId);
		}
		else
		{
			SET_BIT(DDRA,ChannelId);
		}
		break;
	case 1:
		if(dir==INPUT)
		{
			CLR_BIT(DDRB,ChannelId%8);
		}
		else
		{
			SET_BIT(DDRB,ChannelId%8);
		}
		break;
	case 2:
		if(dir==INPUT)
		{
			CLR_BIT(DDRC,ChannelId%8);
		}
		else
		{
			SET_BIT(DDRC,ChannelId%8);
		}
		break;
	case 3:
		if(dir==INPUT)
		{
			CLR_BIT(DDRD,ChannelId%8);
		}
		else
		{
			SET_BIT(DDRD,ChannelId%8);
		}
		break;
	}
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	Dio_PortType port=ChannelId/8;
	switch(port)
	{
	case Dio_PORTA:
		if(Level==STD_HIGH)
			SET_BIT(PORTA,ChannelId);
		else
			CLR_BIT(PORTA,ChannelId);
		break;
	case Dio_PORTB:
		if(Level==STD_HIGH)
			SET_BIT(PORTB,ChannelId%8);
		else
			CLR_BIT(PORTB,ChannelId%8);
		break;
	case Dio_PORTC:
		if(Level==STD_HIGH)
			SET_BIT(PORTC,ChannelId%8);
		else
			CLR_BIT(PORTC,ChannelId%8);
		break;
	case Dio_PORTD:
		if(Level==STD_HIGH)
			SET_BIT(PORTD,ChannelId%8);
		else
			CLR_BIT(PORTD,ChannelId%8);
		break;


	}
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_PortType port=ChannelId/8;
	Dio_LevelType level =STD_LOW;
	switch(port)
	{
	case Dio_PORTA:
		level =(GET_BIT(PINA,ChannelId));
		break;
	case Dio_PORTB:
		level =(GET_BIT(PINB,ChannelId%8));
		break;
	case Dio_PORTC:
		level =(GET_BIT(PINC,ChannelId%8));
		break;
	case Dio_PORTD:
		level = (GET_BIT(PIND,ChannelId%8));
		break;
	}
	return level;
}
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	Dio_PortType port=ChannelId/8;
	Dio_LevelType level =STD_LOW;
	switch(port)
	{
	case Dio_PORTA:
		level =(TGL_BIT(PORTA,ChannelId));
		break;
	case Dio_PORTB:
		level =(TGL_BIT(PORTB,ChannelId%8));
		break;
	case Dio_PORTC:
		level =(TGL_BIT(PORTC,ChannelId%8));
		break;
	case Dio_PORTD:
		level = (TGL_BIT(PORTD,ChannelId%8));
		break;
	}
	return level;
}

