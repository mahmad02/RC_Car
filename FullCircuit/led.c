// ------------------------------------------------------------------------------
//
//  Description: This file contains the LED INITIALIZATION
//
//  Mohammad Ahmad
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V7.12.4
// ------------------------------------------------------------------------------

#include  "functions.h"
#include  "msp430.h"
#include "macros.h"


void Init_LEDs(void){
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
// Turns on both LEDs
  P1OUT &= ~RED_LED;
  P6OUT &= ~GRN_LED;
//------------------------------------------------------------------------------
}