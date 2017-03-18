#ifndef __ECE353_INTERRUPTS_H__
#define __ECE353_INTERRUPTS_H__

#include <stdint.h>
#include <stdbool.h>
#include "TM4C123.h"
#include "serial.h"

extern volatile int count;
extern volatile bool ALERT_TX_DONE;
extern volatile bool ALERT_RX_DATA;

//*****************************************************************************
// GPIOA_Handler is used to detect when the start bit on the Rx line has 
// been received.  The handler will enable TIMER0B so that it generates a 
// timer interrupt that is four times as fast as the baud rate.  Make sure that 
// you reload the current value of the timer with the correct interval before
// you enable Timer0B.
//
// The GPIOA handler should disable itself once the start bit is detected.  
// The GPIOA handler will be re-enabled when the STOP bit has finished 
// being received by the Timer0B Handler.
//*****************************************************************************
void GPIOA_Handler(void);

//*****************************************************************************
// Timer0A will be used to transmit data.  One all 10-bits of data hass been
// transmitted, it will disable itself and set ALERT_TX_DONE to true.
//*****************************************************************************
void TIMER0A_Handler(void);

//*****************************************************************************
// TIMER0B is used to sample the Received data at four times the rate at
// which the data is being received.  
//
// By sampling at 4 times the data rate, we can oversample the data on the Rx
// line and reduce the chances that noise on the line results in corrupted
// data.
//
// Each bit of data being received will be present on the Rx pin for 4 TIMER0B 
// interrupts.  For each bit, read in the value on the Rx line for the first 
// three interrupts.  You will then use a majority vote of those three samples
// to determine if the bit was either a one or a zero.
// 
// The 4th interrupt for each bit should be ignored since we would expect the 
// data to transition at that time.
//  
// After the final TIMER0B interrupt for the STOP bit has occurred, disable the
// TIMER0B interrupt and indicate that a byte of data has arrived to the main
// application.  The TIMER0B ISR should re-enable the GPIOA interrupt used to
// detect the START bit of a new data packet.  Be sure to clear any oustanding
// GPIOA interrupts prior to re-enabling interrupts.
//*****************************************************************************
void TIMER0B_Handler(void);

#endif
