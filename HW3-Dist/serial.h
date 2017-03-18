#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdint.h>
#include <stdbool.h>
#include "TM4C123.h"
#include "gpio_port.h"


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
void send_byte(char c);

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
char receive_byte(void);

#endif
