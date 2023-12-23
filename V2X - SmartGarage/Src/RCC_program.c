/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

/** LIB Layer **/
#include "STD_types.h"
#include "BIT_math.h"

/** MCAL **/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_u8InitSysClk				(void)
{
	/* select the clk to be selected */
	/* select clk source : 1:HSI , 2:HSE , 3:PLL */
#if RCC_u8_SYS_CLK == RCC_u8_HSI
	//RCC->CR=0x00000001;//HSI ON
		//RCC->CFGR=0x00000000;	   // HSI selected as clk system
		SET_BIT(RCC->CR,RCC_CR_HSION);
		while(GET_BIT(RCC->CR,RCC_CR_HSIRDY)==0);
		CLR_BIT(RCC->CFGR,RCC_CFGR_SW0);
		CLR_BIT(RCC->CFGR,RCC_CFGR_SW1);
#elif RCC_u8_SYS_CLK == RCC_u8_HSE
	RCC->CR=0x00050000; //HSE ON
	RCC->CFGR=0x00000001;		// HSE selected as clk system
#elif RCC_u8_SYS_CLK == RCC_u8_PLL
	RCC->CR=0x01000000; //PLL ON
	RCC->CFGR=0x00000002;		//PLL selected as clk system
#else
	#error "Wrong System Clock Choice"

#endif
	

}

void RCC_u8EnablePeripheralClk	(uint8 Copy_u8BusID , uint8 Copy_u8PeripheralID)
{
	if (Copy_u8PeripheralID <32)//if >32 then out of range
	{
		switch (Copy_u8BusID)
		{
			case RCC_u8_AHB_BUS:
				SET_BIT(RCC->AHBENR,Copy_u8PeripheralID);
				break;
			
			case RCC_u8_APB1_BUS:
				SET_BIT(RCC->APB1ENR,Copy_u8PeripheralID);
				break;

			case RCC_u8_APB2_BUS:
				SET_BIT(RCC->APB2ENR,Copy_u8PeripheralID);
				break;
		}
	}
}

void RCC_u8DisablePeripheralClk	(uint8 Copy_u8BusID , uint8 Copy_u8PeripheralID)
{
	if (Copy_u8PeripheralID <32)//if >32 then out of range
	{
		switch (Copy_u8BusID)
		{
			case RCC_u8_AHB_BUS:
				CLR_BIT(RCC->AHBENR,Copy_u8PeripheralID);
				break;

			case RCC_u8_APB1_BUS:
				CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralID);
				break;

			case RCC_u8_APB2_BUS:
				CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralID);
				break;
		}
	}
}
