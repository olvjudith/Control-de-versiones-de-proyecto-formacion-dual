/*
 * window.h
 *
 *  Created on: 25/10/2018
 *      Author: Jorge Roberto
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Cpu.h"

#ifndef STDINT_H_
#include <stdint.h>
#endif

#ifndef DEFINITIONS_H_
#include "definitions.h"
#endif

#ifndef CLOCK_H_
#include "clock.h"
#endif

#ifndef GPIO_H_
#include "gpio.h"
#endif

#ifndef TIMER_H_
#include "timer.h"
#endif

#ifndef LPSPI1_H_
#include "LPSPI1.h"
#endif



void WINDOW_State_Initialize(void);

#endif /* WINDOW_H_ */
