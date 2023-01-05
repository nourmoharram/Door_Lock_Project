#include<util/delay.h>
#include "../APPLICATION/APP1.h"





int main(void)
{
	MC1_Init();
	while(1)
	{
		APP_Start();
		_delay_ms(1000);
	}
}




/*
int main(void)
{
	u8 Local_pass='\0';
	u8 Password[4];
	u8 Counter=0;
	u8 UART_Counter=0;
	u8 flag=1;
	u8 Door_flag=1;
	u8 Received_data=0;
	u8 Received_data_2=0;
	KEYPAD_Init();
	CLCD_voidInit();
	USART_voidPinInit();
	USART_voidInit();
	while(1)
	{
		CLCD_voidSendString("Enter Password");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("To Open door");
		_delay_ms(2000);
		CLCD_voidClearDisplay();
		CLCD_voidSendString("Password:");
		while(flag==1)
		{
			while(Counter<=3)
			{
				Local_pass = KPD_u8GetPressedKey();
				while(Local_pass == '\0')
					{
						Local_pass = KPD_u8GetPressedKey();
					}
				CLCD_voidSendData(Local_pass);
				Password[Counter]=Local_pass;
				Counter++;
			}
				flag=0;
			}
		while(UART_Counter<=3)
			{
				if(Password[UART_Counter] != '\0')
				{
					USART_voidSend(Password[UART_Counter]);
					UART_Counter++;
				}
			}

			Received_data = USART_u8Receive();
			if(Received_data==1)
			{
				CLCD_voidClearDisplay();
				CLCD_voidSendString("Door is open");
				while(Door_flag==1)
				{
					Received_data_2= USART_u8Receive();
					if(Received_data_2==2)
					{
						CLCD_voidClearDisplay();
						CLCD_voidSendString("Door is Closed");
						Door_flag=0;
						_delay_ms(2000);
					}
				}
			}
			else if(Received_data==0)
			{
				CLCD_voidClearDisplay();
				CLCD_voidSendString("Wrong Password");
				_delay_ms(2000);
			}
			CLCD_voidClearDisplay();
			_delay_ms(2000);
			flag=1;
			UART_Counter=0;
			Counter=0;
			Door_flag=1;
	}

	CLCD_voidSendString("Enter Password");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("To Open door");
	_delay_ms(2000);
	CLCD_voidClearDisplay();
	CLCD_voidSendString("Password:");
	while(flag==1)
	{
		while(Counter<=3)
		{
			Local_pass = KPD_u8GetPressedKey();
			while(Local_pass == '\0')
				{
					Local_pass = KPD_u8GetPressedKey();
				}
			CLCD_voidSendData(Local_pass);
			Password[Counter]=Local_pass;
			Counter++;
		}
		flag=0;
	}
	while(UART_Counter<=3)
	{
		if(Password[UART_Counter] != '\0')
		{
			USART_voidSend(Password[UART_Counter]);
			UART_Counter++;
		}
	}

	Received_data = USART_u8Receive();
	if(Received_data==1)
	{
		CLCD_voidClearDisplay();
		CLCD_voidSendString("Door is open");
	}
	else if(Received_data==2)
	{
		CLCD_voidClearDisplay();
		CLCD_voidSendString("Door is Closed");
	}
	else
	{
		CLCD_voidClearDisplay();
		CLCD_voidSendString("Wrong Password");
	}

}
*/
