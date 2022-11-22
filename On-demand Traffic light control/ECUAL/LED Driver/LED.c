/*
 * LED.c
 *
 * Created: 11/10/2022 11:41:07 PM
 *  Author: Youssef
 */ 
#include "LED.h"

uint8_t stop_blinking = 0;

System_Error_t LED_init(uint8_t ledpin , uint8_t ledport){
	DIO_init(ledpin , ledport , OUT); // initialize ledpin and port as output
	DIO_Write(ledpin , ledport , LOW); // setting the led pin as low at the beginning
	return System_OK; // system worked without errors
}

System_Error_t LED_on(uint8_t ledpin , uint8_t ledport){
	DIO_Write(ledpin , ledport , HIGH); // setting the led pin to HIGH
	return System_OK;// system worked without errors
}

System_Error_t LED_off(uint8_t ledpin , uint8_t ledport){
	DIO_Write(ledpin , ledport , LOW);// setting the led pin to LOW
	return System_OK;// system worked without errors
}

System_Error_t LED_toggle(uint8_t ledpin , uint8_t ledport){
	DIO_Toggle(ledpin , ledport); // toggling the value on ledpin
	return System_OK;// system worked without errors
}

System_Error_t LED_blink(uint8_t ledpin , uint8_t ledport){
	stop_blinking = 0; // initializing the stop blinking variable to zero the starting the blinking in for loop
	for(int i =0 ; i < 10 ; i++ ){
		if(! stop_blinking){ // checking if the stop blinking function changed the variable value to 1
			DIO_Toggle(ledpin , ledport); // change value of ledpin
			delay_ms(500);//delay 500ms
		}
	}
	return System_OK;// system worked without errors
}

System_Error_t LED_blink_two(uint8_t ledpin1 , uint8_t ledport1, uint8_t ledpin2 , uint8_t ledport2){
	stop_blinking = 0;
	
	for(int i =0 ; i < 10 ; i++ ){
		if(! stop_blinking){
	DIO_Toggle(ledpin1 , ledport1);
	DIO_Toggle(ledpin2 , ledport2);
	delay_ms(500);
	}
	}
	return System_OK;// system worked without errors
}

System_Error_t stop_blinking_fun(){
	stop_blinking = 1; // setting stop blinking variable to 1
	return System_OK;// system worked without errors
}