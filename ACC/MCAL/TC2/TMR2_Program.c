/**********************************************
 * Filename:TMR2_Program.c                     *
 * Description:Timer 2 Function implementation  *
 * Created on: Nov 16, 2023                    *
 * Author: Zeyad Ossama                        *
 ***********************************************/
#include "LIB_BIT_MATH.h"
#include "TMR2_Config.h"
#include "TMR2_Interface.h"
#include "TMR2_Private.h"
#include "TMR2_Register.h"
static void (*CallbackFunOVF)(void)=NULL;
static void (*CallbackFunCTC)(void)=NULL;

static volatile u16 CTC_Counter=0;
/*
 *Description:Function that initialize timer mode of operation
 */
void TMR2_voidInit()
{
#if TMR2_MODE==TMR2_NORMAL_MODE
	//Select mode normal mode
	CLEAR_BIT(TCCR2,WGM20);
	CLEAR_BIT(TCCR2,WGM21);
	//Enable Interrupt
	SET_BIT(TIMSK,TOIE2);
	//Preload value
	TCNT2=TMR2_PRELOAD_VALUE;

#elif TMR2_MODE==TMR2_CTC_MODE
	//Select mode CTC mode
	CLEAR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	//Enable Interrupt
	SET_BIT(TIMSK,OCIE2);

#elif TMR2_MODE==TMR2_FAST_PWM_MODE
	//Select mode FAST_PWM_MODE
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	//Select non-Inverting PWM
#if TMR2_PWM_MODE==TMR2_PWM_NON_INVERTING
	SET_BIT(TCCR2,COM21);
	CLEAR_BIT(TCCR2,COM20);
	//Select Inverting PWM
#elif TMR2_PWM_MODE==TMR2_PWM_INVERTING
	SET_BIT(TCCR2,COM21);
	SET_BIT(TCCR2,COM20);
#endif

#elif TMR2_MODE==TMR2_PHASE_CORRECT_PWM_MODE
	//Select mode Phase Correct_PWM_MODE
	SET_BIT(TCCR2,WGM20);
	CLEAR_BIT(TCCR2,WGM21);
	//Select non-Inverting PWM
#if TMR2_PWM_MODE==TMR2_PWM_NON_INVERTING
	SET_BIT(TCCR2,COM21);
	CLEAR_BIT(TCCR2,COM20);
	//Select Inverting PWM
#elif TMR2_PWM_MODE==TMR2_PWM_INVERTING
	SET_BIT(TCCR2,COM21);
	SET_BIT(TCCR2,COM20);
#endif



#endif
}
/*
 * Description:Function starts timer by setting Prescaler value
 * */
void TMR2_voidStart()
{
#if   TMR2_PRESCALER==TMR2_PRESCALER_1
	SET_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
#elif TMR2_PRESCALER==TMR2_PRESCALER_8
	CLEAR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
#elif TMR2_PRESCALER==TMR2_PRESCALER_64
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
#elif TMR2_PRESCALER==TMR2_PRESCALER_256
	CLEAR_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
#elif TMR2_PRESCALER==TMR2_PRESCALER_1024
	SET_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
#elif TMR2_PRESCALER==TMR2_EXTERNAL_CLOCK_FALLING
	CLEAR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#endif
}
/*
 * Description:Function stops timer by setting Prescaler value to zero
 * */
void TMR2_voidStop()
{
	CLEAR_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);

}
/*
 * Description:Function that set Callback function for Normal mode
 */
void TMR2_voidSetCallBackOVF(void (*ptrfun)(void))
{
	if(ptrfun!=NULL)
	{
		CallbackFunOVF=ptrfun;
	}
}
/*
 * Description:Function that set Callback function for CTC mode
 */
void TMR2_voidSetCallBackCTC(void (*ptrfun)(void))
{
	if(ptrfun!=NULL)
	{
		CallbackFunCTC=ptrfun;
	}
}
/*
 * Description:Function that set Compare match register value
 */
void TMR2_voidSetCompareMatchvalue(u8 copy_u8CompareValue)
{
	OCR2=copy_u8CompareValue;
}
/*
 * Description:Function that set delay for CTC mode
 */
void TMR2_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms)
{
	//under condition tick time 4ms and OCR=249
#if   TMR2_PRESCALER==TMR2_PRESCALER_1
	OCR2=40;
	CTC_Counter=copy_u16Delay_ms*400;
#elif TMR2_PRESCALER==TMR2_PRESCALER_8
	OCR2=249;
	CTC_Counter=copy_u16Delay_ms*8;
#elif TMR2_PRESCALER==TMR2_PRESCALER_64
	OCR2=249;
	CTC_Counter=copy_u16Delay_ms;
#elif TMR2_PRESCALER==TMR2_PRESCALER_256
	OCR2=20;
	CTC_Counter=copy_u16Delay_ms*3;

#elif TMR2_PRESCALER==TMR2_PRESCALER_1024
	OCR2=3;
	CTC_Counter=copy_u16Delay_ms*4;


#endif
}
/*
 * Description:Function that set Duty cycle for all PWM modes
 */
void TMR2_voidSetDutycycle(u8 copy_u8Duty)
{
	if(copy_u8Duty<=100)
	{
#if TMR2_PWM_MODE==TMR2_PWM_NON_INVERTING
		OCR2=((u16)(copy_u8Duty*256)/100)-1;
#elif TMR2_PWM_MODE==TMR2_PWM_INVERTING
		//OCR0=255-(((uint16)copy_u8Duty*256)/100);
		OCR2=((uint16)((100-copy_u8Duty)*256)/100)-1;
#endif
	}
}

/*
 * Description:ISR for Timer2 Normal mode
 */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16counter=0;
	local_u16counter++;
	if(TMR2_OVER_FLOW_COUNTER==local_u16counter)
	{
		TCNT2=TMR2_PRELOAD_VALUE;
		local_u16counter=0;

		if(CallbackFunOVF!=NULL)
		{
			CallbackFunOVF();
		}
	}

}
/*
 * Description:ISR for Timer2 CTC mode
 */
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	/*
	static u16 local_u16counter=0;
	local_u16counter++;
	if(CTC_Counter==local_u16counter)
	{
		local_u16counter=0;
		if(CallbackFunCTC!=NULL)
		{
			CallbackFunCTC();
		}
	}*/
	if(CallbackFunCTC!=NULL)
	{
		CallbackFunCTC();
	}
}



