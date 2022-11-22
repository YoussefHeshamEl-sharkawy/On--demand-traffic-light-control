/*
 * Timer.c
 *
 * Created: 11/11/2022 4:00:34 PM
 *  Author: Youssef
 */ 

// includes
#include "Timer.h"
#include <math.h>

#define cpu_freq 16000000 // frequency of CPU is 16MHz
#define prescaler 1024 // using the largest prescaler to increase the Max delay time

double T_max_delay; // max delay time of system in 1 overflow
double T_tick; // time taken for 1 cycle
uint8_t T_init_value; // starting counting value in TCNT0 register
uint32_t N_overflow = 0; // required number of overflows to be calculated to reach the required delay time
volatile uint32_t overflowcounter =0; // counting the number of overflows happened 


System_Error_t timer_0_init(){
	TCCR0 = 0x00; // Normal mode
	TCNT0 = 0x00; // Zero initial value
	return System_OK; // system worked without errors
}

System_Error_t delay_ms (uint16_t delaytime){
	timer_0_init();
	T_tick = (float) (prescaler)/(cpu_freq); // calculate time of 1 cycle
	T_max_delay = (float) T_tick * 256; // calculate max delay time in 1 overflow starting the timer from 0 
	
	if((delaytime*(0.001)) < T_max_delay){ // if the required delay time is less than max delay time then no number of overflow is required
		
		T_init_value = (T_max_delay - (delaytime*0.001))/T_tick; // calculating the required initial value
		TCNT0 = T_init_value; // starting the timer from the calculated initial value
	}
	else if((delaytime*(0.001)) == T_max_delay){ // required delay time is equal to the max delay time of timer 0
		
		TCNT0 = 0x00; // starting timer from zero
	}
	else{ // required delay time is larger than the max delay time of timer 0
		
		N_overflow = ceil((delaytime*0.001)/T_max_delay);
		T_init_value = (uint8_t) 256 - (((delaytime*0.001)/T_tick)/N_overflow);
		TCNT0 = T_init_value;
	}
	
	SET_BIT(TCCR0 , 0);// setting prescaler to be 1024 in TCCR0 register - CS00 bit
	CLR_BIT(TCCR0 , 1);// setting prescaler to be 1024 in TCCR0 register - CS01 bit
	SET_BIT(TCCR0 , 2);// setting prescaler to be 1024 in TCCR0 register - CS02 bit
	
	if(N_overflow == 0){ // if the needed delay time doesn't require the overflow of TCNT0 register
		
		while((TIFR & (1<<0)) == 0); // wait for timer overflow
		SET_BIT(TIFR , 0); // clear 1 from overflow flag
		
	}
	else{
		while (overflowcounter < N_overflow){ // when a number of overflows is required
			
			while((TIFR & (1<<0)) == 0); // wait for timer overflow
			
			SET_BIT(TIFR , 0); // clear 1 from overflow flag
			overflowcounter++; 
		}
		overflowcounter =0; // reset timer counter
	}
	

	TCCR0 = 0x00; // Stopping timer
	
	return System_OK; // system worked without errors
}

System_Error_t timer_0_off(){
	N_overflow = 0; // setting the number of required overflows to zero so that we can stop the while loop in the delay function
	return System_OK;
	
}