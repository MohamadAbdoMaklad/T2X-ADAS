
/*
 * main.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Lenovo
 */
#include<util/delay.h>
#include"Std_Types.h"
#include"Bit_Math.h"
#include"MCAL/Dio/Dio.h"
#include"MCAL/UART/uart.h"
#include"HAL/GPS/GPS.h"
#include"HAL/LCD2/lcd.h"

int main()
{

	initializeGPS();
	LCD_init();
	GPS_Data gps_data;
	LCD_goToRowColumn(0,0);
	LCD_displayString("GPS TRACKER!");
	_delay_ms(2000);
	LCD_clearScreen();
	while(1)
	{
        char data = readGPSData();
        Parse_GPS_Data(&data,&gps_data);
		LCD_DisplayString("Lat: ");
    	LCD_displayString(gps_data.latitude);
    	LCD_goToRowColumn(1, 0);
		LCD_DisplayString("Long: ");
       	LCD_displayString(gps_data.longitude);
	}


	return 0;
}
