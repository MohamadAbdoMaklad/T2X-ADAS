#define F_CPU 16000000UL
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"
#include "DIO_Interface.h"
#include "L298N_Interface.h"
#include "FlagsType.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "TMR0_Interface.h"
#include "TMR2_Interface.h"
#include "HAL/Ultrasonic/ultrasonic.h"
#include "UART0_interface.h"


xTaskHandle Task_GetState = NULL;
#define Task_GetStatePr		2

xTaskHandle Task_CheckEMB = NULL;
#define Task_CheckEMBPr		1

xTaskHandle Task_SetACCAction = NULL;
#define Task_SetACCActionPr	0

xTaskHandle Task_Uart_Handle=NULL;
#define Task_UartReceivePr	3


void Task_Uart				        			(void* pvParameter);
void Task_GetState_Func							(void* pvParameter);
void Task_CheckEMB_Func							(void* pvParameter);
void Task_SetACCAction_Func						(void* pvParameter);
void UART0_ReceptionCompleteNotfication			(void);
void UART0_TransmissionCompleteNotiication      (void);

s8 SetSpeed = 80;
u16 MyDistance = 0;
Flags_t Flag;

#define  PWM_Intial_Value    20
#define Minimum_Speed        40
s16 CurrentPWM=PWM_Intial_Value;
u8 SetPoint_Speed=60;
u8 Safe_Distance=80;
f32 Constant=0.5;


int main(void)
{
	Flag.ACC		= LOW;
	Flag.EMB		= LOW;
	Flag.Ultra_Init	= LOW;
	Flag.DataUpdate = LOW;
	Flag.DataSent   =HIGH;
	DCM_CH1_voidInit();
	UART0_SetReceptionCompleteCallBack(UART0_ReceptionCompleteNotfication);
	UART0_SetTransmissionCompleteCallBack(UART0_TransmissionCompleteNotiication);
	UART0_init();
	DCM_CH1_voidSetMotorState(MotorCW);
	DCM_CH2_voidSetMotorSpeed(CurrentPWM);
	Dio_SetChannelDirection(DIOC3,INPUT);
	Dio_SetChannelDirection(DIOC2,OUTPUT);
	xTaskCreate(Task_GetState_Func		,(const s8*)"GetState"		,50,NULL,Task_GetStatePr		,&Task_GetState	   );
	xTaskCreate(Task_CheckEMB_Func		,(const s8*)"SetAction"		,50,NULL,Task_CheckEMBPr		,&Task_CheckEMB	   );
	xTaskCreate(Task_SetACCAction_Func	,(const s8*)"SetACC"		,50,NULL,Task_SetACCActionPr	,&Task_SetACCAction);
	xTaskCreate(Task_Uart               ,(const s8*)"UartReceive"   ,50,NULL,Task_UartReceivePr     ,&Task_Uart_Handle );
	vTaskStartScheduler();
	while(1)
	{
		
	};
	return 0;
}

void Task_GetState_Func(void* pvParameter)
{
	portTickType Start=xTaskGetTickCount();
	portTickType Freq=50;
	for(;;)
	{
		if (LOW == Flag.Ultra_Init)
		{
			Ultrasonic_init();
			Flag.Ultra_Init = HIGH;
			Flag.ICUDR = LOW;
		}
		else
		{
			Ultrasonic_Trigger_1();
			vTaskDelay(1);
			Ultrasonic_Trigger_2();
		}
		u16 buffer;
		if (1==Ultrasonic_GetReading(&buffer))
		{
			MyDistance=buffer;
			Flag.DataUpdate=HIGH;
		}
		vTaskDelayUntil(&Start,Freq);
	}
}
void Task_CheckEMB_Func(void* pvParameter)
{
	portTickType Start=xTaskGetTickCount();
	portTickType Freq=100;
	for(;;)
	{
		if(LOW==Flag.EMB)
		{
			if((MyDistance>0)&&(MyDistance<=20))
			{
				DCM_CH1_voidSetMotorState(MotorOFF);
				CurrentPWM=0;
				Flag.ACC=LOW;
				Flag.EMB=HIGH;
				if(HIGH==Flag.DataSent)
				{
					UART0_AsyncSendByte('G');
					Flag.DataSent=LOW;
				}
			}
		}
		else if(HIGH==Flag.EMB)
		{
			
			if(STD_LOW==Dio_ReadChannel(DIOC3))
			{
				
				Flag.EMB=LOW;
				if(HIGH==Flag.DataSent)
				{
					UART0_AsyncSendByte('H');
					Flag.DataSent=LOW;
				}
			}
		}
		vTaskDelayUntil(&Start,Freq);
	}
}
void Task_SetACCAction_Func(void* pvParameter)
{
	portTickType Start=xTaskGetTickCount();
	portTickType Freq=200;
	for(;;)
	{
		if((LOW==Flag.EMB)&&(HIGH==Flag.ACC)&&(HIGH==Flag.DataUpdate))
		{
			DCM_CH1_voidSetMotorState(MotorCCW);
			s16 Speed_Change=MyDistance-Safe_Distance;
			if((Speed_Change<5)&&(Speed_Change>-5))
			{
				Speed_Change=0;
			}
			CurrentPWM=CurrentPWM+Constant*Speed_Change;
			
			if(CurrentPWM<Minimum_Speed)
			{
				CurrentPWM=Speed_Change;
			}
			if(CurrentPWM>100)
			{
				CurrentPWM=100;
			}
			Flag.DataUpdate=LOW;
			if((CurrentPWM<SetSpeed))
			{
				DCM_CH1_voidSetMotorSpeed((u8)CurrentPWM);
			}
			else
			{
				CurrentPWM=SetSpeed;
				DCM_CH1_voidSetMotorSpeed((u8)CurrentPWM);
			}
		}
		vTaskDelayUntil(&Start,Freq);
	}
}
void Task_Uart(void* pvParameter)
{
	portTickType Start=xTaskGetTickCount;
	portTickType Freq=100;
	for(;;)
	{
		uint32_t ulReceptionNotificationValue;
		ulReceptionNotificationValue    = ulTaskNotifyTakeIndexed(0,pdFALSE,200);
		
		if(1==ulReceptionNotificationValue)
		{
			u8 local_ACC_Rx_Data=UART0_ReadDataReceived();
			if(HIGH==(GET_BIT(local_ACC_Rx_Data,0)))
			{
				Flag.ACC=HIGH;
				SetSpeed = GET_REG_BITS(local_ACC_Rx_Data,7,1);
			}
			else
			{
				Flag.ACC=LOW;
			}
		}
		else
		{
			/*Do nothing*/
		}
		vTaskDelayUntil(&Start,Freq);
	}
}
void UART0_ReceptionCompleteNotfication(void)
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	if(Task_Uart_Handle!=NULL)
	{
		vTaskNotifyGiveFromISR(Task_Uart_Handle,&xHigherPriorityTaskWoken);
	}
}
void UART0_TransmissionCompleteNotiication(void)
{
		if(Task_Uart_Handle!=NULL)
		{
			Flag.DataSent=HIGH;
		}
}

