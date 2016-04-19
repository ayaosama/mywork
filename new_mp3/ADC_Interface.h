/*
 * ADC_Interface.h
 *
 *  Created on: Mar 13, 2016
 *      Author: aya osama
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADENIND			7
#define ADSCIND			6
#define ADATEIND			5
#define ADIFIND				4
#define ADIEIND			3
#define ADPS2IND			2
#define ADPS1IND			1
#define ADPS0IND			0

#define ADTS2IND			7
#define ADTS1IND			6
#define ADTS0IND			5

#define REFS1IND			7
#define RFES0IND			6

/*************************************************************/
#define AREF  			  			0
#define AVCC	 		  			1
#define INTVOLT	  			3

#define LEFTADJ		  			0
#define RIGHTADJ		  		1

#define FREE						0
#define ANGCMP					1
#define EXTINT0					2
#define CMPTIM0					3
#define OVFTIM0					4
#define CMPTIM1					5
#define OVFTIM1					6
#define CAPTURE1				7

/************************************************************/
void ADC_voidInit(void);
void Enable_voidADC(void);
void Disable_voidADC(void);
u16 Read_u16Channel(u8 Copy_u8ChannelNum);



#endif /* ADC_INTERFACE_H_ */
