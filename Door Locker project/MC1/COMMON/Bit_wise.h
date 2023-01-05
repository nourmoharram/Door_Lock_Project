/*
 * Bit_wise.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Dell
 */

#ifndef  COMMON_BIT_WISE_H_
#define  COMMON_BIT_WISE_H_

#define SET_BIT(Register,Bit_No) (Register |=(1<<Bit_No))
#define CLR_BIT(Register,Bit_No) (Register &=(~(1<<Bit_No)))
#define TOG_BIT(Register,Bit_No) (Register ^=(1<<Bit_No))
#define GET_BIT(Register,Bit_No) ((Register>>Bit_No)&0x01)

#endif  /*COMMON_BIT_WISE_H_ */
