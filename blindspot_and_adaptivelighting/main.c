/*
 * APP LAYER FOR
 * ADAPTIVE LIGHTING AND BLIND SPOT FEATURES
 *
 */
#include"LIB_BIT_MATH.h"
#include"LIB_STD.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "ultrasonic.h"
#include "ICU_reg.h"
#include "LCD_Interface.h"
#include "ADC.h"
#include"TMR0_Interface.h"
#include "ServoMotor_Interface.h"
u16 measured_distance=0;
/*
 * a function to set direction of lighting
 * */
void adaptive_lighting_position(void);
/*
 * a function to detect objects (blind spot)
 * */
void blind_spot(void);
/*
 * a function to turn off a warning action if there is not detected object
 * */
void blind_spot_led_off(void);
/*
 * a function to turn on a warning action if an object is detected
 * */
void blind_spot_led_on(void);
/*
 * a function to control the the lighting intensity according to the sensed light
 * */
void adaptive_lighting(void);
/*
 * a function to initialize the system
 * */
void system_init(void);
int main(void)
{
	 system_init();

	while(1)
	{
		blind_spot();
		_delay_ms(300);
		adaptive_lighting();
		adaptive_lighting_position();

	}
	return 0;
	}
void blind_spot(void)
{
	if (Ultrasonic_1_readDistance()<=20)
	{
		LCD_Clear();
		LCD_SetPosition(1,2);
		LCD_String("an object detected\0");
		blind_spot_led_on();

	}
	else
	{
		LCD_Clear();
		blind_spot_led_off();
	}
}
void blind_spot_led_on(void)
{
	Dio_WriteChannel(DIOE4 , STD_HIGH);
	}
void blind_spot_led_off(void)
{
	Dio_WriteChannel(DIOE4 , STD_LOW);
	}
void adaptive_lighting(void)
{
	TMR0_voidSetDutycycle(LDR_u16GetDigitalReading(0)/7);
	}
void system_init(void)
{
	Ultrasonic_init();
	LCD_Init();
	 Dio_SetChannelDirection(DIOE4 ,OUTPUT);
	 Dio_WriteChannel(DIOE4 , STD_LOW);
		ADC_voidInit();
		TMR0_voidInit();
		TMR0_voidSetDutycycle(0);
		TMR0_voidStart();
		 Dio_SetChannelDirection(DIOB4 ,OUTPUT);
		 Dio_SetChannelDirection(DIOD3 ,OUTPUT);
		 ServoMotor_voidInit();
	}
void adaptive_lighting_position(void)
{
	measured_distance=Ultrasonic_2_readDistance();
	if( measured_distance <10)
	{

		ServoMotor_SetAngle(0);
	}
	else if(10<=measured_distance && measured_distance <50)
	{
		ServoMotor_SetAngle(measured_distance+40 );
	}
	else
		ServoMotor_SetAngle(90);
	}
