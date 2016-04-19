/*
 * Keypad_interface.h
 *
 *  Created on: Mar 2, 2016
 *      Author: 7ossam
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define Keypad_u8Key1 		1
#define Keypad_u8Key2 		2
#define Keypad_u8Key3 		3
#define Keypad_u8Key4 		4
#define Keypad_u8Key5 		5
#define Keypad_u8Key6 		6
#define Keypad_u8Key7 		7
#define Keypad_u8Key8 		8
#define Keypad_u8Key9 		9
#define Keypad_u8Key10 		10
#define Keypad_u8Key11 		11
#define Keypad_u8Key12 		12
#define Keypad_u8Key13 		13
#define Keypad_u8Key14 		14
#define Keypad_u8Key15 		15
#define Keypad_u8Key16 		16

#define u8FORWARD		0
#define u8REVERSE			1


extern u8 Check_u8SwitchState(u8 Copy_u8SwitchIdx);
extern u8 Keypad_u8Read(void);

#endif /* KEYPAD_INTERFACE_H_ */
