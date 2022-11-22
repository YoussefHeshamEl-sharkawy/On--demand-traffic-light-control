/*
 * bit_operations.h
 *
 * Created: 11/10/2022 9:07:43 PM
 *  Author: Youss
 */ 


#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

// function macros
#define SET_BIT(X,bitnum) X |=(1<<bitnum) // set bit macro
#define CLR_BIT(X,bitnum) X &=~(1<<bitnum) // clear bit macro
#define READ_BIT(X,bitnum) ((X & (1<<bitnum))>>bitnum) // read bit macro
#define TOGGLE_BIT(X,bitnum) X^=(1<<bitnum) // toggle bit macro


#endif /* BIT_OPERATIONS_H_ */