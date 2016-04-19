/*
 * Stepper.h
 *
 *  Created on: Mar 7, 2016
 *      Author: aya osama
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#define STEPPERPIN1    DIO_u8PIN26
#define STEPPERPIN2    DIO_u8PIN27
#define STEPPERPIN3    DIO_u8PIN25
#define STEPPERPIN4    DIO_u8PIN24


extern void Stepper_Speed(u8 Copy_u8MotorDir);
extern void Stepper_Reverse(void);
extern void Stepper_Stop(void);

#endif /* STEPPER_H_ */
