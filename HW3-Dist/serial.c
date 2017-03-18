#include "serial.h"
#include "interrupts.h"
volatile bool ALERT_TX_DONE;
volatile bool ALERT_RX_DATA;


//*****************************************************************************
// Description
// Transmits a byte over PA1 using Timer0A.  This function will set 
// ALERT_TX_DONE to false and then enable Timer0A.  The function will busy wait
// until the Timer0A ISR sets ALERT_TX_DONE to true.
//
// Parameters
// c 	:		The 8 bits of data that will be transmitted
//  
// Returns
//  Nothing
//*****************************************************************************
void send_byte(char c){
	int i = 0;
	int bit;
	char* curr = c;
	ALERT_TX_DONE = false;
	//enable timer0A
	NVIC_EnableIRQ(TIMER0A_Handler);
	//send bit start bit(0)
	
	
	while(	ALERT_TX_DONE == false){}

	for (i = 7; i>-1; 1--){
		//get least significant bit
		bit = *curr >> i & 1;  // this may not work
		ALERT_TX_DONE = false;
		//send next bit least significant first
	
	
	
		while(ALERT_TX_DONE == false){}
	}
	ALERT_TX_DONE = false;
	//send out stop bit
	
	
	while(ALERT_TX_DONE == false){}
	Return;
}

//*****************************************************************************
// Description
// Busy waits for a byte of data to be received on PA0.  The function waits 
// until Timer0B ISR sets ALERT_RX_DATA to true.  Prior to returning the data,
// ALERT_RX_DATA should be set to false.
//
// The function should busy wait until a valid 10-bit packet has been received.
//
// Parameters
//  None
//  
// Returns
//  one byte of data (8-bits)
//*****************************************************************************
char receive_byte(void){
int packet = 0;
int sum = 0;
char c;
int i, j;
	for (i = 0; i < 10; i++ ){
		for(j = 0; j< 4; j++) 
			while (ALERT_RX_DATA == false){}
			// receive GPIO data bit and add it to sum
			if(j <3){
				sum += NULL;
			}
		}
		if (sum >= 2) 
			packet |= 1 << i;  
		else
			packet |= 0 << i;
	}
	return c = (packet >> 1) &= 0xFF; 
}