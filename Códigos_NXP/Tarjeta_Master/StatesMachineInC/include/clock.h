/*
 * clock.h
 *
 *  Created on: 05/11/2019
 *      Author: alabe
 */

#ifndef CLOCK_H_
#define CLOCK_H_

extern void WD_v_Disable (void);
extern void SOSC_init_8MHz (void);
extern void SPLL_init_160MHz (void);
extern void NormalRUNmode_80MHz (void);

#endif /* CLOCK_H_ */
