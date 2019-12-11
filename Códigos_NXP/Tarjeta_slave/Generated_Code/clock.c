/*
 * clock.c
 *
 *  Created on: 22/10/2018
 *      Author: azpei
 */
/*============================================================================*/
/* Project    =   Window Lifter 						                      */
/* Module     =   clock.c                                                      */
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
#include <clock.h>
#include "S32K144.h"
/*******************************************************************************
 **                      Function Definitions                                  **
 *******************************************************************************/
/**************************************************************
 *  Name                 : CLOCK_SOSC_Init_8MHz
 *  Description          : Configuration of registers for System Oscillator
 *  Input Parameters     : None (name of return variable)
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [yes / No]
 **************************************************************/

void CLOCK_SOSC_Init_8MHz(void) {
	SCG->SOSCDIV = 0x00000101; /* SOSCDIV1 & SOSCDIV2 =1: divide by 1 */
	SCG->SOSCCFG = 0x00000024; /* Range=2: Medium freq (SOSC between 1MHz-8MHz)*/
	while (SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK)
		; /* Ensure SOSCCSR unlocked */
	SCG->SOSCCSR = 0x00000001;
	while (!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK))
		; /* Wait for sys OSC clk valid */
}

/**************************************************************
 *  Name                 : CLOCK_SPLL_Init_160MHz
 *  Description          : Configuration of registers for SPI communication pines
 *  Input Parameters     : None (name of return variable)
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [yes / No]
 **************************************************************/
void CLOCK_SPLL_Init_160MHz(void) {
	while (SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK)
		; /* Ensure SPLLCSR unlocked */
	SCG->SPLLCSR = 0x00000000; /* SPLLEN=0: SPLL is disabled (default) */
	SCG->SPLLDIV = 0x00000302; /* SPLLDIV1 divide by 2; SPLLDIV2 divide by 4 */
	SCG->SPLLCFG = 0x00180000; /* PREDIV=0: Divide SOSC_CLK by 0+1=1 */
	while (SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK)
		; /* Ensure SPLLCSR unlocked */
	SCG->SPLLCSR = 0x00000001; /* LK=0: SPLLCSR can be written */
	while (!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK))
		; /* Wait for SPLL valid */
}

/**************************************************************
 *  Name                 : CLOCK_Setup_80MHz
 *  Description          : Change to normal RUN mode with 8MHz SOSC, 80 MHz PLL
 *  Input Parameters     : None (name of return variable)
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [yes / No]
 **************************************************************/
void CLOCK_Setup_80MHz(void) /* */
{
	SCG->RCCR = SCG_RCCR_SCS(6) /* PLL as clock source*/
	| SCG_RCCR_DIVCORE(0b01) /* DIVCORE=1, div. by 2: Core clock = 160/2 MHz = 80 MHz*/
	| SCG_RCCR_DIVBUS(0b01) /* DIVBUS=1, div. by 2: bus clock = 40 MHz*/
	| SCG_RCCR_DIVSLOW(0b10); /* DIVSLOW=2, div. by 3: SCG slow, flash clock= 26 2/3 MHz*/
	while (((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) != 6) {
	}
}

/**************************************************************
 *  Name                 : CLOCK_Disable_Watchdog
 *  Description          : Disable watchdog
 *  Input Parameters     : None (name of return variable)
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [yes / No]
 **************************************************************/
void CLOCK_Disable_Watchdog(void) {
	WDOG->CNT = 0xD928C520; /*Unlock watchdog*/
	WDOG->TOVAL = 0x0000FFFF; /*Maximum timeout value*/
	WDOG->CS = 0x00002100; /*Disable watchdog*/
}
