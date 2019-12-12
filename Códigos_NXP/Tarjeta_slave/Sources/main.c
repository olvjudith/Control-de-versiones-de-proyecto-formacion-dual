/*============================================================================*/
/* Project    =   Window Lifter 						                      */
/* Module     =   main.c                                                      */
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

#include <window.h>
#include <LPSPI1.h>

/*******************************************************************************
 **                      Global Data Types                                     **
 *******************************************************************************/

uint8_t windowPosition = 00;
uint8_t windowMovement = INITIALIZE;
uint8_t antiPinchFlag = FALSE;
uint16_t LPSPI1_16bits_read = 00;

/*******************************************************************************
 **                      Function Definitions                                  **
 *******************************************************************************/
/**************************************************************
 *  Name                 : main function
 *  Description          : state machine
 *  Input Parameters     : None (name of imput parameters)
 *  Return Parameter     : None (name of return variable)
 *  Preconditions        : [No]
 **************************************************************/

int main(void) {
	WINDOW_State_Initialize();

	while (1) {
		LPSPI1_16bits_read = LPSPI1_v_Receive_16bits_Data();

		switch (LPSPI1_16bits_read) {

		case (0xef): {

			LPSPI1_v_Send_8_bits_Data(79);

			GPIO_Set_On_Output(PRT_E, PIN_5);
			GPIO_Set_Off_Output(PRT_A, PIN_11);
			GPIO_Set_Off_Output(PRT_E, PIN_4);
			GPIO_Set_Off_Output(PRT_A, PIN_17);

			GPIO_Set_On_Output(PRT_D, PIN_16);
			GPIO_Set_On_Output(PRT_D, PIN_15);

		}
			break;
		case (0xf0): {

			LPSPI1_v_Send_8_bits_Data(79);

			GPIO_Set_On_Output(PRT_E, PIN_4);
			GPIO_Set_On_Output(PRT_E, PIN_5);
			GPIO_Set_Off_Output(PRT_A, PIN_11);
			GPIO_Set_Off_Output(PRT_A, PIN_17);

			GPIO_Set_On_Output(PRT_D, PIN_16);
			GPIO_Set_On_Output(PRT_D, PIN_15);

		}
			break;

		case (0xf1): {

			LPSPI1_v_Send_8_bits_Data(79);

			GPIO_Set_On_Output(PRT_E, PIN_4);
			GPIO_Set_On_Output(PRT_E, PIN_5);
			GPIO_Set_On_Output(PRT_A, PIN_11);
			GPIO_Set_Off_Output(PRT_A, PIN_17);

			GPIO_Set_On_Output(PRT_D, PIN_16);
			GPIO_Set_On_Output(PRT_D, PIN_15);

		}
			break;
		case (0xf2): {

			LPSPI1_v_Send_8_bits_Data(79);

			GPIO_Set_On_Output(PRT_E, PIN_4);
			GPIO_Set_On_Output(PRT_E, PIN_5);
			GPIO_Set_On_Output(PRT_A, PIN_11);
			GPIO_Set_On_Output(PRT_A, PIN_17);

			GPIO_Set_Off_Output(PRT_D, PIN_16);
			GPIO_Set_On_Output(PRT_D, PIN_15);

		}
			break;

		default: {

			LPSPI1_v_Send_8_bits_Data(79);

			GPIO_Set_Off_Output(PRT_E, PIN_5);
			GPIO_Set_Off_Output(PRT_A, PIN_11);
			GPIO_Set_Off_Output(PRT_E, PIN_4);
			GPIO_Set_Off_Output(PRT_A, PIN_17);

			GPIO_Set_Off_Output(PRT_D, PIN_15);
			GPIO_Set_On_Output(PRT_D, PIN_16);

		}

		}
	}
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	//for(;;) {
	//if(exit_code != 0) {
	// break;
	//}
	//}
	return 0;
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
