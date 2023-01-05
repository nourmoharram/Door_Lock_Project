/*
 * TIMER1_Register.h
 *
 *  Created on: Jan 3, 2023
 *      Author: Dell
 */

#ifndef MCAL_FAST_PWM_TIMER1_TIMER1_HEADER_TIMER1_REGISTER_H_
#define MCAL_FAST_PWM_TIMER1_TIMER1_HEADER_TIMER1_REGISTER_H_

#define TCCR1A          *((volatile u8*)0x4f) /*timer 1A control register*/
#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1
#define TCCR1A_COM1A1   7
#define TCCR1A_COM1A0   6

#define TCCR1B          *((volatile u8*)0x4e) /*timer 1B control register*/
#define TCCR1B_WGM13    4
#define TCCR1B_WGM12    3
#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2

#define ICR1            *((volatile u16*)0x46)
#define OCR1A           *((volatile u16*)0x4a)

#endif /* MCAL_FAST_PWM_TIMER1_TIMER1_HEADER_TIMER1_REGISTER_H_ */
