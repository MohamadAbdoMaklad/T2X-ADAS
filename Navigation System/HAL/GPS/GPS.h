/*
 * GPS.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Lenovo
 */

#ifndef HAL_GPS_GPS_H_
#define HAL_GPS_GPS_H_


typedef struct {
    char latitude[10];
    char longitude[10];

} GPS_Data;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void initializeGPS();
void sendATCommand(char* command);
uint8_t readGPSData();
void Parse_GPS_Data(const char *sentence, GPS_Data *gps_data);

#endif /* HAL_GPS_GPS_H_ */
