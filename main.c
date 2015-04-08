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
#include "ADCSWTrigger.h"

void Output_Init(void);

int main(void){ int32_t data;
  Output_Init();              // initialize output device
  ADC0_InitSWTriggerSeq3_Ch9();
	int32_t ADCVals[1000];
	for (int32_t i = 0; i < 1000; i++){
		for (int8_t j = 0; j < 124; j++){
			ADC0_InSeq3();
		}
		ADCVals[i] = ADC0_InSeq3();
	}
	
	printf("ADC Results\n");
	for (int32_t k = 0; k < 1000; k++){
		printf("%d", ADCVals[k]);
	}
	/*
  while(1){
    data = ADC0_InSeq3();
    printf("\nADC data =%d ",data);
  }
	*/
}
