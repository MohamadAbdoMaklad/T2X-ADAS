#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void T1_voidInit(void);
void T1_voidStart(void);
void T1_voidStop(void);
void T1_voidSetCompMatchValA(u16 copy_u16CompareMatchVal);
void T1_SetDyty_Mode14(f32 copy_f32DytyCycleVal);
void T1_SetFreq_Mode14(u16 copy_u16FreqVal);

#endif /* TIMER1_INTERFACE_H_ */