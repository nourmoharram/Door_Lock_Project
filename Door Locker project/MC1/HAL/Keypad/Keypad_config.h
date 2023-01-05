/*
 * Keypad_config.h
 *
 *  Created on: Dec 27, 2022
 *      Author: Dell
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define KPD_PORT     DIO_u8PORTA

#define KPD_COLUMN0_PIN       DIO_u8PIN4
#define KPD_COLUMN1_PIN       DIO_u8PIN5
#define KPD_COLUMN2_PIN       DIO_u8PIN6
#define KPD_COLUMN3_PIN       DIO_u8PIN7


#define KPD_ROW0_PIN          DIO_u8PIN0
#define KPD_ROW1_PIN          DIO_u8PIN1
#define KPD_ROW2_PIN          DIO_u8PIN2
#define KPD_ROW3_PIN          DIO_u8PIN3

#define NOT_PRESSED  '\0'

#define KPD_ARR_VALUES      {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
