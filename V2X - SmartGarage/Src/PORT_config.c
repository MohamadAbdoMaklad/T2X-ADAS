/***************************************************************************/
/* Author  : MERNA */
/* Version : 01    */
/***************************************************************************/

#include "STD_types.h"
#include "PORT_config.h"
#include "GPIO_interface.h"


Port_ConfigType Port_cngs[]=
{
	//led
	{GPIO_PORT_C,GPIO_PIN_13,GPIO_OUT_50_PP},

	//IRs
	{GPIO_PORT_A,GPIO_PIN_0,GPIO_INP_PULL},
	{GPIO_PORT_A,GPIO_PIN_1,GPIO_INP_PULL},

	{-1,-1,-1}
};
