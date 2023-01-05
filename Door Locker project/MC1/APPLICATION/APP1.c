#include"../APPLICATION/APP1.h"
#include<util/delay.h>
/*Global initialized variables*/
u8 Password[4]={0};
u8 Password_flag=0;
u8 Send_Password_flag=0;
u8 Close_door_flag=0;
u8 Display_status_flag=0;
/*Function to start initialization for specific peripherals*/
void MC1_Init(void)
{
	CLCD_voidInit();
	KEYPAD_Init();
	USART_voidInit();
	USART_voidPinInit();

}
/*Function used to take password from used using keypad and display entered password on LCD*/
void Take_Password(void)
{
	u8 Local_pass='\0';
	u8 Counter=0;
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Enter Password");
	_delay_ms(500);
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("To Open Door");
	_delay_ms(500);
	CLCD_voidClearDisplay();
	CLCD_voidSendString("Pass:");
	while(Counter<=3)
	{
		Local_pass=KPD_u8GetPressedKey();
		while(Local_pass == '\0')
			{
				Local_pass=KPD_u8GetPressedKey();
			}
		CLCD_voidSendData(Local_pass);
		Password[Counter]=Local_pass;
		Counter++;
	}
	/*Flag to determine that the process of taking password is done*/
	Password_flag=1;
}
/*Function used to Send password to Micro-controller 2 using UART communication protocol*/
void Send_Password(void)
{
	u8 USART_Counter=0;
	for(USART_Counter=0;USART_Counter<=3;USART_Counter++)
	{
		USART_voidSend(Password[USART_Counter]);
		_delay_ms(10);
	}
	/*flag to determine that the process of transmitting is finished*/
	Send_Password_flag=1;
}
/*Function used to Close the door after being opened by sending specific Number to MICRO-controller2*/
void Close_Door(void)
{
	u8 Local_command;
	CLCD_voidClearDisplay();
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("To Close Door");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("Press '5' ");
	_delay_ms(500);

	Local_command=KPD_u8GetPressedKey();
	while(Local_command == '\0')
		{
			Local_command=KPD_u8GetPressedKey();
		}
	if(Local_command =='5')
	{
		USART_voidSend('5');
		/*flag =1 to indicate that process of sending the number is done*/
		Close_door_flag=1;
	}
	else if(Local_command != '5')
	{
		CLCD_voidClearDisplay();
		CLCD_voidSendString("Unknown Command");
		_delay_ms(500);
		/*flag =0 to indicate that number entered is wrong*/
		Close_door_flag=0;
	}

}

void Display_Status(void)
{
	u8 Received_Data;
	Received_Data=USART_u8Receive();
	switch(Received_Data)
	{
	case 1:
		//CLCD_voidClearDisplay();
		//CLCD_voidSendString("Door is Open");
		//_delay_ms(500);
		/*flag =1 to indicate that door is opened*/
		Display_status_flag=1;
		break;
	case 2:
		//CLCD_voidClearDisplay();
		//CLCD_voidSendString("Wrong Password!");
		//_delay_ms(500);
		/*flag =2 to indicate that password sent is wrong*/
		Display_status_flag=2;
		break;
	case 3:
		//CLCD_voidClearDisplay();
		//CLCD_voidSendString("Door is Close");
		//_delay_ms(500);
		/*flag =3 to indicate that door is closed after being opened*/
		Display_status_flag=3;
		break;
	default:
		//CLCD_voidClearDisplay();
		//CLCD_voidSendString("ERROR");
		/*flag =4 to indicate error*/
		Display_status_flag=4;
	}

}

void APP_Init(void)
{
	MC1_Init();
}
/*Application implementation*/
void APP_Start(void)
{
	Take_Password();
	if(Password_flag==1)
	{
		Send_Password();
		if(Send_Password_flag==1)
		{
			Display_Status();
			switch(Display_status_flag)
			{
			case 1:
				CLCD_voidClearDisplay();
				CLCD_voidSendString("Door is Open");
				_delay_ms(500);
				Close_Door();
				while(Close_door_flag==0)
				{
					Close_Door();
				}
				Display_Status();
				if(Display_status_flag==3)
				{
					CLCD_voidClearDisplay();
					CLCD_voidSendString("Door is Close");
					_delay_ms(500);
				}
				break;
			case 2:
				CLCD_voidClearDisplay();
				CLCD_voidSendString("Wrong Password!");
				_delay_ms(500);
				break;
			default:
				CLCD_voidClearDisplay();
				CLCD_voidSendString("ERROR");
			}
		}
	}
}

