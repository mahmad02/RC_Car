#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern char display_line[DISPLAYSIZE][DISPLAYLENGTH];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;





void Fwd_Fun(void){
  RIGHT_FORWARD_SPEED = FWDRTSPD;
  LEFT_FORWARD_SPEED = FWDLFTSPD;
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
  LEFT_REVERSE_SPEED = WHEEL_OFF;
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;

}

void Stopthe_Fun(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
  LEFT_REVERSE_SPEED = WHEEL_OFF;
  
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;
}

void Rivers_Fun(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = RVRTSPD;
  LEFT_REVERSE_SPEED = RVLFTSPD;
  
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;
}

void Clock_Fun(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = TURNSPEED;
  RIGHT_REVERSE_SPEED = ANTITURNSPEED;
  LEFT_REVERSE_SPEED = WHEEL_OFF;
  
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;
}

void AntiClock_Fun(void){
  RIGHT_FORWARD_SPEED = TURNSPEED;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
  LEFT_REVERSE_SPEED = ANTITURNSPEED;
  
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;
}

void Left_Fun(void){
  RIGHT_FORWARD_SPEED = GOBOY;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
  LEFT_REVERSE_SPEED = WHEEL_OFF;
  
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;
}

void Right_Fun(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = GOBOY;
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
  LEFT_REVERSE_SPEED = WHEEL_OFF;
  
          update_string(display_line[DISPLAYLINE4], DISPLAYLINE4);
          enable_display_update();
          display_changed= ALWAYS;
}
