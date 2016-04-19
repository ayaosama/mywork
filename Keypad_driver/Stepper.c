/*
 * Stepper.c
 *
 *  Created on: Mar 7, 2016
 *      Author: aya osama
 */

#include "Types.h"
#include "util.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "Delay.h"
#include "Stepper.h"
#include "Keypad_interface.h"
#include "keypad_config.h"
#include "Keypad_private.h"

const u8 ArrOfPins[4] = { STEPPERPIN1, STEPPERPIN2, STEPPERPIN3, STEPPERPIN4 };
const u8 ArrOfPinsRev[4] ={ STEPPERPIN4, STEPPERPIN3, STEPPERPIN2, STEPPERPIN1 };
extern void Stepper_Speed(u8 Copy_u8MotorDir) {
	static u8 Local_u8LoopCounter1 = 0;
	u8 Local_u8LoopCounter2 = 0;
	for (Local_u8LoopCounter2 = 0; Local_u8LoopCounter2 < 4;	Local_u8LoopCounter2++) {
		DIO_u8WritePinVal(ArrOfPins[Local_u8LoopCounter2], DIO_u8LOW);

	}

	if (Copy_u8MotorDir == u8FORWARD) {
		DIO_u8WritePinVal(ArrOfPins[Local_u8LoopCounter1], DIO_u8HIGH);
	} else if (Copy_u8MotorDir ==u8REVERSE) {
	DIO_u8WritePinVal(ArrOfPinsRev[Local_u8LoopCounter1], DIO_u8HIGH);
	}

	//DIO_u8WritePinVal(ArrOfPins[Local_u8LoopCounter1], DIO_u8HIGH);
	Local_u8LoopCounter1++;
	Local_u8LoopCounter1 = Local_u8LoopCounter1 % 4;

}




//extern void Stepper_Reverse(void)
//{
//	s8 Local_u8LoopCounter1=3;
//	s8 Local_u8LoopCounter2=0;
//	//s8 Local_u8LoopCounter=0;
//	for(Local_u8LoopCounter1=3;Local_u8LoopCounter1>=0;Local_u8LoopCounter1--)
//		{
//			DIO_u8WritePinVal(ArrOfPins[Local_u8LoopCounter2],DIO_u8LOW);
//		}
//					DIO_u8WritePinVal(ArrOfPins[Local_u8LoopCounter1],DIO_u8HIGH);
//					Local_u8LoopCounter1--;
//					Local_u8LoopCounter1=Local_u8LoopCounter1%4;
//}

extern void Stepper_Stop(void) {
	s8 Local_u8LoopCounter = 0;

	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 4;
			Local_u8LoopCounter++) {
		DIO_u8WritePinVal(ArrOfPinsRev[Local_u8LoopCounter], DIO_u8LOW);
	}

}
