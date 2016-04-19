/*
 * main.c
 *
 *  Created on: Mar 2, 2016
 *      Author: 7ossam
 */

#include "Types.h"
#include "util.h"
#include "DIO_interface.h"
#include "Delay.h"
#include "Keypad_interface.h"
#include "Stepper.h"

int main(void) {
	u8 Local_u8KeypadReading = 0;
	u8 Local_u8MaxCounter = 0;
	u8 Local_u8Counter = 0;
	u8 Local_u8MotorDir = u8FORWARD;
	DIO_voidInit();

	while (1) {
//		//Stepper_Stop();
		Local_u8KeypadReading = Keypad_u8Read();
		Local_u8MaxCounter = (320 / Local_u8KeypadReading);
		Local_u8Counter++;
	if (Local_u8Counter >= Local_u8MaxCounter) {
//			if (Local_u8KeypadReading == 13) {
//				Stepper_Stop();
//				Local_u8Counter = 0;	}
//			else if (Local_u8KeypadReading == 10) {
//				if (Local_u8MotorDir == u8FORWARD) {
//					Local_u8MotorDir = u8REVERSE;
//					Stepper_Speed(Local_u8MotorDir);
//					Local_u8Counter = 0;
//				} else if (Local_u8MotorDir == u8REVERSE) {
//					Local_u8MotorDir = u8FORWARD;
//					Stepper_Speed(Local_u8MotorDir);
//					Local_u8Counter = 0;
//				}
//
//			}
//	else {
//				Stepper_Speed(Local_u8MotorDir);
//				Local_u8Counter = 0;
//			}
//		}
//	Stepper_Speed(Local_u8KeypadReading);
//DELAY_voidDELAY(300);
//Stepper_Reverse();
		DIO_u8WritePortVal(2, Local_u8KeypadReading);}
	}

	return 0;
}

