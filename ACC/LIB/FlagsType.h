#ifndef FLAGSTYPE_H_
#define FLAGSTYPE_H_
#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"
typedef struct
{
	u8 ACC			:1;
	u8 EMB			:1;
	u8 TRIG_Seq		:1;
	u8 RDR			:1;
	u8 ICUDR		:1;
	u8 Ultra_Init	:1;
    u8 DataUpdate   :1;
    u8 DataSent		:1;
}Flags_t;
typedef union
{
	Flags_t Bit;
	u8 Reg;
}FlagAcc_t;

#endif /* FLAGSTYPE_H_ */