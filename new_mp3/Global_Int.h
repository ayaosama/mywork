/*
 * Global_Int.h
 *
 *  Created on: Mar 31, 2016
 *      Author: aya osama
 */

#ifndef GLOBAL_INT_H_
#define GLOBAL_INT_H_

extern void Enable_voidGlobalInt(void)
{
	__asm__("SEI");
}

extern void Disable_voidGlobalInt(void)
{
	__asm__("CLI");
}

#endif /* GLOBAL_INT_H_ */
