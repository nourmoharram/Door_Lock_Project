/*
 * LCD_Interface.h
 *
 *  Created on: Dec 28, 2022
 *      Author: Dell
 */

#ifndef HAL_LCD_CLCD_INTERFACE_H_
#define HAL_LCD_CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(char *string);

//void CLCD_voidSendString(const char* ptr_string);

void CLCD_voidSendNumber(u8 *Copy_u8Num);

void CLCD_voidClearDisplay(void);

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

void CLCD_voidInit(void);

void CLCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

#endif /* HAL_LCD_CLCD_INTERFACE_H_ */
