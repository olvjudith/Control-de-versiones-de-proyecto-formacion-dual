/*
 * S_Configurations.c
 *
 *  Created on: Nov 4, 2019
 *      Author: cvite
 */

#include "S_Configurations.h"
extern void LPSPI1_v_Initialization (void);
extern void SOSC_init_8MHz (void);
extern void SPLL_init_160MHz (void);
extern void NormalRUNmode_80MHz (void);
extern void WD_v_Disable (void);
extern void PORT_v_InitializeSPI_Pins(void);

e_Status config_CLOCKS(void)
{
	WD_v_Disable ();
	SOSC_init_8MHz ();
	SPLL_init_160MHz ();
	NormalRUNmode_80MHz ();
	return OK;
}

e_Status config_SPI(void)
{
	LPSPI1_v_Initialization();
	return OK;
}

e_Status config_TIMER(void)
{
	return OK;
}

e_Status config_PORTS(void)
{
	PORT_v_InitializeSPI_Pins();
	return OK;
}
