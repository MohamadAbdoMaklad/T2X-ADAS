/*************************************************/
/*Author	            : Mohamad Abdo Maklad	 */
/*Date		            : 17-10-2023			 */
/*Last Modification		: 						 */
/*Version	            : V01				   	 */
/*************************************************/
/******(Bit Math Operations)**********************/
/*************************************************/
#ifndef LIB_BIT_MATH_H
#define LIB_BIT_MATH_H

#define SET_BIT(Reg,BitNo)           (Reg |=(1U<<BitNo))
#define CLEAR_BIT(Reg,BitNo)         (Reg &=(~(1U<<BitNo)))
#define TOGGLE_BIT(Reg,BitNo)        (Reg ^=(1U<<BitNo))
#define GET_BIT(Reg,BitNo)           ((Reg>>BitNo)&1U)

#define GET_REG_BITS(Reg,Bits,StartBit)				(((Reg)>>(StartBit))&((1U<<(Bits))-1U))
#define CLEAR_REG_BITS(Reg,Bits,StartBit)			((Reg)&=~(((1U<<(Bits))-1U)<<(StartBit)))
#define MOD_REG_BITS(Reg,Bits,StartBit,NewValue)	((Reg)=((Reg)&~(((1U<<(Bits))-1U)<<(StartBit)))|((NewValue)<<(StartBit)))
#define MOD_BIT(Reg,StartBit,NewValue)				((Reg)=((Reg)&~(1<<StartBit))|(NewValue<<StartBit))
//#define GetBit(Reg,BitNo)           (Reg & (1 << BitNo))
//#define GetRegBits0(Reg,Bits,StartBit)              (Reg & (((1U<<(Bits))-1U)<<StartBit))
#endif