/************************************************/
/*Author	            : Ahmed Hesham Ahmed 	*/
/*Date		            : 15-11-2023     	    */
/*Version	            : V01					*/
/************************************************/
/*******************(ADC   AtMega128)************/
/************************************************/
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "LIB_STD.h"

void ADC_voidInit(void);                           //ADC initialization

// Synch
u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb);   // Read From ADC Channel

u16 ADC_u16GetADCRegValue (void);

// Conversion in Asynch function (Start convertion Asynch)  (Enabling Interrupt to start Conversion)
void ADC_voidGetDigitalValueAsynch(u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(void));


//LDR Functions
u16 LDR_u16GetDigitalReading(u8 Copy_u8ChannelNb);
u16 LDR_u16GetAnalogReading(u8 Copy_u8ChannelNb); // o/p >> millivolt


#endif /* MCAL_ADC_ADC_H_ */
