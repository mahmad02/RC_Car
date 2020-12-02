// ------------------------------------------------------------------------------
//
//  Description: This file contains the LCD INITIAL CONDITIONS
//
//  Mohammad Ahmad
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V7.12.4
// ------------------------------------------------------------------------------

#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <string.h>

extern char display_line[DISPLAYSIZE][DISPLAYLENGTH];
extern char *display[DISPLAYSIZEPNTR];
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;

void Init_Conditions(void){
//------------------------------------------------------------------------------
  int i;

  for(i=LOOPSTART;i<DISPLAYLENGTH;i++){
    display_line[DISPLAYLINE1][i] = RESET_STATE;
    display_line[DISPLAYLINE2][i] = RESET_STATE;
    display_line[DISPLAYLINE3][i] = RESET_STATE;
    display_line[DISPLAYLINE4][i] = RESET_STATE;
  }
  display_line[DISPLAYLINE1][DISPLAYCHAR10] = ZEROFORDISPLAY;
  display_line[DISPLAYLINE2][DISPLAYCHAR10] = ZEROFORDISPLAY;
  display_line[DISPLAYLINE3][DISPLAYCHAR10] = ZEROFORDISPLAY;
  display_line[DISPLAYLINE4][DISPLAYCHAR10] = ZEROFORDISPLAY;

  display[DISPLAYLINE1] = &display_line[DISPLAYLINE1][ZEROFORDISPLAY];
  display[DISPLAYLINE2] = &display_line[DISPLAYLINE2][ZEROFORDISPLAY];
  display[DISPLAYLINE3] = &display_line[DISPLAYLINE3][ZEROFORDISPLAY];
  display[DISPLAYLINE4] = &display_line[DISPLAYLINE4][ZEROFORDISPLAY];
  update_display = NODISPUPDATE;
  update_display_count = DISPUPDATECOUNT;
// Interrupts are disabled by default, enable them.
  enable_interrupts();
//------------------------------------------------------------------------------
}