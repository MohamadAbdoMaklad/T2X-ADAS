/************************************************/
/*Author	            : Ahmed Hesham Ahmed 	*/
/*Date		            : 15-11-2023     	    */
/*Version	            : V01					*/
/************************************************/
/*******************(ADC   AtMega128)************/
/************************************************/
#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_


/*  Voltage Reference Selection :
 *
 * 1-AREF
 * 2-AVCC (External Capcitaor)
 * 3-Internal 2.56 V Voltage Reference
 *
 */
#define Voltage_Reference  AVCC

/*  ADC PRESCALAR
 *  From 2 , 4 , 8 , 16 , 32 , 64 , 128
 */

#define ADC_PreScalar 128


#define ADC_ADJUST RIGHT



#endif /* MCAL_ADC_ADC_CFG_H_ */
