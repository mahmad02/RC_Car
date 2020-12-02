#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"
extern int followline;
extern char display_line[DISPLAYSIZE][DISPLAYLENGTH];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern int blfix;
int numbcountr = NOTHING;
int sw1debounce = NOTHING;
int sw2debounce = NOTHING;
int dispupd = NOTHING;
int bigdoinkcount = NOTHING;
int ADC_Channel = NOTHING;
int ADC_Left_Detect = NOTHING;
int ADC_Right_Detect = NOTHING;
int ADC_THUMB = NOTHING;
int ircounter = NOTHING;
extern int process;
int timerboii = NOTHING;
int mstr = LOWINITVAL;
int turncnt = NOTHING;
int BLACKDETECT = NOTHING;
int timestr = NOTHING;


//int LEFTWHITE = NOTHING;
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
        HEXtoBCD(ADC_Left_Detect); // Convert result to String PUT IN MAIN
        adc_line4(NOTHING); // Place String in Display X2(^(^^^
        break;
      case ADCINT2:
        ADCMCTL0 &= ~ADCINCH_3; // Disable Last channel A3
        ADCMCTL0 |= ADCINCH_5; // Enable Next channel A5
        ADC_Right_Detect = ADCMEM0; // Move result into Global
        ADC_Right_Detect = ADC_Right_Detect >> TWO; // Divide the result by 4
        HEXtoBCD(ADC_Right_Detect); // Convert result to String
        adc_line3(NOTHING); // Place String in Display
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

#pragma vector=PORT4_VECTOR
__interrupt void switchP4_interrupt(void){
// Switch 1
if (P4IFG & SW1) {

  if (BLACKDETECT ==NOTHING) {
    BLACKDETECT = ADC_Right_Detect;}
    P4IFG &= ~SW1; // IFG SW1 cleared
  
//  TB0CCTL0 |= CCIE;

          sw1debounce =NOTHING;
}
}


#pragma vector=PORT2_VECTOR
__interrupt void switchP2_interrupt(void){
  // Switch 2
 if (P2IFG & SW2) {
  P2IFG &= ~SW2; // IFG SW2 cleared
  //TB0CCTL1 |= CCIE;
  TB0CCTL0 |= CCIE;
    ircounter++; 
    mstr = NOTHING;
    timestr = ONE;
  switch (ircounter){
 case (ONE):
      P3OUT |= IR_LED;
      break;
 case (TWO):
    P3OUT &= ~IR_LED;
    ircounter = NOTHING;
    break;
  }
 }
}


#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
//------------------------------------------------------------------------------
// TimerB0 0 Interrupt handler
//----------------------------------------------------------------------------
//...... Add What you need happen in the interrupt ......
  if (followline == ONE){
  timerboii++;
  }
  
  numbcountr++;
  turncnt++;
  sw1debounce++;
  sw2debounce++;
  if (numbcountr == TWOHUNDREDMS) { //UPDATES SCREEN WORDS EVERY 200 MSEC
    if (mstr <TWOCIRC && timestr ==ONE){
        mstr = mstr +TWO;;
    HEXtoBCD(mstr); // Convert result to String PUT IN MAIN
        adc_line2(NOTHING); // Place String in Display X2(^(^^^
        timerboii =NOTHING;

    }
        update_display= ALWAYS;
        numbcountr = NOTHING;
        
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
  if (process == NOTHING && ircounter == ONE && bigdoinkcount >15) {
    process = STEP0;
  }

        if (mstr == TWOCIRC && followline ==ONE) {
          followline = TWO;
          turncnt =NOTHING;
        }
  bigdoinkcount++;

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


