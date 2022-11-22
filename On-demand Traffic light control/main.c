/*
 * On-demand Traffic light control.c
 *
 * Created: 11/9/2022 9:45:21 PM
 * Author : Youssef
 */ 

#include "Application/app.h"


int main(void)
{  
	// DIO driver test cases
	//DIO_init(6 , PORT_B , OUT);
	//DIO_init(3 , PORT_A , OUT);
	
	//Timer driver tests
	//DIO_init(7 , PORT_D , OUT);
	//timer_0_init();
	
	// button driver test 
	//Button_init(2 , PORT_D); // initialize button as input and INT0 interrupt is on
	//DIO_init(7 , PORT_D , OUT);
	
	//led driver tests
	//LED_init(7,PORT_D);
	//LED_init(3,PORT_D);
	
	App_init();
    while (1) 
    {	
		
		// DIO driver test cases
		
		//DIO_Write(6 , PORT_B , LOW);
		//DIO_Write(3 , PORT_A , HIGH);
		//DIO_Toggle(7 , PORT_D);
		//delay_ms(500);
		
		//Timer driver tests
		//DIO_Toggle(7 , PORT_D);
		////delay_ms(2000);
		//delay_ms(8000);
		
		//LED driver tests
		//LED_on(7, PORT_D);
		//LED_off(3, PORT_D);
		//LED_toggle(7, PORT_D);
		//delay_ms(500);
		//LED_blink(7, PORT_D);
		//LED_blink_two(7, PORT_D , 3 , PORT_D);
		
		
		App_start();
    }
}

// button driver tests

//ISR(EXT_INT_0){
	//DIO_Toggle(7 , PORT_D);
//}