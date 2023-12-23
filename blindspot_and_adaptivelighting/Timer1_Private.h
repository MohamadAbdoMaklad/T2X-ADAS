#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
typedef enum
{
	 WGM10=0,
	 WGM11,
	 FOC1B,
	 FOC1A,
	 COM1B0,
	 COM1B1,
	 COM1A0,
	 COM1A1,
}T1_TCCR1A_Bits;

typedef union{
	u8 AllRegister;
	T1_TCCR1A_Bits Bits;
}T1_TCCR1A_t;


typedef enum
{
	 CS10=0,
	 CS11,
	 CS12,
	 WGM12,
	 WGM13,
	 RESERVED,
	 ICES1,
	 ICNC1
}T1_TCCR1B_Bits;

typedef union{
	u8 AllRegister;
	T1_TCCR1B_Bits Bits;
}T1_TCCR1B_t;



#define TCNT1  (*(volatile u16 *)((0x2C) + 0x20))
#define ICR1 (*(volatile u16 *)((0x26) + 0x20))
#define OCR1B (*(volatile u16 *)((0x28) + 0x20))
#define OCR1A (*(volatile u16 *)((0x2A) + 0x20))
#define TCCR1B (*(volatile u8 *)((0x2E) + 0x20))
#define TCCR1A (*(volatile u8 *)((0x2F) + 0x20))
#define TIFR (*(volatile u8 *)((0x38) + 0x20))
#define TIMSK (*(volatile u8 *)((0x39) + 0x20))


/*Timer 1 Modes*/
#define T1_NORMAL_M0	1
#define T1_CTC_M4		5
#define T1_FastPWM_M14	15
/*T1_FastPWM_M14 Modes*/
#define T1_PWM_NONINVERTING 1
#define T1_PWM_INVERTING 2
/*Timer 1 Prescaler Values*/
#define T1_PRESCALER_1				1
#define T1_PRESCALER_8				2
#define T1_PRESCALER_64				3
#define T1_PRESCALER_256			4
#define T1_PRESCALER_1024			5


#endif /* TIMER1_PRIVATE_H_ */

