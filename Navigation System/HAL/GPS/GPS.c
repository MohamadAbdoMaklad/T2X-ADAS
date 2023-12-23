/*
 * GPS.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Lenovo
 */
#include<util/delay.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"../../MCAL/UART/uart.h"
#include"GPS.h"


// Function to send an AT command to the GPS module
void sendATCommand(char* command)
{
    // Iterate through the characters in the command and send them one by one
    for (int i = 0; command[i] != '\0'; i++)
    {
        UART_sendByte(command[i]);
    }
    // Send newline character (optional, depends on the module's requirements)
    UART_sendByte('\r');
    UART_sendByte('\n');
    // Optional delay to allow the module to process the command
    _delay_ms(100);
 }


void initializeGPS()
{
    // Initialize UART with specified baud rate
    UART_init();
    sendATCommand("$GPGGA,1");  // Enable GGA sentence

}

uint8_t readGPSData()
{
	return UART_recieveByte();
}
void Gps_ReadString(char* buffer, uint8_t buffer_size)
{
    uint8_t index = 0;
    char received_char;

    // Read characters until a newline character is encountered
    do {
        received_char = readGPSData();
        buffer[index++] = received_char;
    } while (received_char != '\n' && index < buffer_size);

    // Null-terminate the string
    buffer[index] = '\0';
}
void Parse_GPS_Data(const char *sentence, GPS_Data *gps_data)
{
	   if(strncmp(sentence, "$GPGGA,", 7) == 0){
		   sscanf(sentence, "$GPGGA,%[^,],%[^,]", gps_data->latitude, gps_data->longitude);
	}
}

