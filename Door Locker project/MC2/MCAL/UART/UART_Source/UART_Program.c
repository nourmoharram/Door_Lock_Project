#include"../../../COMMON/STD_Types.h"
#include"../../../COMMON/Bit_wise.h"
#include"../UART_Header/UART_Interface.h"
#include"../UART_Header/UART_Config.h"
#include"../UART_Header/UART_Private.h"
#include"../UART_Header/UART_Register.h"
#include"../../DIO/DIO_Header/DIO_Interface.h"

void USART_voidPinInit(void)
{
	/*Initialize USART PINS*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
}


void USART_voidInit(void)
{
	u8 Local_UCSRC=0;
	/*SET BIT 7 TO SELECT UCSRC REGISTER*/
	SET_BIT(Local_UCSRC,UCSRC_URSEL);
	/*Mode initially is Asynchronous*/
	CLR_BIT(Local_UCSRC,UCSRC_UMSEL);
	/*Parity mode disabled initially*/
	CLR_BIT(Local_UCSRC,UCSRC_UPM0);
	CLR_BIT(Local_UCSRC,UCSRC_UPM1);

	/*Stop bit is 1 initially*/
	CLR_BIT(Local_UCSRC,UCSRC_USBS);

	/*select 8 bit word size*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_UCSRC,UCSRC_UCSZ1);

	UCSRC = Local_UCSRC;
	/*SET BAUD RATE TO 9600 bit/second*/
	UBBRL = 51;

	SET_BIT(UCSRB,UCSRB_RXEN); //ENABLE receive bit
	SET_BIT(UCSRB,UCSRB_TXEN); //ENABLE transmit bit
}

void USART_voidSend(u8 Copy_u8data)
{
	/*WAIT until transmit buffer is empty*/
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR= Copy_u8data;
}

u8 USART_u8Receive(void)
{
	/*wait until receive is complete*/
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;

}
