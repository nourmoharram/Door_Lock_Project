#include"../../COMMON/STD_Types.h"
#include"../../MCAL/DIO/DIO_Header/DIO_Interface.h"
#include"CLCD_Interface.h"



void main(void)
{
	/*Initialize lcd pins*/
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);

	CLCD_voidInit();
	CLCD_voidSendData('N');
	CLCD_voidSendData('O');
	CLCD_voidSendData('U');
	CLCD_voidSendData('R');


	while(1)
	{

	}
}
