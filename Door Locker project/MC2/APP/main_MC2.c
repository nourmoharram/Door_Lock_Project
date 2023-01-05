#include<util/delay.h>
#include "../APPLICATION/APP2.h"

int main(void)
{
	MC2_Init();
	while(1)
	{
		APP_Start();
		_delay_ms(1000);

	}
}
/*
int main(void)
{
	u8 Received_data=0;
	u8 Received_Pass[4];
	u8 Password[4]={'1','2','3','4'};
	u8 UART_Counter=0;
	u8 flag=1;
	u8 flag2=1;
	u8 Counter=0;
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	//DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	TIMER1_voidInit();
	USART_voidInit();
	TIMER1_voidSetICR(20000);
	//u16 Local_u8Counter=0;
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	while(1)
	{
		Received_data=USART_u8Receive();
		if(Received_data != '\0')
			{
				Received_Pass[UART_Counter]=Received_data;
				UART_Counter++;
			}
			if(UART_Counter==4)
			{
				if(Password[Counter]==Received_Pass[Counter])
					{
						Counter++;
					}
				else if(Password[Counter] != Received_Pass[Counter])
					{
						USART_voidSend(0);
					}
				if(Counter==4)
					{
						USART_voidSend(1);
						TIMER1_voidSetCompareMatch(1188);
					}
			}
			while((DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0))==0);
			TIMER1_voidSetCompareMatch(750);
			USART_voidSend(2);
			Counter=0;
			UART_Counter=0;
	}

	while(1)
	{

		while(flag==1)
		{
			Received_data=USART_u8Receive();
			if(Received_data != '\0')
			{
				Received_Pass[UART_Counter]=Received_data;
				UART_Counter++;
			}
			if(UART_Counter==4)
			{
				flag=0;
			}
		}
		while(flag2==1)
		{
			if(Password[Counter]==Received_Pass[Counter])
			{
				Counter++;
			}
			else if(Password[Counter] != Received_Pass[Counter])
			{
				flag2=0;
				USART_voidSend(0);
			}
			if(Counter==4)
			{
				flag2=0;
				USART_voidSend(1);
				TIMER1_voidSetCompareMatch(1188);
			}
		}

		while((DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0))==0);
		TIMER1_voidSetCompareMatch(750);
		USART_voidSend(2);
		flag=1;
		flag2=1;
		Counter=0;
		UART_Counter=0;
	}

	while(flag==1)
	{
		Received_data=USART_u8Receive();
		if(Received_data != '\0')
		{
			Received_Pass[UART_Counter]=Received_data;
			UART_Counter++;
		}
		if(UART_Counter==4)
		{
			flag=0;
		}
	}
	while(flag2==1)
	{
		if(Password[Counter]==Received_Pass[Counter])
		{
			Counter++;
		}
		else if(Password[Counter] != Received_Pass[Counter])
		{
			flag2=0;
			USART_voidSend(0);
		}
		if(Counter==4)
		{
			flag2=0;
			USART_voidSend(1);
			TIMER1_voidSetCompareMatch(1188);
		}
	}
	while((DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0))==0);
	TIMER1_voidSetCompareMatch(750);
	USART_voidSend(2);



}

*/
