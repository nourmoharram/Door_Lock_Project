
#include"../../COMMON/STD_Types.h"

#include"../../MCAL/DIO/DIO_Header/DIO_Interface.h"
//#include"../../MCAL/PORT/PORT_Header/PORT_Interface.h"
#include"Keypad_config.h"
#include"Keypad_interface.h"
#include"Keypad_private.h"
#include<util/delay.h>

void KEYPAD_Init(void)
{
	/*Define Row bins as Input*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_INPUT);
	/*Define column pins as OUTPUT*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_OUTPUT);
	/*Define Row bins as pulled up*/
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
	/*Define Columns pins as High*/
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);
}



char KPD_u8GetPressedKey(void)
{
	char Local_u8PressedKey=NOT_PRESSED;
	u8 Local_u8ColumnIndex;
	u8 Local_u8RowIndex;
	//u8 Local_u8Pinstate;
	static u8 Local_u8KPDArr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	static u8 Local_u8KPDColumnArr[4]={4,5,6,7};
	static u8 Local_u8KPDRowArr[4]={0,1,2,3};

	//DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<4;Local_u8ColumnIndex++)
	{
		/*De-Activate current column*/
		DIO_u8SetPinValue(DIO_u8PORTA,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);

		/*Check rows*/
		for(Local_u8RowIndex=0;Local_u8RowIndex<4;Local_u8RowIndex++)
		{
			/*Read current row*/
			//Local_u8Pinstate= DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex]);
			/*check if switch is pressed*/
			if(DIO_u8GetPinValue(DIO_u8PORTA,Local_u8KPDRowArr[Local_u8RowIndex]) == DIO_u8PIN_LOW)
			{
				//DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);

				_delay_ms(50);

				Local_u8PressedKey= Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];

				/*Busy waiting until button is released*/
				while(DIO_u8GetPinValue(DIO_u8PORTA,Local_u8KPDRowArr[Local_u8RowIndex])==DIO_u8PIN_LOW)
				{
					Local_u8PressedKey= Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				}
				/*return value of button pressed*/
				//return Local_u8PressedKey;
				//_delay_ms(5);

				break;
			}
		}

		/*Deactivate the current column*/
		DIO_u8SetPinValue(DIO_u8PORTA,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
