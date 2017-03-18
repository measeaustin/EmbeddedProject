#ifndef __TIMERS_H__
#define __TIMERS_H__

#include <stdint.h>
#include <stdbool.h>
#include "TM4C123.h"
#include "driver_defines.h"

//******************************************************************************
// Description
// Enables the clock gating register for Timer 0.  This function should busy 
// wait until Timer0 is ready and then return
//
// Parameters
//  None
// Returns
//  Nothing
//*****************************************************************************
void timer0_enable_sysctrl(void);

//******************************************************************************
// Description
// Configures the A timer of Timer 0.  This function should fully configure 
// Timer0A, but it should not enable the timer to begin counting.
//
// Parameters
//  ticks       - value used to initialize the load register
//  mode        - configures the mode register (TAMR).
//  enable_irq  - true enables interrupts from the timer.
//  
// Returns
//  Nothing
//*****************************************************************************
void timer0_configA(uint16_t ticks, uint32_t mode, bool enable_irq);


//******************************************************************************
// Description
// Configures the B timer of Timer 0.  This function should fully configure 
// Timer0B, but it should not enable the timer to begin counting.
//
// Parameters
//  ticks       - value used to initialize the load register
//  mode        - configures the mode register (TBMR).
//  enable_irq  - true enables interrupts from the timer.
//  
// Returns
//  Nothing
//*****************************************************************************
void timer0_configB(uint16_t ticks, uint32_t mode, bool enable_irq);

#endif
