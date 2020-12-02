#include  "functions.h"
#include  "msp430.h"
#include "macros.h"
#include <string.h>

extern int ADC_Left_Detect;
extern int ADC_Right_Detect;
extern char display_line[DISPLAYSIZE][DISPLAYLENGTH];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
char adc_char[11] = "          ";
extern int ircounter;
extern int directline;
//extern int LEFTWHITE;
extern int BLACKDETECT;
//------------------------------------------------------------------------------
//******************************************************************************
// Hex to BCD Conversion
// Convert a Hex number to a BCD for display on an LCD or monitor
//
//------------------------------------------------------------------------------

void HEXtoBCD(int hex_value){
int value;
adc_char[NOTHING] = '0';
while (hex_value > NINEEE){
hex_value = hex_value - TENNN;
value = value + BCDONE;
adc_char[NOTHING] = CONVIRTY + value;
}


value = NOTHING;
while (hex_value > NINEE){
hex_value = hex_value - TENN;
value = value + BCDONE;
}
adc_char[BCDONE] = CONVIRTY + value;


value = NOTHING;
while (hex_value > NINE){
hex_value = hex_value - TEN;
value = value + BCDONE;
}
adc_char[BCDTWO] = CONVIRTY + value;


adc_char[BCDTHREE] = CONVIRTY + hex_value;
}
//******************************************************************************
//------------------------------------------------------------------------------

void adc_line4(int ok) {
  strcpy(display_line[DISPLAYLINE1], adc_char );
  update_string(display_line[DISPLAYLINE1], DISPLAYLINE1);
  enable_display_update();
  display_changed= ALWAYS;
}

void adc_line3(int ok) {
  strcpy(display_line[DISPLAYLINE2], adc_char);
  update_string(display_line[DISPLAYLINE2], DISPLAYLINE2);
  enable_display_update();
  display_changed= ALWAYS;
}

void adc_line2(int ok) {
  display_line[TWO][NOTHING] = adc_char[NOTHING];
    display_line[TWO][ONE] = adc_char[ONE];
    display_line[TWO][TWO] = adc_char[TWO];
    display_line[TWO][THREE] = '.';
    display_line[TWO][FOUR] = adc_char[THREE];
    display_line[TWO][FIVE] = 's';

  update_string(display_line[DISPLAYLINE3], DISPLAYLINE3);
  enable_display_update();
  display_changed= ALWAYS;
}

void Check_Line(void) {
  if (ADC_Left_Detect >= BLACKDETECT && ADC_Right_Detect >= BLACKDETECT){
    directline = STRAIGHT;
  }
  else if (ADC_Left_Detect < BLACKDETECT && ADC_Right_Detect > BLACKDETECT) {
    directline = RIGHT;
  }
  else if (ADC_Left_Detect > BLACKDETECT && ADC_Right_Detect < BLACKDETECT) {
    directline = LEFT;
  }
}