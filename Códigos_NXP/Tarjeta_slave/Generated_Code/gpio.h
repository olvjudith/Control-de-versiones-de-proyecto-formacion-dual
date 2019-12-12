/*
 * gpio.h
 *
 *  Created on: 05/11/2018
 *      Author: azpei
 */
/*============================================================================*/
/* Project    =  Window Lifter						                          */
/* Module     =   gpio.h                                                       */
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
#ifndef GPIO_H_
#define GPIO_H_
/*******************************************************************************
 **                      Include Section                                       **
 *******************************************************************************/
#include <stdint.h>
/*******************************************************************************
 **                      Global Data Types                                     **
 *******************************************************************************/
typedef char char_t;

/*******************************************************************************
 **                      Function Prototypes                                   **
 *******************************************************************************/
void GPIO_Clock_Set_Up(uint8_t portIndex);
void GPIO_Init_As_Input(char_t port, uint8_t pinNumber);
void GPIO_Init_As_Output(char_t port, uint8_t pinNumber);
void GPIO_Set_Off_Output(char_t port, uint8_t pinNumber);
void GPIO_Set_On_Output(char_t port, uint8_t pinNumber);

#endif /* GPIO_H_ */
