/*
 * ADC_Config.h
 *
 *  Created on: Mar 13, 2016
 *      Author: aya osama
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define ADATE				u8ZERO
#define ADIE					u8ZERO
#define PRRSCALER		16
/********************************************************************************/
#define REFSELECTION 	AVCC/*	AREF , AVCC , INTVOLT*/
#define ADLAR					LEFTADJ    /*LEFTAGJ or RIGHTAGJ */
/********************************************************************************/
#define AUTOTRGSOURCE		FREE  /*FREE, ANGCMP,EXTINT0,CMPTIM0,OVFTIM0,CMPTIM1,OVFTIM1,CAPTURE1*/

#endif /* ADC_CONFIG_H_ */
