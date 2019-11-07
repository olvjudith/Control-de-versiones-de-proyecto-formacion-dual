/*
 * WindowLifter.h
 *
 *  Created on: Nov 4, 2019
 *      Author: cvite
 */

#ifndef WINDOWLIFTER_H_
#define WINDOWLIFTER_H_

typedef enum				//Definicion de tipo de datos. CONJUNTO
{
	e_Configuring = 0,
	e_ReadButtons,
	e_ButtonValid,
	e_SendBajar,
	e_SendSubir,
	e_MessageValid,
	e_Error,
	e_Wait
} e_WL_States; 				//Nombre de la variable del tipo de datos

void WindowLifter(void);

#endif /* WINDOWLIFTER_H_ */
