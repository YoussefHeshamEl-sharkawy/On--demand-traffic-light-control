/*
 * app.h
 *
 * Created: 11/11/2022 9:52:28 PM
 *  Author: Youssef
 */ 


#ifndef APP_H_
#define APP_H_

//includes
#include "../ECUAL/Button Driver/Button.h"
#include "../ECUAL/LED Driver/Led.h"

typedef enum Operation_state{
	Normalmode , Pedestrianmode
	} Operation_state;

typedef enum Traffic_state{
	GREEN, Yellow , RED
} Traffic_state;

Traffic_state next_color;
Traffic_state current_color;


System_Error_t App_init();
System_Error_t App_start();



#endif /* APP_H_ */