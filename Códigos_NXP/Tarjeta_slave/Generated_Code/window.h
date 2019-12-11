/*
 * window.h
 *
 *  Created on: 25/10/2018
 *      Author: Jorge Roberto
 */
/*============================================================================*/
/* Project    =  Window Lifter						                          */
/* Module     =   window.h                                                       */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/* Layer:            Application, Service, Abstraction, Drivers               */
/* %version:         1 %                                                      */
/* %created_by:      uid02495 %                                               */
/* %date_created:    Tue Dec 10 13:41:01 2019 %                               */
/*============================================================================*/
/* DESCRIPTION : This file contains macros, ADC type definitions,             */
/* enumerations,  data types and API function prototypes of ADC Driver        */
/*============================================================================*/
/*                             OBJECT HISTORY                                 */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/* Integration under Continuous CM                                            */
/*============================================================================*/

#ifndef WINDOW_H_
#define WINDOW_H_

/*******************************************************************************
 **                      Include Section                                       **
 *******************************************************************************/
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

/*******************************************************************************
 **                      Function Prototypes                                   **
 *******************************************************************************/
void WINDOW_State_Initialize(void);

#endif /* WINDOW_H_ */
