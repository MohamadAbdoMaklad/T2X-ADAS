/**********************************************
 * Filename:TMR0_Program.c                     *
 * Description:Timer 0 Fuction implementation  *
 * Created on: Nov 16, 2023                    *
 * Author: Zeyad Ossama                        *
 ***********************************************/
#include"TMR0_Config.h"
#include"TMR0_Interface.h"
#include"TMR0_Register.h"
#include"TMR0_Private.h"
#include"LIB_BIT_MATH.h"
static void (*CallbackFunOVF)(void)=NULL;
static void (*CallbackFunCTC)(void)=NULL;

static volatile u16 CTC_Counter=0;
/*
 *Description:Function that initialize timer mode of operation
 */
void TMR0_voidInit()
{
#if TMR0_MODE==TMR0_NORMAL_MODE
	//Select mode normal mode
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	//Enable Interrupt
	SET_BIT(TIMSK,TOIE0);
	//Preload value
	TCNT0=TMRO_PRELOAD_VALUE;

#elif TMR0_MODE==TMR0_CTC_MODE
	//Select mode CTC mode
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	//Enable Interrupt
	SET_BIT(TIMSK,OCIE0);

#elif TMR0_MODE==TMR0_FAST_PWM_MODE
	//Select mode FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	//Select non-Inverting PWM
#if TMR0_PWM_MODE==TMR0_PWM_NON_INVERTING
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	//Select Inverting PWM
#elif TMR0_PWM_MODE==TMR0_PWM_INVERTING
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
#endif

#elif TMR0_MODE==TMR0_PHASE_CORRECT_PWM_MODE
	//Select mode Phase Correct_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	//Select non-Inverting PWM
#if TMR0_PWM_MODE==TMR0_PWM_NON_INVERTING
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	//Select Inverting PWM
#elif TMR0_PWM_MODE==TMR0_PWM_INVERTING
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
#endif


#endif
}
/*
 * Description:Function starts timer by setting Prescaler value
 * */
void TMR0_voidStart()
{
#if   TMR0_PRESCALER==TMR0_PRESCALER_1
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
#elif TMR0_PRESCALER==TMR0_PRESCALER_8
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
#elif TMR0_PRESCALER==TMR0_PRESCALER_64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
#elif TMR0_PRESCALER==TMR0_PRESCALER_256
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
#elif TMR0_PRESCALER==TMR0_PRESCALER_1024
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#endif
}
/*
 * Description:Function stops timer by setting Prescaler value to zero
 * */
void TMR0_voidStop()
{
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

}
/*
 * Description:Function that set Callback function for Normal mode
 */
void TMR0_voidSetCallBackOVF(void (*ptrfun)(void))
{
	if(ptrfun!=NULL)
	{
		CallbackFunOVF=ptrfun;
	}
}
/*
 * Description:Function that set Callback function for CTC mode
 */
void TMR0_voidSetCallBackCTC(void (*ptrfun)(void))
{
	if(ptrfun!=NULL)
	{
		CallbackFunCTC=ptrfun;
	}
}
/*
 * Description:Function that set Compare match register value
 */
void TMR0_voidSetCompareMatchvalue(u8 copy_u8CompareValue)
{
	OCR0=copy_u8CompareValue;
}
/*
 * Description:Function that set delay for CTC mode
 */
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms)
{
	//under condition tick time 4ms and OCR=249
#if   TMR0_PRESCALER==TMR0_PRESCALER_1
	OCR0=40;
	CTC_Counter=copy_u16Delay_ms*400;
#elif TMR0_PRESCALER==TMR0_PRESCALER_8
	OCR0=249;
	CTC_Counter=copy_u16Delay_ms*8;
#elif TMR0_PRESCALER==TMR0_PRESCALER_64
	OCR0=249;
	CTC_Counter=copy_u16Delay_ms;
#elif TMR0_PRESCALER==TMR0_PRESCALER_256
	OCR0=20;
	CTC_Counter=copy_u16Delay_ms*3;

#elif TMR0_PRESCALER==TMR0_PRESCALER_1024
	OCR0=3;
	CTC_Counter=copy_u16Delay_ms*4;


#endif
}
/*
 * Description:Function that set Duty cycle for all PWM modes
 */
void TMR0_voidSetDutycycle(u8 copy_u8Duty)
{
	if(copy_u8Duty<=100)
	{
#if TMR0_PWM_MODE==TMR0_PWM_NON_INVERTING
		OCR0=((u16)(copy_u8Duty*256)/100)-1;
#elif TMR0_PWM_MODE==TMR0_PWM_INVERTING
		//OCR0=255-(((uint16)copy_u8Duty*256)/100);
		OCR0=((uint16)((100-copy_u8Duty)*256)/100)-1;
#endif
	}
}

/*
 * Description:ISR for Timer0 Normal mode
 */
void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	static u16 local_u16counter=0;
	local_u16counter++;
	if(TMR0_OVER_FLOW_COUNTER==local_u16counter)
	{
		TCNT0=TMRO_PRELOAD_VALUE;
		local_u16counter=0;

		if(CallbackFunOVF!=NULL)
		{
			CallbackFunOVF();
		}
	}

}
/*
 * Description:ISR for Timer0 CTC mode
 */
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	static u16 local_u16counter=0;
	local_u16counter++;
	if(CTC_Counter==local_u16counter)
	{
		local_u16counter=0;
		if(CallbackFunCTC!=NULL)
		{
			CallbackFunCTC();
		}
	}
}



