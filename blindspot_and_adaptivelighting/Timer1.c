#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"

#include "Timer1_Cfg.h"
#include "Timer1_Private.h"
#include "Timer1_Interface.h"


void T1_voidInit(void)
{
	//SetMode
	#if T1_MODE == T1_FastPWM_M14
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#endif
		#if		T1_PWM_Mode == T1_PWM_NONINVERTING
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
	#endif
}
void T1_voidStart(void)
{
	#if		T1_PRESCALER == T1_PRESCALER_1
		T1.TCCR1B.Bits.CS10_Bit	= HIGH;
		T1.TCCR1B.Bits.CS11_Bit	= LOW;
		T1.TCCR1B.Bits.CS12_Bit	= LOW;
	#elif	T1_PRESCALER ==	T1_PRESCALER_8
		T1.TCCR1B.Bits.CS10_Bit	= LOW;
		T1.TCCR1B.Bits.CS11_Bit	= HIGH;
		T1.TCCR1B.Bits.CS12_Bit	= LOW;
	#elif	T1_PRESCALER ==	T1_PRESCALER_64
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	#elif	T1_PRESCALER ==	T1_PRESCALER_256
		T1.TCCR1B.Bits.CS10_Bit	= LOW;
		T1.TCCR1B.Bits.CS11_Bit	= LOW;
		T1.TCCR1B.Bits.CS12_Bit	= HIGH;
	#elif	T1_PRESCALER ==	T1_PRESCALER_1024
		T1.TCCR1B.Bits.CS10_Bit	= HIGH;
		T1.TCCR1B.Bits.CS11_Bit	= LOW;
		T1.TCCR1B.Bits.CS12_Bit	= HIGH;
	#endif
	
	
}
void T1_voidStop(void)
{
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
}
void T1_voidSetCompMatchValA(u16 copy_u16CompareMatchVal)
{
	OCR1A = copy_u16CompareMatchVal;
}
void T1_SetDyty_Mode14(f32 copy_f32DytyCycleVal)
{
	#if T1_MODE == T1_FastPWM_M14
		#if		T1_PWM_Mode == T1_PWM_NONINVERTING
			OCR1A = (((copy_f32DytyCycleVal*(ICR1 +1))/100)-1);
		#elif	T1_PWM_Mode == T1_PWM_INVERTING
			copy_f32DytyCycleVal = 100 - copy_f32DytyCycleVal;
			OCR1A = (((copy_f32DytyCycleVal*(ICR1 +1))/100)-1);
		#endif
	#endif
	
	
	
	
}
void T1_SetFreq_Mode14(u16 copy_u16FreqVal)
{
	ICR1 = (((1000000UL/copy_u16FreqVal)/4)-1);
}
