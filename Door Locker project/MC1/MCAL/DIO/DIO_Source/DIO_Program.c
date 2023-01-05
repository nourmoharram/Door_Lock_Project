/*
 * DIO_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Dell
 */

#include"../../../COMMON/Bit_wise.h"
#include"../../../COMMON/STD_Types.h"
#include"../DIO_Header/DIO_Interface.h"
#include"../DIO_Header/DIO_Register.h"
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<= DIO_u8PIN7)
	{
		if(Copy_u8Direction==DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8PORTB: CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8PORTC: CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8PORTD: CLR_BIT(DDRD,Copy_u8Pin); break;
			default: Local_u8ErrorState=1; break;

			}
		}
		else if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
						{
						case DIO_u8PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
						case DIO_u8PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
						case DIO_u8PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
						case DIO_u8PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
						default: Local_u8ErrorState=1; break;

						}
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	return Local_u8ErrorState=0;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: DDRA = Copy_u8Direction; break;
	case DIO_u8PORTB: DDRB = Copy_u8Direction; break;
	case DIO_u8PORTC: DDRC = Copy_u8Direction; break;
	case DIO_u8PORTD: DDRD = Copy_u8Direction; break;

	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<= DIO_u8PIN7)
		{
			if(Copy_u8Value==DIO_u8PIN_LOW)
			{
				switch(Copy_u8Port)
				{
				case DIO_u8PORTA: CLR_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB: CLR_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC: CLR_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD: CLR_BIT(PORTD,Copy_u8Pin); break;
				default: Local_u8ErrorState=1; break;

				}
			}
			else if(Copy_u8Value == DIO_u8PIN_HIGH)
			{
				switch(Copy_u8Port)
							{
							case DIO_u8PORTA: SET_BIT(PORTA,Copy_u8Pin); break;
							case DIO_u8PORTB: SET_BIT(PORTB,Copy_u8Pin); break;
							case DIO_u8PORTC: SET_BIT(PORTC,Copy_u8Pin); break;
							case DIO_u8PORTD: SET_BIT(PORTD,Copy_u8Pin); break;
							default: Local_u8ErrorState=1; break;

							}
			}

}
	return Local_u8ErrorState;

}
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8Port)
		{
		case DIO_u8PORTA: PORTA = Copy_u8Value; break;
		case DIO_u8PORTB: PORTB = Copy_u8Value; break;
		case DIO_u8PORTC: PORTC = Copy_u8Value; break;
		case DIO_u8PORTD: PORTD = Copy_u8Value; break;

		}
	return Local_u8ErrorState;

}
/*
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState=0;
	if((Copy_pu8Value != NULL) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: *Copy_pu8Value= GET_BIT(PINA , Copy_u8Pin); break;
		case DIO_u8PORTB: *Copy_pu8Value= GET_BIT(PINB , Copy_u8Pin); break;
		case DIO_u8PORTC: *Copy_pu8Value= GET_BIT(PINC , Copy_u8Pin); break;
		case DIO_u8PORTD: *Copy_pu8Value= GET_BIT(PIND , Copy_u8Pin); break;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
*/

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_return_data=0;
	if((Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: Local_return_data= GET_BIT(PINA , Copy_u8Pin); break;
		case DIO_u8PORTB: Local_return_data= GET_BIT(PINB , Copy_u8Pin); break;
		case DIO_u8PORTC: Local_return_data= GET_BIT(PINC , Copy_u8Pin); break;
		case DIO_u8PORTD: Local_return_data= GET_BIT(PIND , Copy_u8Pin); break;
		}
	}
	else
	{
		//Local_u8ErrorState=1;
	}
	return Local_return_data;
}
