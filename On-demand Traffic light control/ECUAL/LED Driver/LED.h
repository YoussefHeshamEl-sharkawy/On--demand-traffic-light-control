/*
 * Led.h
 *
 * Created: 11/10/2022 11:40:49 PM
 *  Author: Youssef
 */ 


#ifndef LED_H_
#define LED_H_
//includes
#include "../../MCAL/DIO Driver/Dio.h"
#include "../../MCAL/Timer Driver/Timer.h"

// function prototypes

System_Error_t LED_init(uint8_t ledpin , uint8_t ledport); // initiate led pin and port to be output and initially low
System_Error_t LED_on(uint8_t ledpin , uint8_t ledport); // turn the led on
System_Error_t LED_off(uint8_t ledpin , uint8_t ledport); // turn the led off
System_Error_t LED_toggle(uint8_t ledpin , uint8_t ledport); // toggle the state of the led
System_Error_t LED_blink(uint8_t ledpin , uint8_t ledport); // blink the given led for 5 seconds changing its state every 500ms
System_Error_t LED_blink_two(uint8_t ledpin1 , uint8_t ledport1, uint8_t ledpin2 , uint8_t ledport2); // blink the two given led s for 5 seconds changing its state every 500ms
System_Error_t stop_blinking_fun(); // stop the blinking led interrupting the blink function


#endif /* LED_H_ */