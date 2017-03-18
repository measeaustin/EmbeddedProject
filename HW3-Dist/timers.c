#include "timers.h"
//#include "TM4C123.h"


//1 is enabled: 0 is disabled
#define TA_INTERRUPT_MASK 0x00000017 // may need RTCIM in bit #3
#define TB_INTERRUPT_MASK 0x00000F00
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
void timer0_enable_sysctrl(void){
	
	// Turn on the clock for the timer
  SYSCTL->RCGCTIMER |= SYSCTL_PRTIMER_R0;
	
  // Wait for the timer to turn on
  while( (SYSCTL->PRTIMER & SYSCTL_PRTIMER_R0) == 0) {};
		
		return;
	
}

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
void timer0_configA(uint16_t ticks, uint32_t mode, bool enable_irq){
	//typecast to a timer
	TIMER0_Type *gp_timer;

  	//mask my base
	gp_timer = (TIMER0_Type *) TIMER0_BASE;
		
	//Turn the timer off
	gp_timer->CTL &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);
	
	//Set timer for 16 bit mode
	gp_timer->CFG = TIMER_CFG_16_BIT;
	
	//set no inturrupts
	if (enable_irq){
		gp_tiemr->IMR |= TA_INTERRUPT_MASK;
	}else{
		gp_tiemr->IMR &= !TA_INTERRUPT_MASK;
	}
	
	// set TAMR to the mode (passed in via input arguments)
	gp_timer->TAMR = mode;
	
	//set the period
	gp_timer ->TAILR = ticks;
	
	//clear the "expired" status bits 
	gp_timer->ICR |= TIMER_ICR_TATOCINT;
	
	// //enable timer - this starts the countdown
	// gp_timer->CTL |= TIMER_CTL_TAEN; //does this start the countdown?
	
	// while ( (gp_timer->RIS & TIMER_RIS_TATORIS) == 0){}
	
}

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
void timer0_configB(uint16_t ticks, uint32_t mode, bool enable_irq){
	//typecast to a timer
	TIMER0_Type *gp_timer;

  	//mask my base
	gp_timer = (TIMER0_Type *) TIMER0_BASE;
		
	//Turn the timer off
	gp_timer->CTL &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);
	
	//Set timer for 16 bit mode
	gp_timer->CFG = TIMER_CFG_16_BIT;
	
	//set inturrupts
	if enable_irq{
		gp_tiemr->IMR |= TB_INTERRUPT_MASK;
	}else{
		gp_tiemr->IMR &= !TB_INTERRUPT_MASK;
	}
	// set TAMR to the mode (passed in via input arguments
	gp_timer->TAMR = mode;

	//set the period
	gp_timer ->TAILR = ticks;
	
	//clear the "expired" status bits 
	gp_timer->ICR |= TIMER_ICR_TATOCINT;


	
	// //enable timer - this starts the countdown
	// gp_timer->CTL |= TIMER_CTL_TAEN; //does this start the countdown?
	
	// while ( (gp_timer->RIS & TIMER_RIS_TATORIS) == 0){}
	
}