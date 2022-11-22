/*
 * app.c
 *
 * Created: 11/11/2022 9:52:17 PM
 *  Author: Youssef
 */ 
#include "app.h"

uint8_t is_pressed = 0; // starting by the button being not pressed
Operation_state current_state  = Normalmode; // starting in the normal operating mode

System_Error_t App_init(){
	// initialize all the led pins as output
	LED_init(RED , PORT_A);
	LED_init(GREEN , PORT_A);
	LED_init(Yellow , PORT_A);
	LED_init(RED , PORT_B);
	LED_init(GREEN , PORT_B);
	LED_init(Yellow , PORT_B);
	
	Button_init(2 , PORT_D); // initialize button as input and INT0 interrupt is on
	
	 next_color = GREEN;//starting from green
	 current_color = GREEN;//no previous color so initially its green
	 
	 return System_OK;
}



System_Error_t App_start(){
	
	if(current_state == Normalmode){ // checking the operation if its in the normal mode
		switch(next_color){ // switching on which state on the car traffic light should work now
			
			case RED: // car red led should be on for 5 secs and all the other leds are off except red led for pedestrian traffic which is always on in normal operating mode
				LED_off(GREEN , PORT_A);
				LED_off(Yellow , PORT_A);
				LED_on(RED , PORT_A);
				LED_off(GREEN , PORT_B);
				LED_off(Yellow , PORT_B);
				LED_on(RED , PORT_B);
				delay_ms(5000);
				
				if(current_state == Normalmode){ // only changing the sequence if the button is not pressed while the 5 seconds delay 
					next_color = Yellow; //setting next state to be yellow 
					current_color = RED;
				}
			break;
		
			case Yellow: // car yellow led should be blinking for 5 secs and all the other leds are off except red led for pedestrian traffic which is always on in normal operating mode
				LED_off(GREEN , PORT_A);
				LED_off(RED , PORT_A);
				LED_on(RED , PORT_B);
				LED_off(GREEN , PORT_B);
				LED_blink(Yellow , PORT_A);
				LED_off(Yellow , PORT_B);
				if(current_state == Normalmode){
					if(current_color == RED){ // checking which direction to go after the yellow based on previous cycle's on LED
						next_color = GREEN; // we came to yellow from red cycle so green will be on next
						current_color = Yellow;
						
						}else{
						next_color = RED;// we came to yellow from green cycle so red will be on next
						current_color = Yellow;
					}
				}
			break;
		
			case GREEN:// car green led should be on for 5 secs and all the other leds are off except red led for pedestrian traffic which is always on in normal operating mode
				LED_off(RED , PORT_A);
				LED_off(Yellow , PORT_A);
				LED_on(GREEN , PORT_A);
				LED_on(RED , PORT_B);
				LED_off(Yellow , PORT_B);
				LED_off(GREEN , PORT_B);
				delay_ms(5000);
				if(current_state == Normalmode){
				next_color = Yellow;
				current_color = GREEN;}
				break;
				default: break;
		}
	}
	else{ // when the operating mode is the pedestrian mode
		switch(next_color){ // switching on the state of car traffic light when pressing the button
			
			case RED: // car led should be red and pedestrian should be green for 5 seconds
			
				next_color = Yellow; 
				current_color = RED;
				LED_off(GREEN , PORT_A);
				LED_off(Yellow , PORT_A);
				LED_on(RED , PORT_A);
				LED_on(GREEN , PORT_B);
				LED_off(Yellow , PORT_B);
				LED_off(RED , PORT_B);
				delay_ms(5000);
				current_state  = Normalmode; // returning to normal mode after the green of pedestrian is on for 5 seconds
				is_pressed = 0; // enable us to take action if the button is pressed again as the operating mode in back to normal
				
			break;
			
			case Yellow: // blinking both yellow leds
			if(current_color == RED){ //setting next state color
					next_color = GREEN;
					current_color = Yellow;
					
					}else{
					next_color = RED;
					current_color = Yellow;
				}
					LED_off(GREEN , PORT_A);
					LED_off(RED , PORT_A);
					LED_off(GREEN , PORT_B);
					LED_off(RED , PORT_B);
					LED_blink_two(Yellow , PORT_A , Yellow , PORT_B);
					
			break;
			
			case GREEN: // if pressed when car led is green we will go to red case interrupting the car's green led light
				next_color = RED;
				current_color = GREEN;
				break;
	
			
			default: return System_Error; 
			
			
		}
	}
	return System_OK;
}


ISR(EXT_INT_0){
	if(is_pressed == 0){ // checking if the button is not pressed
		current_state = Pedestrianmode; // changing the operation state to pedestrian mode
		is_pressed = 1; // changed button state to be pressed
		timer_0_off(); // stop the delay function if any was operating when the button is pressed
		
		switch(next_color){// switching on the state of car traffic light when pressing the button
			
			case RED: // car's traffic led was red
				LED_on(GREEN , PORT_B);
				LED_off(Yellow , PORT_B);
				LED_off(RED , PORT_B);
				next_color = RED; // setting next state should be red in pedestrian mode
				break;
				
			case Yellow:  // car's traffic led was yellow
				stop_blinking_fun(); // stop blinking of the car's yellow led to start blinking both leds
				LED_off(GREEN , PORT_B);
				next_color = Yellow;// setting next state should be yellow in pedestrian mode
				break;
				
			case GREEN:  // car's traffic led was green
				LED_off(RED , PORT_B);
				LED_off(Yellow , PORT_B);
				LED_off(GREEN , PORT_B);
				next_color = Yellow;// setting next state should be yellow in pedestrian mode
				break;
				
			default:break;
		}
		
	}
}