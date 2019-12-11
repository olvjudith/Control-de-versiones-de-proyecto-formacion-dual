/*
 * timer.h
 *
 *  Created on: 26/10/2018
 *      Author: azpei
 */
/*============================================================================*/
/* Project    =  Window Lifter						                          */
/* Module     =   timer.h                                                       */
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
#ifndef TIMER_H_
#define TIMER_H_
#ifndef DEFINITIONS_H_

/*******************************************************************************
 **                      Include Section                                       **
 *******************************************************************************/

#include "definitions.h"
#endif

#ifndef STDINT_H
#include <stdint.h>
#endif

/*******************************************************************************
 **                      Function Prototypes                                   **
 *******************************************************************************/
void TIMER_Delay_Milliseconds(uint32_t msTimerDuration);

#endif /* TIMER_H_ */
