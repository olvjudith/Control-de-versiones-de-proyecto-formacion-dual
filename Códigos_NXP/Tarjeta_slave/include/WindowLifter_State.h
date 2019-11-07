/*
 * WindowLifter_State.h
 *
 *  Created on: Nov 4, 2019
 *      Author: cvite
 */

#ifndef WINDOWLIFTER_STATs_H_
#define WINDOWLIFTER_STATs_H_

void Configuring(void);
void ReadButtons(void);
void ButtonValid(void);
void SendBajar(void);
void SendSubir(void);
void MessageValid(void);
void Error(void);
void Wait(void);

extern void LPSPI1_v_Send_8_bits_Data ( char ui_Data );    //FUNCIONES DE SPI
extern unsigned short int LPSPI1_v_Receive_16bits_Data (void);

#endif /* WINDOWLIFTER_STATS_H_ */
