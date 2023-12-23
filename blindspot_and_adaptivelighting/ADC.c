/************************************************/
/*Author	            : Ahmed Hesham Ahmed 	*/
/*Date		            : 15-11-2023     	    */
/*Version	            : V01					*/
/************************************************/
/*******************(ADC   AtMega128)************/
/************************************************/

#include "ADC.h"
#include "LIB_BIT_MATH.h"

#include "ADC.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"
#include "ADC_Reg.h"

//Global Pointers
u8 ADC_u8BusyState = IDLE;

static void (*ADC_pfNotification)(void)= NULL;
static u8 ADC_u8BusyFlag =0;        //static not to change any file to change  this variable


void ADC_voidInit(void){

	// Select Voltage Reference

#if Voltage_Reference == AREF
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
	CLEAR_BIT(ADMUX,ADMUX_REFS0);

#elif Voltage_Reference == AVCC
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

#elif Voltage_Reference == Internal
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

#endif

// Selecting ADC Adjustment
#if ADC_ADJUST == RIGHT

	CLEAR_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_ADJUST == LEFT

	SET_BIT(ADMUX,ADMUX_ADLAR);

#endif


// Selecting ADC_PreScalar

#if ADC_PreScalar == 2
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 4
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);


#elif ADC_PreScalar == 8
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 16
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 32
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);


#elif ADC_PreScalar == 64
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 128
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);


#endif

    //Disable Free Running Mode
	CLEAR_BIT(ADCSRA,ADCSRA_ADFR);

	//Enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}


u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb){

	// Clear the mux Bits in ADMUX Reg
	ADMUX &= 0b11100000;


	// ADMUX |=(ADMUX_CHANNEL_NUM_MASK);
	ADMUX |=Copy_u8ChannelNb;

	//START CONVERSION
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	//POLLING ON FLAG

	while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

		// CLEAR FLAG
		SET_BIT(ADCSRA,ADCSRA_ADIF);

		//READ ADC VALUE

		u16 res= ADCL ;
		res |= (ADCH << 8) ;  // Reading Both Regs
        //u16 res =ADC_REG;
		return res;

}

void ADC_voidGetDigitalValueAsynch(u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(void)) {

	if (ADC_u8BusyFlag==0 && Copy_pfNotification!= NULL){
	// ADMUX &=(ADMUX_CHANNEL_NUM_MASK);
	ADMUX |=Copy_u8ChannelNb;

	//Set Flag to make ADC is busy

	ADC_u8BusyFlag=1;

	// Update Global Pointer to a function
	ADC_pfNotification=Copy_pfNotification;

	//START CONVERSION
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	//Enable ADC Interrupt
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	}


}

void __vector_21(void)  __attribute__((signal)); /* Attribute signal to protect from the compiler from optimization*/
void __vector_21(void)
{
	if (ADC_pfNotification!= NULL){
		//Clear Busy Flag
		ADC_u8BusyFlag=0;
		//Disable ADC Interrupt
		CLEAR_BIT(ADCSRA,ADCSRA_ADIE);

		// Calling Notification Function
		ADC_pfNotification();


	}
}


u16 ADC_u16GetADCRegValue (void)
{
	return ADC_REG;
}




u16 LDR_u16GetDigitalReading(u8 Copy_u8ChannelNb)
{
	u16 ADC_DigitalReading_LDR ;

	ADC_DigitalReading_LDR = ADC_u16GetDigitalValue(Copy_u8ChannelNb);

	return ADC_DigitalReading_LDR ;

}

u16 LDR_u16GetAnalogReading(u8 Copy_u8ChannelNb) // o/p >> millivolt
{
	u16 ADC_AnalogReading_LDR , ADC_DigitalReading_LDR;

	// output from ADC >> Digital
	ADC_DigitalReading_LDR = ADC_u16GetDigitalValue(Copy_u8ChannelNb);

    // Conversion into Analog voltage in mv
 	ADC_AnalogReading_LDR=((u32)ADC_DigitalReading_LDR * 5000UL)/1024;

	return ADC_AnalogReading_LDR ;
}
