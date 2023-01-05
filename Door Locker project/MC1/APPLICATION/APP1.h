/*
 * APP.h
 *
 *  Created on: Jan 4, 2023
 *      Author: Dell
 */
#include"../COMMON/Bit_wise.h"
#include"../COMMON/STD_Types.h"
#include"../MCAL/DIO/DIO_Header/DIO_Interface.h"
#include"../MCAL/UART/UART_Header/UART_Interface.h"
#include"../HAL/Keypad/Keypad_interface.h"
#include"../HAL/LCD/CLCD_Interface.h"
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

void MC1_Init(void);

void Take_Password(void);

void Send_Password(void);

void Close_Door(void);

void Display_Status(void);

void APP_Init(void);

void APP_Start(void);


#endif /* APPLICATION_APP_H_ */
