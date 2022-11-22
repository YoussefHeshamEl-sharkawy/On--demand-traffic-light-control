/*
 * Dio.h
 *
 * Created: 11/9/2022 10:09:44 PM
 *  Author: Youssef
 */ 


#ifndef DIO_H_
#define DIO_H_

// includes
#include "../../Utilities/bit_operations.h"
#include "../../Utilities/Registers.h"
// define driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// define direction macros
#define IN 0
#define OUT 1
//define output value macros
#define LOW 0
#define HIGH 1

// define interrupt macros

#define EXT_INT_0 __vector_1

#define ISR(INT_VECT)void INT_VECT(void)__attribute__((signal , used));\
void INT_VECT(void)

// Driver function prototypes
System_Error_t DIO_init(uint8_t pinnum , uint8_t portnum , uint8_t direction); // initialize the direction if the pin (input or output)

System_Error_t DIO_Write(uint8_t pinnum , uint8_t portnum , uint8_t Value); // write high or low on pin

System_Error_t DIO_Toggle(uint8_t pinnum , uint8_t portnum ); // toggle the value on pin 

System_Error_t interrupt_init_0();// initiate external interrupt on INT0 

#endif /* DIO_H_ */