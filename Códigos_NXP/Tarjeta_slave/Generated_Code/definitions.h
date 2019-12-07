/*
 * definitions.h
 *
 *  Created on: 26/10/2018
 *      Author: Jorge Roberto
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

/* Boolean */
#define FALSE                       0
#define TRUE                        1

/* Ports */
#define PRT_A                      'A'
#define PRT_B                      'B'
#define PRT_C                      'C'
#define PRT_D                      'D'
#define PRT_E                      'E'

/* Pin number */
#define PIN_0                       0
#define PIN_1                       1
#define PIN_2                       2
#define PIN_3                       3
#define PIN_4                       4
#define PIN_5                       5
#define PIN_6                       6
#define PIN_7                       7
#define PIN_8                       8
#define PIN_9                       9
#define PIN_10                     10
#define PIN_11                     11
#define PIN_12                     12
#define PIN_13                     13
#define PIN_14                     14
#define PIN_15                     15
#define PIN_16                     16
#define PIN_17                     17

/* State Names */
#define INITIALIZE                  0
#define DO_NOTHING                  1
#define WINDOW_MOVE_UP              2
#define WINDOW_MOVE_DOWN            3
#define WINDOW_ANTI_PINCH           4
#define WAIT_TIMER                  5

#define TIME_MIN_RESOLUTION        10
#define TIME_LED_TRANSITION       400
#define TIME_ANTI_PINCH_DELAY    5000

#define MIN_CYCLES_TO_CONSIDER_VALID_PRESS  1
#define CYCLES_TO_CONSIDER_MANUAL_OR_AUTO  50

#define CYCLES_FOR_ONE_LED_TRANSITION                                    40
#define CYCLES_FOR_TWO_LED_TRANSITION       CYCLES_FOR_ONE_LED_TRANSITION*2

#define MAX_POSITION               10 /* Upper Limit for Window */
#define MIN_POSITION                0 /* Lower Limit for Window */

#define SPLL2_DIV2_CLK              6
#define CLOCK_BASE              40000

#endif /* DEFINITIONS_H_ */
