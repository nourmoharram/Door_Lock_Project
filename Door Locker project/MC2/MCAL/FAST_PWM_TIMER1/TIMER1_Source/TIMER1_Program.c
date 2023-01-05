/*
 * TIMER1_Program.c
 *
 *  Created on: Jan 3, 2023
 *      Author: Dell
 */
#include"../../../COMMON/Bit_wise.h"
#include"../../../COMMON/STD_Types.h"
#include"../../DIO/DIO_Header/DIO_Interface.h"
#include"../TIMER1_Header/TIMER1_Interface.h"
#include"../TIMER1_Header/TIMER1_Register.h"

void TIMER1_voidInit(void)
{
	/*Select Fast-PWM Non-inverting mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	/*Setting waveform for fast PWM*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/*Setting PRE-SCALLER TO 8 DIVISION*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}

void TIMER1_voidSetICR(u16 Copy_u16TopValue)
{
	ICR1= Copy_u16TopValue;

}

void TIMER1_voidSetCompareMatch(u16 Copy_u16Comparematch)
{
	OCR1A= Copy_u16Comparematch;
}
