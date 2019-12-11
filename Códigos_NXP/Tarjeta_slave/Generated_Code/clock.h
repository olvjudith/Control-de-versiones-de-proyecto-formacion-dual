/*
 * clock.h
 *
 *  Created on: 22/10/2018
 *      Author: azpei
 */
/*============================================================================*/
/* Project    =  Window Lifter						                          */
/* Module     =  clock.h                                                       */
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
#ifndef CLOCK_H_
#define CLOCK_H_

/*******************************************************************************
 **                      Function Prototypes                                   **
 *******************************************************************************/
void CLOCK_SOSC_Init_8MHz(void);

void CLOCK_SPLL_Init_160MHz(void);

void CLOCK_Setup_80MHz(void);

void CLOCK_Disable_Watchdog(void);

#endif /* CLOCK_H_ */
