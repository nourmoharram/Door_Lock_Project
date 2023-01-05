/*
 * DIO_Register.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Dell
 */

#ifndef MCAL_DIO_DIO_HEADER_DIO_REGISTER_H_
#define MCAL_DIO_DIO_HEADER_DIO_REGISTER_H_

/*Address for the DDR Registers*/

#define DDRA    (*((volatile u8*)0x3A))
#define DDRB    (*((volatile u8*)0x37))
#define DDRC    (*((volatile u8*)0x34))
#define DDRD    (*((volatile u8*)0x31))
/*Address for the PORT Registers*/
#define PORTA    (*((volatile u8*)0x3B))
#define PORTB    (*((volatile u8*)0x38))
#define PORTC    (*((volatile u8*)0x35))
#define PORTD    (*((volatile u8*)0x32))

/*Address for the PIN Registers*/
#define PINA     (*((volatile u8*)0x39))
#define PINB     (*((volatile u8*)0x36))
#define PINC     (*((volatile u8*)0x33))
#define PIND     (*((volatile u8*)0x30))


#endif /* MCAL_DIO_DIO_HEADER_DIO_REGISTER_H_ */
