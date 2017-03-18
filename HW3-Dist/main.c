//*****************************************************************************
// main.c
// Author: jkrachey@wisc.edu
//*****************************************************************************
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "TM4C123.h"
#include "serial.h"
#include "timers.h"

//*****************************************************************************
// Complete this function that initializes all of the required hardeware 
// peripherals
//*****************************************************************************
void init_hardware(void)
{
	//enable GPIO send pin
	
	
	//enable GPIO receive pin
	
	
	//enable timer
	timer0_enable_sysctrl();
	//setup tiemr A
	// bod rate of 0.10416 milliseconds. ==  0.10416×10^-3×50×10^6 = 5208clock cycles
	timer0_configA(5208, TIMER_TAMR_TAMR_PERIOD, True);
	//setup tiemr B
	//oversample 4X per bod rate
	timer0_configA(5208/4, TIMER_TAMR_TAMR_PERIOD, True);
	
	//enable interrupts
	NVIC_EnableIRQ(GPIOA_Handler);
	
}

void print_string(char *string)
{
		if ( string != 0)
		{
			while( *string != '\0')
			{
				send_byte(*string);
				string++;
			}
		}
}

void get_input(void)
{
	char input;
	
	do
	{
		input = receive_byte();
		send_byte(input);
	} while ( input != '\n' && input != '\r');
}

//*****************************************************************************
//*****************************************************************************
int 
main(void)
{
  
		init_hardware();
		
		
  // Reach infinite loop
  while(1){
	print_string("\n\r\n\rEnter Characters: ");
	get_input();
	};
}
