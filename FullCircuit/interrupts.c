#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"
int mstr = 0;
extern int followline;
extern char display_line[DISPLAYSIZE][DISPLAYLENGTH];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern int blfix;
int numbcountr = NOTHING;
int sw1debounce = NOTHING;
int sw2debounce = NOTHING;
int dispupd = NOTHING;
int splash = NOTHING;
int timerboii = NOTHING;
int twosec = NOTHING;

volatile unsigned int usb_rx_ring_wr;
volatile unsigned int usb_rx_ring_rd;
volatile unsigned int usb_tx_ring_wr;
volatile unsigned int usb_tx_ring_rd;
volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile char USB_Char_Tx[SMALL_RING_SIZE] ;
int flag = NOTHING;
extern volatile unsigned int UCA1_index ;
extern volatile unsigned int UCA0_index ;
extern char test_command[LENNGTH];
extern int reset;
extern int baudboi;
extern int transfer;
int iotreset_flag = 0;
unsigned int command = 0;
volatile char iotringbuff[SMALL_RING_SIZE] ;
volatile char iotprocessbuff[32] ;
int part1 = 0;
int part2 = 0;
int ok = 0;
int dexter = 0;
volatile unsigned int dex;
char oldtemp = 'o';
char old2temp = 'o';
char ipaddress[15] = "";
unsigned int ipindex = 0;
int parse1 = 0;
int timeunit =0;
extern int direction;
char startpress[16] = "AT+NSTCP=42069,1";
char ip[10] = "AT+NSTAT=?";
int connect = 0; int findip = 0;
int indexer =0; int indexo = 0;
unsigned char temp1;
unsigned char temp;
extern int setip;
int queue = 0;
extern int direction2;
int timeunit2 = 0;
int ADC_Channel = NOTHING;
int ADC_Left_Detect = NOTHING;
int ADC_Right_Detect = NOTHING;
int ADC_THUMB = NOTHING;
extern int linefound;
int waittime = 10;

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
switch(__even_in_range(UCA0IV,EIGHT)){
case NOTHING: // Vector 0 - no interrupt
break;

case TWO: // Vector 2 - RXIFG


  temp = UCA0RXBUF; // RX -> USB_Char_Rx character
  UCA1TXBUF = temp;
  
    
      if (temp == '^'){
        command = 1;
      }
      if (command ==1 && temp == '1') {
        command =2;}
      if (command ==2 && temp == '2') {
        command =3;}
      if (command ==3 && temp == '3') {
        command =4;}
      if (command ==4 && temp == '4') {
        command =5;}
      if (command ==5  && temp == 'F') {
          direction2 = FORWARD;
          command =6;
      }
      else if (command ==5  && temp == 'B') {
          direction2 = REVERSE;
          command =6;
      }
      else if (command ==5  && temp == 'L') {
          direction2 = LEFT;
          command =6;
      }      
      else if (command ==5  && temp == 'R') {
          direction2 = RIGHT;
          command =6;
      }
      else if (command ==5  && temp == 'C') {
          direction2 = FINDBL;
          command =6;
      }
      else if (command ==5  && temp == 'O') {
          direction2 = 11;
          command =6;
      }
      else if (command ==5  && temp == 'T') {
          direction2 = 12;
          command =6;
      }
      else if (command ==5  && temp == 'H') {
          direction2 = 13;
          command =6;
      }
      else if (command ==5  && temp == 'P') {
          direction2 = 14;
          command =6;
      }
      else if (command ==5  && temp == 'K') {
          direction2 = 15;
          command =6;
      }
      else if (command ==5  && temp == 'M') {
          direction2 = 16;
          command =6;
      }
      else if (command ==5  && temp == 'N') {
          direction2 = 17;
          command =6;
      }
      else if (command ==5  && temp == 'Z') {
          direction2 = 18;
          command =6;
      }
      
      if (command ==6 && temp > '0' && temp < '9') {
          timeunit2 = temp - '0';
          timeunit2 = timeunit2 +timeunit2 +timeunit2;
          queue = queue + 1;
          command = 0;
      }
      
      
  iotringbuff[dex++] =temp;
      if (dex >= (sizeof(iotringbuff))){
      dex = BEGINNING; // Circular buffer back to beginning
    }

     iotprocessbuff[dexter] = iotringbuff[dex];
      dexter++;
      if (dexter >= (sizeof(iotprocessbuff))){
      dexter = BEGINNING; // Circular buffer back to beginning
    }

    if (old2temp == 'r' && oldtemp == '=') {
      parse1 = 1;
    }

    if ( parse1 == 1 && ipindex <15) {
      ipaddress[ipindex++] = temp;
    }
    old2temp = oldtemp;
    oldtemp = temp;
break;

  case FOUR: // Vector 4 – TXIFG
       
    break;
    
  default: break;
  }
}

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){

  switch(__even_in_range(UCA1IV,EIGHT)){
  case NOTHING: // Vector 0 - no interrupt
    break;
    
  case TWO: // Vector 2 - RXIFG
    
    if (!iotreset_flag) {
      iotreset_flag =1;
    }
    else {
    
    temp1 = UCA1RXBUF;
    UCA0TXBUF = temp1;
    }
    /*
    if (temp == 0x0D) {
    command =0;
  }

    
    if (command == 1) {
    if (temp == 'F') {
    reset = NOTHING;
    baudboi = ONE;
  }
    if (temp == 'S') {
    reset = NOTHING;
    baudboi = TWO;
  }
  }
    */


    
    
      USB_Char_Rx[usb_rx_ring_wr++] = temp1; // RX -> USB_Char_Rx character  
      if (usb_rx_ring_wr >= (sizeof(USB_Char_Rx))){
      usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
    }
    break;

    
  case FOUR: // Vector 4 – TXIFG
    
    
    break;
    
  default: break;
  }
}




