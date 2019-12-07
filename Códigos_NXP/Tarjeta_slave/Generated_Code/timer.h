/*
 * timer.h
 *
 *  Created on: 26/10/2018
 *      Author: azpei
 */

#ifndef TIMER_H_
#define TIMER_H_

#ifndef DEFINITIONS_H_
#include "definitions.h"
#endif

#ifndef STDINT_H
#include <stdint.h>
#endif

void TIMER_Delay_Milliseconds (uint32_t msTimerDuration);

uint8_t TIMER_Button_Pressed_With_Duration_Criteria (uint8_t port, uint8_t pinNumber, uint32_t msTimerDuration);

#endif /* TIMER_H_ */
