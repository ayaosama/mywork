/*
 * Timer_Private.h
 *
 *  Created on: Apr 3, 2016
 *      Author: aya osama
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/***************************************TIMER0 REGISTERS***********************************/
#define TIMER_TCCR0			((volatile u8*)(0x53))
#define TIMER_TCNT0		((volatile u8*)(0x52))
#define TIMER_OCR0			((volatile u8*)(0x5C))
#define TIMER_TIMSK0		((volatile u8*)(0x59))
#define TIMER_TIFR0			((volatile u8*)(0x58))

/**************************************** BITS SETTING******************************************/
#if (WGMMODE==0)
#define T_WGM00 	u8ZERO
#define T_WGM01 	u8ZERO
#define T_FOC0		u8ZERO
/**********************************************************/
#elif (WGMMODE==1)
#define T_WGM00 	1
#define T_WGM01 	0
#define T_FOC0		0
/*********************************************/
#elif (WGMMODE==2)
#define T_WGM00 	0
#define T_WGM01 	1
#define T_FOC0		0
/********************************/
#elif (WGMMODE==3)
#define T_WGM00 	1
#define T_WGM01 	1
#define T_FOC0		1

#endif

/*********** set compare o/p mode  ***********/
					#if ( COMMODE==0)
					#define T_COM00		0
					#define T_COM01		0

					#elif	(COMMODE==1)
					#define T_COM00		1
					#define T_COM01		0

					#elif	(COMMODE==2)
					#define T_COM00		0
					#define T_COM01		1

					#elif	(COMMODE==3)
					#define T_COM00		1
					#define T_COM01		1

					#endif
/**********************SET CLOCK ********************/

#if (CKSELECT == 0)
#define T_CS00			0
#define T_CS01			0
#define T_CS02			0

#elif (CKSELECT == 1)
#define T_CS00			1
#define T_CS01			0
#define T_CS02			0

#elif (CKSELECT == 8)
#define	T_CS00			0
#define T_CS01			1
#define T_CS02			0

#elif (CKSELECT == 64)
#define T_CS00			1
#define T_CS01			1
#define T_CS02			0

#elif (CKSELECT == 256)
#define T_CS00			0
#define T_CS01			0
#define T_CS02			1

#elif (CKSELECT == 1024)
#define T_CS00			1
#define T_CS01			0
#define T_CS02			1

#elif (CKSELECT == 6)
#define T_CS00			0
#define T_CS01			1
#define T_CS02			1

#elif (CKSELECT == 7)
#define T_CS00			1
#define T_CS01			1
#define T_CS02			1

#else
#define T_CS00			0
#define T_CS01			0
#define T_CS02			0

#endif

#define T_TCCR0		CONC(T_FOC0,T_WGM00,T_COM01,T_COM00,T_WGM01,T_CS02,T_CS01,T_CS00)
#define T_TIMSK0	CONC(u8ZERO,u8ZERO,u8ZERO,u8ZERO,u8ZERO,u8ZERO,T_OCIE0,T_TOIE0)
#define T_TIFR0		CONC(u8ZERO,u8ZERO,u8ZERO,u8ZERO,u8ZERO,u8ZERO,1,1)
/*********************************TIMER OVERFLOW ISR***********************************/
#define ISR(vector) 																\
void vector (void) __attribute__((signal,used,externally_visible)); \
void vector (void)


u8 Convert_u8DecToHex(u8 Copy_u8Dec);
#endif /* TIMER_PRIVATE_H_ */
