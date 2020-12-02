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
int process = 1;
int directline = NOTHING;
int followline = NOTHING;
extern int timerboii;
extern int mstr;
extern int turncnt;
//extern int BLACKDETECT;
extern volatile unsigned int usb_rx_ring_rd;
extern volatile unsigned int usb_rx_ring_wr;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
char test_command[LENNGTH] = "          ";
extern int splash;
volatile unsigned int UCA0_index = NOTHING;
volatile unsigned int UCA1_index = NOTHING;
int brw = BAUDONE;
int beef = BEEFONE;
int baudboi = ONE;
int reset = ONE;
extern int twosec;
int transfer = NOTHING;
int iotset = NOTHING;
extern int ok;
extern char ipaddress[15];
extern int parse1;
int direction = 0;
extern int timeunit;
int setip = 0;
extern char startpress[16];
extern int indexer, connect;
extern int indexo, findip;
extern char ip[10];
extern unsigned char temp1;
char tempo, tempi;
extern int timeunit2;
int direction2 = 0;
extern int queue;
int copied =0;
int stopcount =1;
int turned = 0;
int locatetime =0;
int linefound = 0;


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
  Init_Serial_UCA0();
  Init_Serial_UCA1();
  //P4IFG |= SW1;
// Place the contents of what you want on the display, in between the quotes
// Limited to 10 characters per line
//

  UCA0TXBUF = test_command[NOTHING];
  UCA1IE |= UCRXIE; // Enable RX interrupt
  TB0CCTL0 |= CCIE;



  strcpy(display_line[DISPLAYLINE1], "NEED INPUT");
  update_string(display_line[DISPLAYLINE1], DISPLAYLINE1);
  strcpy(display_line[DISPLAYLINE2], "          ");
  update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
  strcpy(display_line[DISPLAYLINE3], "          ");
  update_string(display_line[DISPLAYLINE3], DISPLAYLINE3);
  strcpy(display_line[DISPLAYLINE4], "          ");
  update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
  enable_display_update();
  display_changed= ALWAYS;

//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      // Can the Operating system run
    if (splash == 1 && iotset == NOTHING){
         P5OUT |= IOT_RESET;
         iotset =1;
    }
      if (indexer == 16) {
    UCA0TXBUF =  0x0D;
    indexer++;
    connect =0;
  }
      if (connect ==1) {
  if (indexer < 16){
  tempo = startpress[indexer];
  UCA0TXBUF = tempo;
  indexer++;
  }
  }
      if (indexo == 10) {
    UCA0TXBUF =  0x0D;
    indexo++;
    findip =0;
  }
      if (findip ==1) {
  if (indexo < 10){
  tempi = ip[indexo];
  UCA0TXBUF = tempi;
  indexo++;
  }
  }
    
  if (queue ==1 && copied ==0) {
    direction =direction2;
    timeunit = timeunit2;
    copied =1;
  }

    switch (direction) {
    case 0:
      if (stopcount ==0) {
        //strcpy(display_line[DISPLAYLINE3], "   STOP   "); 
      }
      Stopthe_Fun();

      if (queue> 0) {
        queue= 0; 
        timeunit = timeunit2;
        direction = direction2;
      }
      

      break;
      
    case FORWARD: //FORWARD
      if (timeunit >0) {
        strcpy(display_line[DISPLAYLINE1], " BLSTOP   ");
        Fwd_Fun();
      }
      else
        direction = 0;
        stopcount =0;
      //queue--;
      break;
      
    case REVERSE: //REVERSE
      if (timeunit >0) {
        Rivers_Fun();
      }
      else
        direction = 0;
        stopcount =0;
      //queue--;
      break;
      
    case LEFT: //LEFT
      if (timeunit >0) {
        AntiClock_Fun();
        strcpy(display_line[DISPLAYLINE1], " BLEXIT   ");
      }
      else
        direction = 0;
        stopcount =0;
      //queue--;
      break;
      
    case RIGHT: //RIGHT
      if (timeunit >0) {
        Clock_Fun();
      }
      else
        direction = 0;
        stopcount =0;
      //queue--;
      break;
      
    case FINDBL:
      //timeunit = 3;
      if (timeunit >0) {
        Clock_Fun();
        strcpy(display_line[DISPLAYLINE1], " BLSTART  ");
      }
      else {
        Stopthe_Fun();
          direction =6;
          Init_ADC();
                  Stopthe_Fun();

      }

      break;
    case 6:
      if (linefound ==0){
    switch(process) {
    case (STEP0) :
      strcpy(display_line[DISPLAYLINE1], "INTERCEPT ");
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
        linefound =2;
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
        
        break;
    case 11:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 1 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 12:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 2 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 13:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 3 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 14:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 4 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 15:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 5 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 16:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 6 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 17:
      strcpy(display_line[DISPLAYLINE1], "ARRIVED 7 ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
          case 18:
      strcpy(display_line[DISPLAYLINE1], "BLEXIT ");
                update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
          enable_display_update();
          display_changed= ALWAYS;
          timeunit =0;
          direction = 0;
      break;
      
    
      
      
      default: break;
    }
      
    
    
    
    if (parse1 ==1 &&setip ==0) {
        //lcd_4line();
        display_line[1][1] = ipaddress[0];
        display_line[1][2] = ipaddress[1];
        display_line[1][3] = ipaddress[2];
        display_line[1][4] = ipaddress[3];
        display_line[1][5] = ipaddress[4];
        display_line[1][6] = ipaddress[5];
        display_line[1][7] = ipaddress[6];
        display_line[1][8] = ipaddress[7];
        display_line[2][2] = ipaddress[8];
        display_line[2][3] = ipaddress[9];
        display_line[2][4] = ipaddress[10];
        display_line[2][5] = ipaddress[11];
        display_line[2][6] = ipaddress[12];
        display_line[2][7] = ipaddress[13];
        display_line[2][8] = ipaddress[14];
        update_string(display_line[DISPLAYLINE3], DISPLAYLINE3);
          enable_display_update();
          display_changed= ALWAYS;
        setip =1;
    }
    

                HEXtoBCD(mstr); // Convert result to String PUT IN MAIN
        adc_line2(NOTHING);
    
    //adc_line2(NOTHING);
    Check_Line();
    Display_Process();
    
  
  }
//------------------------------------------------------------------------------
}





