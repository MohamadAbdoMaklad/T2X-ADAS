/************************************************/
/*Author	            : Ahmed Hesham Ahmed 	*/
/*Date		            : 15-11-2023     	    */
/*Version	            : V01					*/
/************************************************/
/*******************(ADC   AtMega128)************/
/************************************************/
#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

// ADC Multiplexer Selection Register � ADMUX
#define ADMUX  *((volatile u8*)0x27)

#define ADMUX_REFS1 7
#define ADMUX_REFS0 6
#define ADMUX_ADLAR 5


// ADC Control and Status Register A � ADCSRA
#define ADCSRA *((volatile u8*)0x26)

#define ADCSRA_ADEN  7
#define ADCSRA_ADSC  6
#define ADCSRA_ADFR  5
#define ADCSRA_ADIF  4
#define ADCSRA_ADIE  3
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0


#define ADCL   *((volatile u8*)0x24)
#define ADCH   *((volatile u8*)0x25)

#define ADC_REG  *((volatile u16*)0x24)
#define SREG (*(volatile uint8_t *)((0x3F) + 0x20))

#endif /* MCAL_ADC_ADC_REG_H_ */
