/*
 * Button.c
 *
 * Created: 11/11/2022 9:48:27 PM
 *  Author: Youssef
 */ 
#include "Button.h"


System_Error_t Button_init(uint8_t pinnum , uint8_t portnum){
	DIO_init(pinnum , portnum , IN); // initialize pin as input
	interrupt_init_0(); // initializing INT0 interrupt 
	return System_OK;
}