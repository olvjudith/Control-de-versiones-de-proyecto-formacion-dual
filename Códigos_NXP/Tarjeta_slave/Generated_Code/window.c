/*
 * window.c

 */
/*============================================================================*/
/* Project    =   Window Lifter 						                      */
/* Module     =   window.c                                                      */
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
#include "window.h"

/*******************************************************************************
 **                      Function Definitions                                  **
 *******************************************************************************/
/**************************************************************
 *  Name                 : WINDOW_State_Initialize
 *  Description          : Initialize register of clock and state of pins
 *  Input Parameters     : None
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/
void WINDOW_State_Initialize() {
	CLOCK_SOSC_Init_8MHz();
	CLOCK_SPLL_Init_160MHz();
	CLOCK_Setup_80MHz();
	CLOCK_Disable_Watchdog();
	PORT_v_InitializeSPI_Pins();
	LPSPI1_v_Initialization();

	GPIO_Clock_Set_Up(PRT_A);
	GPIO_Clock_Set_Up(PRT_C);
	GPIO_Clock_Set_Up(PRT_D);
	GPIO_Clock_Set_Up(PRT_E);

	GPIO_Init_As_Input(PRT_C, PIN_12);
	GPIO_Init_As_Input(PRT_C, PIN_13);
	GPIO_Init_As_Input(PRT_C, PIN_17);

	GPIO_Init_As_Output(PRT_A, PIN_11);
	GPIO_Init_As_Output(PRT_A, PIN_17);
	GPIO_Init_As_Output(PRT_D, PIN_0); //Se cambia por led rojo
	GPIO_Init_As_Output(PRT_D, PIN_3);
	GPIO_Init_As_Output(PRT_D, PIN_5);
	GPIO_Init_As_Output(PRT_D, PIN_10);
	GPIO_Init_As_Output(PRT_D, PIN_11);
	GPIO_Init_As_Output(PRT_D, PIN_12);
	GPIO_Init_As_Output(PRT_D, PIN_15);

	GPIO_Init_As_Output(PRT_D, PIN_16);
	GPIO_Init_As_Output(PRT_E, PIN_3);
	GPIO_Init_As_Output(PRT_E, PIN_4);
	GPIO_Init_As_Output(PRT_E, PIN_5);

	GPIO_Set_Off_Output(PRT_A, PIN_11);
	GPIO_Set_Off_Output(PRT_A, PIN_17);
	GPIO_Set_On_Output(PRT_D, PIN_0);
	GPIO_Set_On_Output(PRT_D, PIN_16);
	GPIO_Set_Off_Output(PRT_D, PIN_15);

	GPIO_Set_Off_Output(PRT_D, PIN_3);
	GPIO_Set_Off_Output(PRT_D, PIN_5);
	GPIO_Set_Off_Output(PRT_D, PIN_10);
	GPIO_Set_Off_Output(PRT_D, PIN_11);
	GPIO_Set_Off_Output(PRT_D, PIN_12);
	GPIO_Set_Off_Output(PRT_E, PIN_3);
	GPIO_Set_Off_Output(PRT_E, PIN_4);
	GPIO_Set_Off_Output(PRT_E, PIN_5);
}

