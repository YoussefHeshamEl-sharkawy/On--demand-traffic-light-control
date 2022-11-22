/*
 * Button.h
 *
 * Created: 11/11/2022 9:48:07 PM
 *  Author: Youssef
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//includes
#include "../../MCAL/DIO Driver/Dio.h"


System_Error_t Button_init(uint8_t pinnum , uint8_t portnum); // initializing the button pin as interrupt

#endif /* BUTTON_H_ */