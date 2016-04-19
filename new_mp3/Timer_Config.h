/*
 * Timer_Config.h
 *
 *  Created on: Apr 3, 2016
 *      Author: aya osama
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


#define FREQCK			4  /*in MHz*/
/**********************************************************************************************************/
#define WGMMODE		0	/* 0 --> normal mode , 1 -->PWM , 2-->CTC , 3--> Fast PWM  */

#define	 COMMODE		0  /* 0-->OC0 disconnected , 1-->toggle OC0 , 2-->OC0 , 3--> clear , 4--> OC0 compare match */

#define CKSELECT 			1	 /* 0 --> no clock source , 1--> no pre scaler , 8 -->CK/8 ,  64 -->CK/64 ,  256 --> CK/256 , 1024 --> CK/1024 ,6 -->T0 falling edge , 7--> T0 rising edge */

#define T_OCIE0					u8DISABLE	/* timer o/p compare match interrupt enable */

#define T_TOIE0					u8ENABLE /* timer overflow interrupt enable */


/**********************************************************************************************************/

#endif /* TIMER_CONFIG_H_ */
