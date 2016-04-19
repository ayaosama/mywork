/*
 * ADC_Private.h
 *
 *  Created on: Mar 13, 2016
 *      Author: aya osama
 */

#ifndef  ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_u8ADCSRA			((volatile u8*)(0x26))
#define ADC_u8ADCMUX 		((volatile u8*)(0x27))
#define ADC_u8ADCH				((volatile u8*)(0x25))
#define ADC_u8ADCL				((volatile u8*)(0x24))
#define ADC_u8SFIOR				((volatile u8*)(0x50))

#if (REFSELECTION==AREF)
#define REFS1			u8ZERO
#define RFES0			u8ZERO

#elif (REFSELECTION==AVCC)
#define REFS1			u8ONE
#define RFES0			u8ZERO

#elif (REFSELECTION==INTVOLT)
#define REFS1			u8ZERO
#define RFES0			u8ONE

#else
#define REFS1			u8ZERO
#define RFES0			u8ZERO

#endif

#if(PRRSCALER==0)
#define ADPS2			u8ZERO
#define ADPS1			u8ZERO
#define ADPS0			u8ZERO

#elif (PRRSCALER == 2)
#define ADPS2			u8ZERO
#define ADPS1			u8ZERO
#define ADPS0			u8ONE

#elif (PRRSCALER == 4)
#define ADPS2			u8ZERO
#define ADPS1			u8ONE
#define ADPS0			u8ZERO

#elif (PRRSCALER == 8)
#define ADPS2			u8ZERO
#define ADPS1			u8ONE
#define ADPS0			u8ONE

#elif (PRRSCALER == 16)
#define ADPS2			u8ONE
#define ADPS1			u8ZERO
#define ADPS0			u8ZERO

#elif (PRRSCALER == 32)
#define ADPS2			u8ONE
#define ADPS1			u8ZERO
#define ADPS0			u8ONE

#elif (PRRSCALER == 64)
#define ADPS2			u8ONE
#define ADPS1			u8ONE
#define ADPS0			u8ZERO

#elif (PRRSCALER == 128)
#define ADPS2			u8ONE
#define ADPS1			u8ONE
#define ADPS0			u8ONE

#else
#define ADPS2			u8ZERO
#define ADPS1			u8ZERO
#define ADPS0			u8ZERO

#endif

#define ADC_ADCSRA			CONC(u8ZERO,u8ZERO,ADATE,u8ZERO,ADIE,ADPS2,ADPS1,ADPS0)
#define ADC_ADCMUX		CONC(REFS1,RFES0,ADLAR,u8ZERO,u8ZERO,u8ZERO,u8ZERO,u8ZERO)
//#define	 ADC_ADCH			CONC(ADC7,ADC6,ADC5,ADC4,ADC3,ADC2,ADC1,ADC0)
//#define	 ADC_ADCL				CONC(ADC7,ADC6,ADC5,ADC4,ADC3,ADC2,ADC1,ADC0)
#define ADC_SFIOR				CONC(ADTS2,ADTS1,ADTS0,u8ZERO,u8ZERO,u8ZERO,u8ZERO,u8ZERO)



#endif /* ADC_PRIVATE_H_ */
