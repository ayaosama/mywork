/*
 * Timer_Interface.h
 *
 *  Created on: Apr 3, 016
 *      Author: aya osama
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define u8ENABLE				1
#define u8DISABLE				0

extern void Timer_voidSetTimerOverFlow_ISR(void (*ptrToFunc)(void));
extern void Timer_voidSetTimerCmpMode_ISR(void (*ptrToFunc)(void));
extern void Timer0_voidInit(void);
extern void Set_voidTimerOvf(u8 Copy_u8desieredTime);
extern void Assign_voidOCR0(u8 Copy_u8Value) ;

#endif /* TIMER_INTERFACE_H_ */
