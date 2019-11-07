/*
 * WindowLifter_State.c
 *
 *  Created on: Nov 4, 2019
 *      Author: cvite
 */
#include "WindowLifter_State.h"
#include "ab_DataTypes.h"
#include "S_Configurations.h"
#include "WindowLifter.h"

extern e_WL_States State;

void Configuring(void)
{
	e_Status configStatus = OK;

	configStatus &= config_CLOCKS();
	configStatus &= config_SPI();
	configStatus &= config_TIMER();
	configStatus &= config_PORTS();

	if(configStatus == OK)
	{
		State = e_ReadButtons;
	}else if (configStatus == NOK){
		State = e_Error;
	}else
	{
		//Do nothing
	}
}

void ReadButtons(void)
{

}

void ButtonValid(void)
{

}

void SendBajar(void)
{

}

void SendSubir(void)
{

}

void MessageValid(void)
{

}

void Error(void)
{

}

void Wait(void)
{

}
