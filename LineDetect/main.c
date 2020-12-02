//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//  Mohammad Ahmad
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V7.12.4
// ------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

// Function Prototypes
void main(void);

  // Global Variables
volatile char slow_input_down;
extern char display_line[DISPLAYSIZE][DISPLAYLENGTH];
extern char *display[DISPLAYSIZEPNTR];
unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
extern int ADC_Left_Detect;
extern int ADC_Right_Detect;
extern volatile char one_time;
extern int bigdoinkcount;
unsigned int test_value;
char chosen_direction;
char change;
int sec = NOTHING;
int process = NOTHING;
int directline = NOTHING;
int followline = NOTHING;
extern int timerboii;
extern int mstr;
extern int turncnt;
//extern int LEFTWHITE;
extern int BLACKDETECT;
int linefound =0;


void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                         // Initialize Ports
  Init_Clocks();                        // Initialize Clock System
  Init_Conditions();                    // Initialize Variables and Initial Conditions
  Init_Timer_B0();                      // Initialize Timers
  Init_Timer_B3();                      // Initialize Timers
  Init_LCD();                           // Initialize LCD
  Init_ADC();
  //P4IFG |= SW1;
// Place the contents of what you want on the display, in between the quotes
// Limited to 10 characters per line
//

  

  strcpy(display_line[DISPLAYLINE1], "          ");
  update_string(display_line[DISPLAYLINE1], DISPLAYLINE1);
  strcpy(display_line[DISPLAYLINE2], "          ");
  update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
  strcpy(display_line[DISPLAYLINE3], "          ");
  update_string(display_line[DISPLAYLINE3], DISPLAYLINE3);
  strcpy(display_line[DISPLAYLINE4], " Mohammad ");
  update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
  enable_display_update();
  display_changed= ALWAYS;

//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      // Can the Operating system run
    if (linefound ==0){
    switch(process) {
    case (STEP0) :
      Fwd_Fun();
      process = STEP1;
      
      break;
  case (STEP1):
   if (ADC_Left_Detect > BLACKDETECT && ADC_Right_Detect > BLACKDETECT){
     Stopthe_Fun();
     process = STEP2;
   }
   break;
    case (STEP2):
      Clock_Fun();
      process = STEP3;
      break;
    case (STEP3):
     if (ADC_Left_Detect < BLACKDETECT &&
         ADC_Right_Detect > BLACKDETECT ){
     Stopthe_Fun();
     process = STEP4; 
     }
     break;
      case (STEP4):
        Stopthe_Fun();
        linefound =1;
        break;
   }
    }
    if (linefound ==1){
      switch (directline) {
      case (LEFT):
        Left_Fun();
        break;
      case (RIGHT):
        Right_Fun();
        break;
      case (STRAIGHT):
        Fwd_Fun();
        break;
      }
    }
    
    adc_line4(NOTHING);
    Display_Process();
    Check_Line();
  
  }
//------------------------------------------------------------------------------
}





