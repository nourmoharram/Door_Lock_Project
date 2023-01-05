/*
 * UART_Interface.h
 *
 *  Created on: Dec 31, 2022
 *      Author: Dell
 */

#ifndef MCAL_UART_UART_HEADER_UART_INTERFACE_H_
#define MCAL_UART_UART_HEADER_UART_INTERFACE_H_

void USART_voidPinInit(void);

void USART_voidInit(void);

void USART_voidSend(u8 Copy_u8data);

u8 USART_u8Receive(void);

#endif /* MCAL_UART_UART_HEADER_UART_INTERFACE_H_ */
