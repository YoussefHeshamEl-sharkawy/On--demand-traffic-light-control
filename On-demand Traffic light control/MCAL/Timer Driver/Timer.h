/*
 * Timer.h
 *
 * Created: 11/11/2022 4:00:44 PM
 *  Author: Youssef
 */ 

#ifndef TIMER_H_
#define TIMER_H_
//  driver includes

#include "../../Utilities/bit_operations.h"
#include "../../Utilities/Registers.h"

// Driver prototype functions

System_Error_t timer_0_init(); // initiate timer 0 in normal mode

System_Error_t delay_ms (uint16_t delaytime); // delay the given amount of time in millisecond using timer zero

System_Error_t timer_0_off(); //force stops the delay function 


#endif /* TIMER_H_ */