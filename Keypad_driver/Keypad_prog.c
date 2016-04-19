/*
 * Keypad_prog.c
 *
 *  Created on: Mar 2, 2016
 *      Author: 7ossam
 */


#include "Types.h"
#include "util.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "Delay.h"
#include "Keypad_interface.h"
#include "keypad_config.h"
#include "Keypad_private.h"

const u8 Rows_u8Arr[Keypad_u8RowsCount]={Keypad_u8Row1,Keypad_u8Row2,Keypad_u8Row3,Keypad_u8Row4};
const u8 Cols_u8Arr[Keypad_u8ColsCount]={Keypad_u8Col1,Keypad_u8Col2,Keypad_u8Col3,Keypad_u8Col4};
extern u8 Check_u8SwitchState(u8 Copy_u8SwitchIdx)
{
	u8 Local_u8SwitchState=u8RELEASED;
	u8 Local_u8ReturnVal=u8ERROR;
	u8 Local_u8Counter=0;

	DIO_u8ReadPinVal(Copy_u8SwitchIdx,&Local_u8SwitchState);
	if (Local_u8SwitchState==u8PRESSED)
	{
		if (Local_u8Counter<50)
		{
			Local_u8Counter++;
		}
		else if (Local_u8Counter==50)
		{
//			DELAY_voidDELAY(10);
			DIO_u8ReadPinVal(Copy_u8SwitchIdx,&Local_u8SwitchState);
			Local_u8Counter=0;
		}
	switch (Local_u8SwitchState)
	{
	case u8PRESSED:
		 Local_u8ReturnVal=u8PRESSED;
		 break;
	case u8RELEASED:
		Local_u8ReturnVal=u8RELEASED;
		 break;
//	default:
//		Local_u8ReturnVal=u8RELEASED;
	}
	}
	return Local_u8ReturnVal;

}

extern u8 Keypad_u8Read(void)
{
	u8 Local_u8LoopRowCounter=0;
	u8 Local_u8LoopCounter=0;
	u8 Local_u8LoopColCounter=0;
	u8 Local_u8SwitchState=0;
	static u8 Local_u8ReturnNum=1;
	u8 x=0;
	for (Local_u8LoopRowCounter=0;Local_u8LoopRowCounter<4;Local_u8LoopRowCounter++)
	{
		for (Local_u8LoopCounter=0;Local_u8LoopCounter<4;Local_u8LoopCounter++)
			{ DIO_u8WritePinVal(Rows_u8Arr[Local_u8LoopCounter],DIO_u8LOW);}
		DIO_u8WritePinVal(Rows_u8Arr[Local_u8LoopRowCounter],DIO_u8HIGH);
		for (Local_u8LoopColCounter=0;Local_u8LoopColCounter<4;Local_u8LoopColCounter++)
		{
			x=Check_u8SwitchState(Cols_u8Arr[Local_u8LoopColCounter]);

			if(x==u8PRESSED)
			{

				Local_u8ReturnNum=Local_u8LoopRowCounter*4+Local_u8LoopColCounter+1;
			}
		}
	}
	return Local_u8ReturnNum;
}