#pragma vector=PORT4_VECTOR
__interrupt void switchP4_interrupt(void){
// Switch 1
if (P4IFG & SW1) {
  P4IFG &= ~SW1;

  connect = 1;
  indexer =0;


}
}


#pragma vector=PORT2_VECTOR
__interrupt void switchP2_interrupt(void){
  // Switch 2
 if (P2IFG & SW2) {
  P2IFG &= ~SW2; // IFG SW2 cleared

 // reset = NOTHING;
 // twosec = NOTHING;
  
  findip = 1;
  indexo =0;
  setip=0;
  
  /*if (baudboi == NOTHING || baudboi ==TWO) {
    baudboi = ONE;
  }
  else if (baudboi == ONE) {
    baudboi = TWO;
  }
    twosec = NOTHING;
    strcpy(display_line[DISPLAYLINE1], "          ");
    update_string(display_line[DISPLAYLINE1], DISPLAYLINE1);*/
    sw1debounce =NOTHING;
  
 }
}

#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void){
 switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
 case ADCIV_NONE:
 break;
 case ADCIV_ADCOVIFG: // When a conversion result is written to the ADCMEM0
 // before its previous conversion result was read.
 break;
 case ADCIV_ADCTOVIFG: // ADC conversion-time overflow
 break;
 case ADCIV_ADCHIIFG: // Window comparator interrupt flags
 break;
 case ADCIV_ADCLOIFG: // Window comparator interrupt flag
 break;
 case ADCIV_ADCINIFG: // Window comparator interrupt flag
 break;
 case ADCIV_ADCIFG: // ADCMEM0 memory register with the conversion result
    ADCCTL0 &= ~ADCENC; // Disable ENC bit.
    switch (ADC_Channel++){
      case ADCINT1: // Channel A2 Interrupt
        ADCMCTL0 &= ~ADCINCH_2; // Disable Last channel A2
        ADCMCTL0 |= ADCINCH_3; // Enable Next channel A3
        ADC_Left_Detect = ADCMEM0; // Move result into Global
        ADC_Left_Detect = ADC_Left_Detect >> TWO; // Divide the result by 4
        //HEXtoBCD(ADC_Left_Detect); // Convert result to String PUT IN MAIN
        //adc_line4(NOTHING); // Place String in Display X2(^(^^^
        break;
      case ADCINT2:
        ADCMCTL0 &= ~ADCINCH_3; // Disable Last channel A3
        ADCMCTL0 |= ADCINCH_5; // Enable Next channel A5
        ADC_Right_Detect = ADCMEM0; // Move result into Global
        ADC_Right_Detect = ADC_Right_Detect >> TWO; // Divide the result by 4
        //HEXtoBCD(ADC_Right_Detect); // Convert result to String
        //adc_line3(NOTHING); // Place String in Display
        break;
      case ADCINT3:
        ADCMCTL0 &= ~ ADCINCH_5; // Disable Last channel A5
        ADCMCTL0 |= ADCINCH_2; // Enable Next channel A2
        ADC_THUMB = ADCMEM0; // Move result into Global
        ADC_THUMB = ADC_THUMB >> TWO; // Divide the result by 4
      //  HEXtoBCD(ADC_THUMB); // Convert result to String
        //adc_line2(NOTHING); // Place String in Display
        ADC_Channel=NOTHING;
        break;
        default:
      break;
  }
 ADCCTL0 |= ADCENC; // Enable Conversions
 ADCCTL0 |= ADCSC; // Start next sample
default:
 break;
}


}
#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
//------------------------------------------------------------------------------
// TimerB0 0 Interrupt handler
//----------------------------------------------------------------------------
//...... Add What you need happen in the interrupt ......
  
  
  numbcountr++;
  sw1debounce++;
  sw2debounce++;
  if (numbcountr == TWOHUNDREDMS) { //UPDATES SCREEN WORDS EVERY 200 MSEC
        update_display= ALWAYS;
        numbcountr = NOTHING;
        mstr = mstr +TWO;;
        if (linefound ==2) {
          if (waittime >0) {
          waittime--;
          }
          else {
            linefound =1;
        }
        }
        splash++;
        twosec++;
        if (timeunit> 0) {
          timeunit--;
        }
  }
 
  switch (sw1debounce) { //HANDLES DEBOUNCE FOR SWITCH 1
  case (DEBOUNCETIP):
    P4IFG &= ~SW1;
    break;
  }
  switch (sw2debounce) { //HANDLES DEBOUNCE FOR SWITCH 2
  case (DEBOUNCETIP):
    P2IFG &= ~SW2;
    break;
  }


TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TBCCR0
//----------------------------------------------------------------------------
}


#pragma vector=TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR(void){
//----------------------------------------------------------------------------
// TimerB0 1-2, Overflow Interrupt Vector (TBIV) handler
//----------------------------------------------------------------------------
switch(__even_in_range(TB0IV,FOURTEEN)){
case NOTHING: break; // No interrupt
case TWO: // CCR1 not used
//...... Add What you need happen in the interrupt ......
TB0CCR1 += OFS_TB0CCR1; // Add Offset to TBCCR1
break;
case FOUR: // CCR2 not used
//...... Add What you need happen in the interrupt ......
TB0CCR2 += OFS_TB0CCR2; // Add Offset to TBCCR2
break;
case FOURTEEN: // overflow
//...... Add What you need happen in the interrupt ......
break;
default: break;
}
//----------------------------------------------------------------------------
}


