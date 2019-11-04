/*
 * main.c                       (c) NXP 2016
 * Description: Simple LPSPI transfer.  A frame is transmitted and results read.
 * May 31 2016 S. Mihalik - Initial version.
 * Sep 23 2016 S. Mihalik - Added SBC commands for SPI transfer
 * Oct 31 2016 SM - Clocks adjusted for SPLL at 160 MHz,
 *                  tx, rx variables made global
 * Jul 03 2017 SM - removed code for MC33903 on obsolete EVB
 */

#include "S32K144.h"           /* include peripheral declarations S32K144 */
#include "LPSPI.h"
#include "clocks_and_modes.h"
#include "GPIO.h"

#define MAIN_ub_PORT_PCR_ALTERNATIVE_3 ( (unsigned long) 3)

#define MAIN_ul_PIN_14 ( (unsigned long) 14 )
#define MAIN_ul_PIN_15 ( (unsigned long) 15 )
#define MAIN_ul_PIN_16 ( (unsigned long) 16 )
#define MAIN_ul_PIN_17 ( (unsigned long) 17 )

  uint16_t tx_16bits = 0xFD00;  /* SBC UJA1169: read Dev ID Reg @ 0x7E (expect non-zero)*/
                                /* Note: Obsolete EVB with MC33903 example used 0c2580 */
  	  	  	  	  	  	  	  	/*       to read SAFE reg flags (expect nonzero result).*/
  uint16_t LPSPI1_16bits_read;  /* Returned data in to SPI */


char MAIN_c_SPI_Tx_Buffer[10] = {'a','A','b','B','h','o','l','a',':',')'};
unsigned char iterator;
unsigned char valorAleatorio;

void WD_v_Disable (void)
{
  WDOG->CNT=0xD928C520;     /*Unlock watchdog*/
  WDOG->TOVAL=0x0000FFFF;   /*Maximum timeout value*/
  WDOG->CS = 0x00002100;    /*Disable watchdog*/
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

int main(void)
{

  WD_v_Disable();
  SOSC_init_8MHz();        		/* Initialize system oscillator for 8 MHz xtal */
  SPLL_init_160MHz();      		/* Initialize SPLL to 160 MHz with 8 MHz SOSC */
  NormalRUNmode_80MHz();   		/* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
  LPSPI1_v_Initialization();    /* Initialize LPSPI 1 as master */
  PORT_v_InitializeSPI_Pins();  /* Configure ports */
  iterator = 0;



  for(;;)
  {

	  LPSPI1_v_Send_8_bits_Data(0xf1);

	  LPSPI1_16bits_read = LPSPI1_v_Receive_16bits_Data();
	  if  (LPSPI1_16bits_read == 0X00){


	  }
  }

}
