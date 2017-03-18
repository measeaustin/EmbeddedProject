#ifndef __UART_H__
#define __UART_H__

#include "driver_defines.h"

//************************************************************************
// Configure UART0 to be 115200, 8N1.  Data will be sent/recieved using
// polling (Do Not enable interrupts)
//************************************************************************
bool uart_init_115K(
  uint32_t base_addr, 
  uint32_t rcgc_mask, 
  uint32_t pr_mask, 
  IRQn_Type irq_mask,
  uint32_t  irq_priority

);


#endif
