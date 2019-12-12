/*
 * gpio.c
 *
 *  Created on: 05/11/2018
 *      Author: azpei
 */
/*============================================================================*/
/* Project    =   Window Lifter 						                      */
/* Module     =   gpio.c                                                      */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/* Layer:            Application, Service, Abstraction, Drivers               */
/* %version:         1 %                                                      */
/* %created_by:      uid02495 %                                               */
/* %date_created:    Tue Dec 10 13:41:01 2019 %                               */
/*============================================================================*/
/* DESCRIPTION : This file contains macros, WindowLifter type definitions,    */
/* enumerations, data types and API function prototypes of WindowLifter Driver*/
/*============================================================================*/
/*                             OBJECT HISTORY                                 */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/* Integration under Continuous CM                                            */
/*============================================================================*/

/******************************************************************************/
/*                      Include Section                                       */
/*============================================================================*/
#include "S32K144.h"
#include <gpio.h>

/*******************************************************************************
 **                      Function Definitions                                  **
 *******************************************************************************/
/**************************************************************
 *  Name                 : GPIO_Clock_Set_Up
 *  Description          : Configuring register for the CMP0 module
 *  Input Parameters     : port
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/

void GPIO_Clock_Set_Up(uint8_t port) {
	switch (port) {
	case 'A':
		PCC->PCCn[PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK;
		break;
	case 'B':
		PCC->PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK;
		break;
	case 'C':
		PCC->PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;
		break;
	case 'D':
		PCC->PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
		break;
	case 'E':
		PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
		break;
	default:
		break;
	}

}

/**************************************************************
 *  Name                 : GPIO_Init_As_Input
 *  Description          : Configuring port as input
 *  Input Parameters     : port, pinNumber
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/

void GPIO_Init_As_Input(char_t port, uint8_t pinNumber) {
	uint32_t pinAsGpioInterrputEnable = 0x00098110;
	switch (port) {
	case 'A':
		PTA->PDDR &= ~(1 << pinNumber);
		PORTA->PCR[pinNumber] = pinAsGpioInterrputEnable;
		break;
	case 'B':
		PTB->PDDR &= ~(1 << pinNumber);
		PORTB->PCR[pinNumber] = pinAsGpioInterrputEnable;
		break;
	case 'C':
		PTC->PDDR &= ~(1 << pinNumber);
		PORTC->PCR[pinNumber] = pinAsGpioInterrputEnable;
		break;
	case 'D':
		PTD->PDDR &= ~(1 << pinNumber);
		PORTD->PCR[pinNumber] = pinAsGpioInterrputEnable;
		break;
	case 'E':
		PTE->PDDR &= ~(1 << pinNumber);
		PORTE->PCR[pinNumber] = pinAsGpioInterrputEnable;
		break;
	default:
		break;
	}
}

/**************************************************************
 *  Name                 : GPIO_Init_As_Output
 *  Description          : Configuring port as output
 *  Input Parameters     : port, pinNumber
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/

void GPIO_Init_As_Output(char_t port, uint8_t pinNumber) {
	uint32_t pinAsGpio = 0x00000100;
	switch (port) {
	case 'A':
		PTA->PDDR |= 1 << pinNumber;
		PORTA->PCR[pinNumber] = pinAsGpio;
		break;
	case 'B':
		PTB->PDDR |= 1 << pinNumber;
		PORTB->PCR[pinNumber] = pinAsGpio;
		break;
	case 'C':
		PTC->PDDR |= 1 << pinNumber;
		PORTC->PCR[pinNumber] = pinAsGpio;
		break;
	case 'D':
		PTD->PDDR |= 1 << pinNumber;
		PORTD->PCR[pinNumber] = pinAsGpio;
		break;
	case 'E':
		PTE->PDDR |= 1 << pinNumber;
		PORTE->PCR[pinNumber] = pinAsGpio;
		break;
	default:
		break;
	}
}

/**************************************************************
 *  Name                 : GPIO_Set_Off_Output
 *  Description          : Set off a pin select
 *  Input Parameters     : port, pinNumber
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/
void GPIO_Set_Off_Output(char_t port, uint8_t pinNumber) {
	switch (port) {
	case 'A':
		PTA->PCOR |= 1 << pinNumber;
		break;
	case 'B':
		PTB->PCOR |= 1 << pinNumber;
		break;
	case 'C':
		PTC->PCOR |= 1 << pinNumber;
		break;
	case 'D':
		PTD->PCOR |= 1 << pinNumber;
		break;
	case 'E':
		PTE->PCOR |= 1 << pinNumber;
		break;
	default:
		break;
	}
}

/**************************************************************
 *  Name                 : GPIO_Set_On_Output
 *  Description          : Set on a pin select
 *  Input Parameters     : port, pinNumber
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/
void GPIO_Set_On_Output(char_t port, uint8_t pinNumber) {
	switch (port) {
	case 'A':
		PTA->PSOR |= 1 << pinNumber;
		break;
	case 'B':
		PTB->PSOR |= 1 << pinNumber;
		break;
	case 'C':
		PTC->PSOR |= 1 << pinNumber;
		break;
	case 'D':
		PTD->PSOR |= 1 << pinNumber;
		break;
	case 'E':
		PTE->PSOR |= 1 << pinNumber;
		break;
	default:
		break;
	}
}
