#include"../../COMMON/STD_Types.h"
#include"../../MCAL/DIO/DIO_Header/DIO_Interface.h"
#include"CLCD_Config.h"
#include"CLCD_Interface.h"
#include"CLCD_Private.h"
#include <util/delay.h>

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*set RS pin to low for sending commands*/
	DIO_u8SetPortDirection(CLCD_CTRL_PORT,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*SET RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Send command to data pins*/
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*set RS pin to high for sending data*/

		DIO_u8SetPortDirection(CLCD_CTRL_PORT,DIO_u8PORT_OUTPUT);

		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

		/*SET RW pin to low for write*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

		/*Send data to data pins*/
		DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);

		DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
		/*Send enable pulse*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2lines and 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control display enable,disable cursor and no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*clear display*/
	CLCD_voidSendCommand(0b00000001);


}

void CLCD_voidSendString(char *string)
{
	u8 counter;
	for(counter=0;string[counter]!=0;counter++)
	{
		CLCD_voidSendData(string[counter]);
	}
}
/*
void CLCD_voidSendString(const char* ptr_string)
{
	u8 Local_u8Counter=0;
	while(ptr_string[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(ptr_string[Local_u8Counter]);
		Local_u8Counter++;
	}
}

*/

void CLCD_voidSendNumber(u8 *Copy_u8Num)
{
	u8 Local_u8Counter;
	for(Local_u8Counter=0;Copy_u8Num[Local_u8Counter]!=0;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_u8Num[Local_u8Counter]+'0');
	}
}

void CLCD_voidClearDisplay(void)
{
	u8 data_clear_display= 0x01;
	CLCD_voidSendCommand(data_clear_display);
}


void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos == 0)
	{
		Local_u8Address = Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1)
	{
		Local_u8Address = Copy_u8YPos + 0x40;
	}
	//128 Is added to the address to set the most significant bit by 1 according to DDRAM address instruction
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Iterator;
	/*first calculate CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRamAddress =0;
	Local_u8CGRamAddress = Copy_u8PatternNumber*8;

	/*Access CGRAM block using function Send command by setting bit 6 and clearing bit7*/
	CLCD_voidSendCommand(Local_u8CGRamAddress+64);
	/*Write the pattern into CG ram*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_u8Pattern[Local_u8Iterator]);
	}

	/*Access the DDRAM again To display the pattern since the gotoxy function is carrying a function to access DDRAM*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/*Display the pattern written in the CG RAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);


}

