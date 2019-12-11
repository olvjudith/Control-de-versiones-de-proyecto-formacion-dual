/*============================================================================*/
/* Project    =   Window Lifter 						                      */
/* Module     =   timer.c                                                      */
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

#include <timer.h>
#include "S32K144.h"

#ifndef GPIO_H_
#include <gpio.h>
#endif

#ifndef STDINT_H_
#include <stdint.h>
#endif

/*******************************************************************************
 **                      Function Definitions                                  **
 *******************************************************************************/
/**************************************************************
 *  Name                 : TIMER_Delay_Milliseconds
 *  Description          : Configuration of registers for a timer duration and set them in a function
 *  Input Parameters     : msTimerDuration
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [yes / No]
 **************************************************************/

void TIMER_Delay_Milliseconds(uint32_t msTimerDuration) {
	PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(SPLL2_DIV2_CLK); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
	PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
	LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
	LPIT0->MIER = 0x00000001; /*Timer Interrupt Enabled for Chan 0 */
	LPIT0->TMR[0].TVAL = msTimerDuration * CLOCK_BASE; /* Timer period */
	LPIT0->TMR[0].TCTRL = 0x00000001; /* Timer enable */
	while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK))
		;
	LPIT0->MSR |= LPIT_MSR_TIF0_MASK;
	LPIT0->TMR[0].TCTRL = 0x00000000; /* Timer disable */
}

