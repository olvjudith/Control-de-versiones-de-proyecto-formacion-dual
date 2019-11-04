/* LPSPI.h              (c) 2016 Freescale Semiconductor, Inc.
 * Descriptions: FTM example code.
 * May 31 2016: Initial version
 */


#ifndef LPSPI_H_
#define LPSPI_H_

extern void LPSPI1_v_Initialization (void);
extern void LPSPI1_v_Send_8_bits_Data ( char ui_Data );
extern uint16_t LPSPI1_v_Receive_16bits_Data (void);
extern unsigned char LPSPI_uc_GetRandomValueVariable( void );
#endif /* LPSPI_H_ */
