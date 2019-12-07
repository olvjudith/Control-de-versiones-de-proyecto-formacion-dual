/*
 * clock.h
 *
 *  Created on: 22/10/2018
 *      Author: azpei
 */

#ifndef CLOCK_H_
#define CLOCK_H_

void CLOCK_SOSC_Init_8MHz(void);

void CLOCK_SPLL_Init_160MHz(void);

void CLOCK_Setup_80MHz(void);

void CLOCK_Disable_Watchdog(void);

#endif /* CLOCK_H_ */
