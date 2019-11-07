/*
 * SPI1.h
 *
 *  Created on: 05/11/2019
 *      Author: alabe
 */

#ifndef SPI1_H_
#define SPI1_H_

typedef unsigned short int  uint16_t;

extern void LPSPI1_v_Initialization (void);
extern void LPSPI1_v_Send_8_bits_Data ( char ui_Data );
extern unsigned short int LPSPI1_v_Receive_16bits_Data (void);
extern unsigned char LPSPI_uc_GetRandomValueVariable( void );

#endif /* SPI1_H_ */
