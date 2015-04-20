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
 /* Answers to prelab questions
 3 ways to trigger conversion: The controller (this is the default option), Timers, GPIO

How to know conversion is done: 
A raw interrupt is enabled from the ADCSSCTL3 register (or the register corresponding to
the correct sequencer) (found on page 821); cleared by writing a 1 to the IN*(0-3) bit in
the ADCISC register
*/

#include <stdio.h>
#include <stdint.h> // C99 variable types
#include "ADCT0ATrigger.h"
#include "PLL.h"
#include "ST7735.h"
#include "Display.h"

void Output_Init(void);
/*
int main(void){ 
	PLL_Init();
  Output_Init();              // initialize output device
	printf("hello world\n");
	// 1000 Hz with clock at 50MHz
	ADC0_InitTimer0ATriggerSeq3(9, 50000);
	while (cnt < 100);
	for (int i = 0; i < 100; ++i){
		printf("%d\n", result[i]);
	}
	while (1);
}*/
int main() {
	PLL_Init();
  Output_Init();              // initialize output device
	printf("Temperature:\n");
	// 100 Hz with clock at 50MHz
	ADC0_InitTimer0ATriggerSeq3(9, 500000);
  int num_samples = 0;
	double sum = 0.0;
	while (1) {
		while (!ADC_ready);
		int my_val = ADC_val;
		ADC_ready = FALSE;
		Display_drawScreen(my_val);
		/*sum += convert_to_temperature(my_val);
		++num_samples;
		if (num_samples >= 10){
		  double temp = sum / num_samples;
			num_samples = 0;
			sum = 0.0;
      ST7735_SetCursor(0,1);
		  printf("%.2f C", temp);
		}*/
		// printf("%4d", my_val);
	}
	
}
