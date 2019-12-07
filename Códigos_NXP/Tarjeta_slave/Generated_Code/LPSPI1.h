/*
 * LPSPI1.h
 *
 *  Created on: 07/11/2019
 *      Author: alabe
 */

#ifndef LPSPI1_H_
#define LPSPI1_H_

extern void PORT_v_InitializeSPI_Pins (void);
extern void LPSPI1_v_Initialization (void);
extern void LPSPI1_v_Send_8_bits_Data ( char ui_Data );
extern uint16_t LPSPI1_v_Receive_16bits_Data (void);
extern unsigned char LPSPI_uc_GetRandomValueVariable( void );

#endif /* LPSPI1_H_ */
