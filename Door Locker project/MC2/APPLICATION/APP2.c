#include "APP2.h"
#include<util/delay.h>

/*Global variables*/
u8 Received_Password[4]={0};
u8 Original_Password[4]={'1','2','3','4'};
u8 Receive_flag=0;
u8 Check_Password_flag=0;
u8 Check_door_flag=0;
/*Function to start initialization for specific peripherals*/
void MC2_Init(void)
{
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);
	USART_voidInit();
	USART_voidPinInit();
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
}
/*Function to receive password from MC1 and store it in specific array*/
void Receive_Password(void)
{
	u8 Counter=0;
	u8 Received_data=0;
	while(Counter<=3)
	{
		Received_data=USART_u8Receive();
		_delay_ms(100);
		if(Received_data != '\0')
		{
			Received_Password[Counter]=Received_data;
			_delay_ms(100);
			Counter++;
		}
	}
	Receive_flag=1;
}
/*Function used to Compare the received password with the Correct one*/
void Check_Password(void)
{
	u8 Counter=0;
	while(Counter<=3)
	{
		if(Original_Password[Counter]==Received_Password[Counter])
		{
			Counter++;
		}
		else if(Original_Password[Counter]!=Received_Password[Counter])
		{
			/*Wrong Password*/
			//USART_voidSend(2);
			Check_Password_flag=2;
			break;
		}
	}
	if(Counter==4)
	{
		/*Door open*/
		//USART_voidSend(1);
		//TIMER1_voidSetCompareMatch(1188);
		/*Enable green led for close door and disable red led*/
		//DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		//DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		//_delay_ms(500);
		Check_Password_flag=1;
	}


}
/*Function used to close door after Specific number is being sent from MC1*/
void Check_Door(void)
{
	u8 Received_data;
	Received_data=USART_u8Receive();
	_delay_ms(200);
	/*Close Door*/
	USART_voidSend(3);
	_delay_ms(200);
	TIMER1_voidSetCompareMatch(750);
	/*Enable led red for close door and disable green led*/
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
	Check_door_flag=1;
}

void APP_Init(void)
{
	MC2_Init();
}

/*Application Implementation*/
void APP_Start(void)
{
	Receive_Password();
	if(Receive_flag==1)
	{
		Check_Password();
		switch(Check_Password_flag)
		{
		case 1:
			/*Door open*/
			USART_voidSend(1);
			TIMER1_voidSetCompareMatch(1188);
			/*Enable green led for close door and disable red led*/
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			break;
		case 2:
			/*Wrong Password*/
			USART_voidSend(2);
			break;
		}
		if(Check_Password_flag==1)
		{
			Check_Door();
		}
	}
}


