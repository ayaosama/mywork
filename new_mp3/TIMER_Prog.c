/*
 * TIMER_Prog.c
 *
 *  Created on: Apr 3, 2016
 *      Author: aya osama
 */

#include "Types.h"
#include "Conc.h"
#include "DIO_interface.h"
#include "Timer_Config.h"
#include "Timer_Private.h"
#include "Timer_Interface.h"

//static volatile u32 Global_u32OvfCounter;

void (*Ptr_TimerOverFlow_ISR)(void);
void (*Ptr_TimerCmpMode_ISR)(void);

void Timer0_voidInit(void) {
	*TIMER_TCCR0 = T_TCCR0;
	*TIMER_TIMSK0 = T_TIMSK0;
	*TIMER_TIFR0 = T_TIFR0;
}

void Timer_voidSetTimerOverFlow_ISR(void (*ptrToFunc)(void)) {
	Ptr_TimerOverFlow_ISR = ptrToFunc;
}
//
//u32 Get_u32OvfCount(void)
//{
//	return Global_u32OvfCounter;
//}

//void Set_CertainTimeOvf(u32 Copy_u32EventsVal)
//{
//	if (Global_u32OvfCounter==Copy_u32EventsVal)
//	{
//		Global_u32OvfCounter=0;
//	}
//}

void Timer_voidSetTimerCmpMode_ISR(void (*ptrToFunc)(void)) {
	Ptr_TimerCmpMode_ISR = ptrToFunc;
}

void Assign_voidOCR0(u8 Copy_u8Value) {
	*TIMER_OCR0 = Copy_u8Value;
}

ISR(__vector_10) {
	Ptr_TimerCmpMode_ISR();
}

ISR(__vector_11) {
//	Global_u32OvfCounter++;
	Ptr_TimerOverFlow_ISR();
}


u8 Convert_u8DecToHex(u8 Copy_u8Dec) {
	u8 Local_u8Rem = 0;
	u8 Local_u8Hex = 0;
	u8 Local_u8Counter = 1;

	while (Copy_u8Dec != 0) {
		Local_u8Rem = Copy_u8Dec % 2;
		Copy_u8Dec /= 2;
		Local_u8Hex += Local_u8Rem * Local_u8Counter;
		Local_u8Counter *= 10;
	}
	return Local_u8Hex;
}

void Set_voidTimerOvf(u8 Copy_u8desieredTime) {
	u8 Local_u8TimerCk = 0;
	u8 Local_u8NwOFOvf = 0;
	u8 Local_u8LoadedValDec = 0;
	u8 Local_u8LoadedValHex = 0;
	u8 Local_u8TimerCKPreScaler = 0;

	Local_u8TimerCKPreScaler = (1 / CKSELECT) * FREQCK;
	Local_u8TimerCk = 1 / Local_u8TimerCKPreScaler;
	Local_u8NwOFOvf = Copy_u8desieredTime / Local_u8TimerCk;
	Local_u8LoadedValDec = 256 - Local_u8NwOFOvf;
	Local_u8LoadedValHex = Convert_u8DecToHex(Local_u8LoadedValDec);
	*TIMER_TCNT0 = Local_u8LoadedValHex;
}

