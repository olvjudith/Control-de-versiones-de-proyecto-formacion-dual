/*
 * LPSPI1.h
 *
 *  Created on: 07/11/2019
 *      Author: alabe
 */
/*============================================================================*/
/* Project    =  Window Lifter						                          */
/* Module     =   LPSPI1.h                                                       */
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
#ifndef LPSPI1_H_
#define LPSPI1_H_

/*******************************************************************************
 **                      Function Prototypes                                   **
 *******************************************************************************/
extern void PORT_v_InitializeSPI_Pins(void);
extern void LPSPI1_v_Initialization(void);
extern void LPSPI1_v_Send_8_bits_Data(char ui_Data);
extern uint16_t LPSPI1_v_Receive_16bits_Data(void);

#endif /* LPSPI1_H_ */
