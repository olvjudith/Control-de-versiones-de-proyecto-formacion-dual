/*
 * GPIO.c
 *
 *  Created on: 05/11/2019
 *      Author: alabe
 */
#include "S32K144.h"
#include "GPIO.h"
#include "SPI1.h"

#define MAIN_ub_PORT_PCR_ALTERNATIVE_3 ( (unsigned long) 3)

#define MAIN_ul_PIN_14 ( (unsigned long) 14 )
#define MAIN_ul_PIN_15 ( (unsigned long) 15 )
#define MAIN_ul_PIN_16 ( (unsigned long) 16 )
#define MAIN_ul_PIN_17 ( (unsigned long) 17 )

unsigned char valorRandom = 100;

unsigned char GPIO_uc_GetRandomValue(void)
{
	return valorRandom;
}

void PORT_v_InitializeSPI_Pins (void)
{
  /* Description of PCC_PORTB register can be found in section 29.6.23 */
  PCC->PCCn [ PCC_PORTB_INDEX ] |=  PCC_PCCn_CGC_MASK; /* Enable clock for PORTB */

  /* Description of PORT_PCR register can be found in section 12.6.1 Pin Control Register n (PORT_PCRn)  */
  PORTB->PCR[ MAIN_ul_PIN_14 ] |=  PORT_PCR_MUX( MAIN_ub_PORT_PCR_ALTERNATIVE_3 ); /* Port B14: MUX = ALT3, LPSPI1_SCK */
  PORTB->PCR[ MAIN_ul_PIN_15 ] |=  PORT_PCR_MUX( MAIN_ub_PORT_PCR_ALTERNATIVE_3 ); /* Port B15: MUX = ALT3, LPSPI1_SIN */
  PORTB->PCR[ MAIN_ul_PIN_16 ] |=  PORT_PCR_MUX( MAIN_ub_PORT_PCR_ALTERNATIVE_3 ); /* Port B16: MUX = ALT3, LPSPI1_SOUT */
  PORTB->PCR[ MAIN_ul_PIN_17 ] |=  PORT_PCR_MUX( MAIN_ub_PORT_PCR_ALTERNATIVE_3 ); /* Port B17: MUX = ALT3, LPSPI1_PCS3 */
}
