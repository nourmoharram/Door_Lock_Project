/*
 * APP.h
 *
 *  Created on: Jan 4, 2023
 *      Author: Dell
 */

#include"../COMMON/Bit_wise.h"
#include"../COMMON/STD_Types.h"
#include"../MCAL/DIO/DIO_Header/DIO_Interface.h"
#include"../MCAL/FAST_PWM_TIMER1/TIMER1_Header/TIMER1_Interface.h"
#include"../MCAL/UART/UART_Header/UART_Interface.h"

#ifndef APPLICATION_APP2_H_
#define APPLICATION_APP2_H_

void MC2_Init(void);

void Receive_Password(void);

void Check_Password(void);

void Check_Door(void);

void APP_Init(void);

void APP_Start(void);

#endif /* APPLICATION_APP2_H_ */
