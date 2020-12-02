// ------------------------------------------------------------------------------
//
//  Description: This file contains the ALL THE MACROS
//
//  Mohammad Ahmad
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V7.12.4
// ------------------------------------------------------------------------------

#define ADCINT1                 0x00
#define ADCINT2                 0x01
#define ADCINT3                 0x02

#define BCDONE                  1
#define BCDTWO                  2
#define BCDTHREE                3
#define NINEEE                  999
#define NINEE                   99
#define NINE                    9
#define TENNN                   1000
#define TENN                    100
#define TEN                     10
#define CONVIRTY                0x30
//#define LEFTWHITE               500
//#define BLACKDETECT             450
#define STEP0                   1
#define STEP1                   2
#define STEP2                   3
#define STEP3                   4
#define STEP4                   5
#define TB0CCR0_INTERVAL        (25000)
#define TB0CCR1_INTERVAL        25000
#define USE_GPIO                (0x00)
#define USE_SMCLK               (0x01)
#define SCREENOFF               10
#define SCREENON                20
#define DEBOUNCETIP             20
#define TWOHUNDREDMS            4
#define SECOND                  20
#define RIGHT_FORWARD_SPEED     (TB3CCR1)
#define LEFT_FORWARD_SPEED      (TB3CCR2)
#define RIGHT_REVERSE_SPEED     (TB3CCR3)
#define LEFT_REVERSE_SPEED      (TB3CCR4)
#define WHEEL_OFF               0
#define WHEEL_PERIOD            40000
#define FWDTIME                 1
#define PAUSETIME1              20
#define PAUSETIME2              40
#define PAUSETIME3              60
#define RVSTIME                 40
#define FWDTIME2                100
#define CLOCKERTIME             140
#define ANTICLOCK               240
#define ENDRESTART              340
#define FWDRTSPD                24000
#define FWDLFTSPD               34000
#define RVRTSPD                 30000
#define RVLFTSPD                30000
#define TURNSPEED               20000
#define ANTITURNSPEED           10000
#define GOBOY                   15000



#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x40) // GREEN LED 1
#define COUNTR                   0
#define INCR                     1
#define START                    300
#define STOP                     1900
#define NOTHING                 (0)
#define TRIANGLE                (1)
#define FIG8                    (2)
#define CIRCLE                  (3)
#define FIX                     (1)
#define TURN1                   (5)
#define TURN2                   (8)
#define TURN3                   (1)
#define TURN4                   (2)
#define ROTATE                  (560)
#define REPS                    (6)
#define LINE                    (700)
#define START2                    800
#define LINE2                    (1025)
#define FIXER                   140
#define LFIXER                  300
#define CENTURN                 13
#define CENTOOOOR               45

#define REDBLNK1                250 // RED LED FIRST BLINK
#define GRNBLNK1                200 // GREEN LED FIRST BLINK
#define REDBLNK2                150 // RED LED SECOND BLINK
#define GRNBLNK2                100 // GREEN LED SECOND BLINK
#define BOTHBLNK                50 // BOTH LED BLINK
#define DISPLAYCHANGE1          1
#define ONETIME0                0
#define SEQUENCE0               0
#define DISPLAYSIZE             4
#define DISPLAYSIZEPNTR         4
#define DISPLAYLENGTH           11    
#define DISPLAYCHAR10           10
#define DISPLAYLINE1            0
#define DISPLAYLINE2            1
#define DISPLAYLINE3            2
#define DISPLAYLINE4            3
#define ZEROFORDISPLAY          0
#define NODISPUPDATE            0
#define DISPUPDATECOUNT         0
#define LOOPSTART               0
#define OUTPUTDIR               0xFF
#define LOWINITVAL              0x00
#define INPUTDIR                0x00
#define ONE                     1
#define TWO                     2
#define THREE                   3
#define FOUR                    4
#define FOURTEEN                14
#define FIVE                    5        
#define STRAIGHT                0
#define RIGHT                   1
#define LEFT                    2
#define TWOCIRC                 300



// Port 1 Pins
#define RED_LED (0x01) // 0 RED LED 0
#define A1_SEEED (0x02) // 1 A1_SEEED
#define V_DETECT_L (0x04) // 2 V_DETECT_L
#define V_DETECT_R (0x08) // 3 V_DETECT_R
#define A4_SEEED (0x10) // 4 A4_SEEED
#define V_THUMB (0x20) // 5 V_THUMB
#define UCA0RXD (0x40) // 6 Back Channel UCA0RXD
#define UCA0TXD (0x80) // 7 Back Channel UCA0TXD

// Port 2 Pins
#define P2_0 (0x01) // 0
#define P2_1 (0x02) // 1
#define P2_2 (0x04) // 2
#define SW2 (0x08) // 3 SW2
#define P2_4 (0x10) // 4
#define P2_5 (0x20) // 5
#define LFXOUT (0x40) // XOUTR
#define LFXIN (0x80) // XINR

// Port 3 Pins
#define TEST_PROBE (0x01) // 0 TEST PROBE
#define CHECK_BAT (0x02) // 1 CHECK_BAT
#define OA2N (0x04) // 2 Photodiode Circuit
#define OA2P (0x08) // 3 Photodiode Circuit
#define SMCLK_OUT (0x10) // 4 SMCLK
#define IR_LED (0x20) // 5 IR_LED
#define IOT_LINK (0x40) // 6 IOT_LINK
#define P3_7 (0x80) // 7 P3_7

// Port 4 Pins
#define RESET_LCD (0x01) // 0 LCD Reset
#define SW1 (0x02) // 1 SW1
#define UCA1RXD (0x04) // 2 Back Channel UCA1RXD
#define UCA1TXD (0x08) // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD (0x10) // 4 Chip Select
#define UCB1CLK (0x20) // 5 SPI mode - clock output—UCB1CLK
#define UCB1SIMO (0x40) // 6 UCB1SIMO
#define UCB1SOMI (0x80) // 7 UCB1SOMI

// Port 5 Pins
#define IOT_RESET (0x01) // 0 IOT RESET
#define V_BAT (0x02) // 1 V_BAT
#define IOT_PROG_SEL (0x04) // 2 IOT_PROG_SEL
#define V_3_3 (0x08) // 3 V_3_3
#define IOT_PROG_MODE (0x10) // 4 IOT_PROG_MODE

// Port 6 Pins
#define R_FORWARD (0x01) // 0 R_FORWARD
#define L_FORWARD (0x02) // 1 L_FORWARD
#define R_REVERSE (0x04) // 2 R_REVERSE
#define L_REVERSE (0x08) // 3 L_REVERSE
#define LCD_BACKLITE (0x10) // 4 LCD_BACKLITE
#define P6_5 (0x20) // 5 P6_5
#define GRN_LED (0x40) // 6 GRN_LED