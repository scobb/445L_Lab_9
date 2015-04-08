// main.c
// Runs on LM4F120/TM4C123
// UART runs at 115,200 baud rate 
// Daniel Valvano
// May 23, 2014

/* This example accompanies the books
  "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
  ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2014

"Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
 
 Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include <stdio.h>
#include <stdint.h> // C99 variable types
//#include "ADCSWTrigger.h"
#include "ADCT0ATrigger.h"
#include "PLL.h"

void Output_Init(void);
/*
int main(void){ 
	PLL_Init();
  Output_Init();              // initialize output device
	printf("hello world\n");
	// 1000 Hz with clock at 50MHz
	ADC0_InitTimer0ATriggerSeq3(9, 50000);
	while (cnt < 1000);
	for (int i = 0; i < 1000; ++i){
		printf("%d\n", result[i]);
	}
	while (1);
}
*/
void convert_to_temperature(int* val) {
	
}
int main() {
	PLL_Init();
  Output_Init();              // initialize output device
	printf("hello world\n");
	// 100 Hz with clock at 50MHz
	ADC0_InitTimer0ATriggerSeq3(9, 500000);
	while (1) {
		while (!ADC_ready);
		int my_val = ADC_val;
		ADC_ready = FALSE;
		convert_to_temperature(&my_val);
		printf("%d", my_val);
	}
	
}
