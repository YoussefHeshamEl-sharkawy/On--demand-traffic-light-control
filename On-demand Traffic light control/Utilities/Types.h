/*
 * Types.h
 *
 * Created: 11/9/2022 10:07:33 PM
 *  Author: Youssef
 */ 


#ifndef TYPES_H_
#define TYPES_H_


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef enum System_Error_t
{
	System_OK , System_Error //an error enum to be used a return value for the system functions
 }System_Error_t;

#endif /* TYPES_H_ */