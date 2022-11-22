/*
 * Dio.c
 *
 * Created: 11/9/2022 10:09:55 PM
 *  Author: Youssef
 */ 
#include "Dio.h"

System_Error_t DIO_init(uint8_t pinnum , uint8_t portnum , uint8_t direction){
	switch(portnum){ // switching cases on the inputed port
		case 'A': 
			if(direction == IN){
				CLR_BIT(DDRA , pinnum); // putting zero in the required bit to set it to input mode
				}
			else if(direction == OUT){
				SET_BIT(DDRA , pinnum); // putting one in the required bit to set it to output mode
				}
				else{// if the direction of the pin is inputed in a wrong way
					return System_Error;//error message
				}
		break;
		
		case 'B':
			if(direction == IN){
				CLR_BIT(DDRB , pinnum);
			}
			else if(direction == OUT){
				SET_BIT(DDRB , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		case 'C':
			if(direction == IN){
				CLR_BIT(DDRC , pinnum);
			}
			else if(direction == OUT){
				SET_BIT(DDRC , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		case 'D':
			if(direction == IN){
				CLR_BIT(DDRD , pinnum);
	
			}
			else if(direction == OUT){
				SET_BIT(DDRD , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		default:
			return System_Error;//error message
		
	}
	
		return System_OK;// system worked without errors
}

System_Error_t DIO_Write(uint8_t pinnum , uint8_t portnum , uint8_t Value){
	switch(portnum){
		case 'A':
			if(Value == LOW){
				CLR_BIT(PORTA , pinnum);
			}
			else if( Value == HIGH){
				SET_BIT(PORTA , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		case 'B':
			if(Value == LOW){
				CLR_BIT(PORTB , pinnum);
			}
			else if( Value == HIGH){
				SET_BIT(PORTB , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		case 'C':
			if(Value == LOW){
				CLR_BIT(PORTC , pinnum);
			}
			else if( Value == HIGH){
				SET_BIT(PORTC , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		case 'D':
			if(Value == LOW){
				CLR_BIT(PORTD , pinnum);
			}
			else if( Value == HIGH){
				SET_BIT(PORTD , pinnum);
			}
			else{
				return System_Error;//error message
			}
		break;
		
		default:
		 return System_Error; // error message
		
	}
	return System_OK;// system worked without errors
	
}

System_Error_t DIO_Toggle(uint8_t pinnum , uint8_t portnum ){
	switch(portnum){
		case 'A':
		TOGGLE_BIT(PORTA , pinnum); // changing the value stored in the bit from 0 to 1 and vice versa
		break;
		
		case 'B':
		TOGGLE_BIT(PORTB , pinnum);
		break;
		
		case 'C':
		TOGGLE_BIT(PORTC , pinnum);
		break;
		
		case 'D':
		TOGGLE_BIT(PORTD , pinnum);
		break;
		
		default: return System_Error;
		
	}
		return System_OK;// system worked without errors
}


System_Error_t interrupt_init_0(){
		SET_BIT(SREG , 7); // enable global interrupt
		SET_BIT(MCUCR , 0); SET_BIT(MCUCR , 1); // choosing external interrupts on rising edge in INT0 by setting ISC00 and ISC01 to 1
		SET_BIT(GICR , 6); // enable external interrupt 0 
		return System_OK;// system worked without errors	
	
}