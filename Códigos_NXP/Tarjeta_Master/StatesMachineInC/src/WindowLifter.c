/*
 * WindowLifter.c
 *
 *  Created on: Nov 4, 2019
 *      Author: cvite
 */

#include "WindowLifter.h"
#include "WindowLifter_State.h"
#include "SPI1.h"

e_WL_States State = e_Configuring;

unsigned short int LPSPI1_16bits_read;

void WindowLifter(void)
{
	switch (State)
	{
	case e_Configuring:
		Configuring();
		break;

	case e_ReadButtons:
		//ReadButtons();
	    LPSPI1_v_Send_8_bits_Data (0x01);
	    LPSPI1_16bits_read = LPSPI1_v_Receive_16bits_Data ();

		break;

	case e_ButtonValid:
		ButtonValid();
		break;

	case e_SendBajar:
		SendBajar();
		break;

	case e_SendSubir:
		SendSubir();
		break;

	case e_MessageValid:
		MessageValid();
		break;

	case e_Error:
		Error();
		break;

	case e_Wait:
		Wait();
		break;

	default:
		break;
	};
}

