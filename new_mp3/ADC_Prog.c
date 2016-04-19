/*
 * ADC_Prog.c
 *
 *  Created on: Mar 13, 2016
 *      Author: aya osama
 */


#include "Conc.h"
#include "util.h"
#include "Types.h"
#include "DIO_interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

//static volatile u8* const ADC_REGISTERS[4]={ADC_u8ADCSRA,ADC_u8ADCMUX,ADC_u8ADCH,ADC_u8ADCL};

void ADC_voidInit(void)
{
	*ADC_u8ADCSRA=ADC_ADCSRA;
	*ADC_u8ADCMUX =ADC_ADCMUX;
//	*ADC_u8ADCL=ADC_ADCL;
//	*ADC_u8ADCH=ADC_ADCH;
	//AssignReg((*ADC_u8SFIOR<<5),AUTOTRGSOURCE);
}

void Enable_voidADC(void)
{
	//*ADC_u8ADCSRA &=~(1<<ADENIND);
	*ADC_u8ADCSRA |=(1<<ADENIND);
}
void Disable_voidADC(void)
{
	*ADC_u8ADCSRA&=~(1<<ADENIND);
}

u16 Read_u16Channel(u8 Copy_u8ChannelNum)
{
	u16 Local_u16ReadingVal=0;
	*ADC_u8ADCMUX|=((*ADC_u8ADCMUX&(0xE0))|Copy_u8ChannelNum );
	*ADC_u8ADCSRA|=(1<<ADSCIND);
	while((*ADC_u8ADCSRA&(1<<ADIFIND))==0);
				Local_u16ReadingVal=*ADC_u8ADCL;
				Local_u16ReadingVal|=(*ADC_u8ADCH<<8);
				*ADC_u8ADCSRA|=(1<<ADIFIND);
				return Local_u16ReadingVal;
}
