/*
 * gpio.h
 *
 *  Created on: 05/11/2018
 *      Author: azpei
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
typedef char char_t;

void GPIO_Clock_Set_Up(uint8_t portIndex);

void GPIO_Init_As_Input(char_t port, uint8_t pinNumber);

uint8_t GPIO_Read_Input(char_t port, uint8_t pinNumber);

uint8_t GPIO_Read_Input_Interrupt(char_t port, uint8_t pinNumber);

void GPIO_Init_As_Output(char_t port, uint8_t pinNumber);

void GPIO_Set_Off_Output(char_t port, uint8_t pinNumber);

void GPIO_Set_On_Output(char_t port, uint8_t pinNumber);

void GPIO_Toggle(char_t port, uint8_t pinNumber);

void GPIO_Clear_Interrupt(char_t port, uint8_t pinNumber);

void GPIO_Enable_Port_Interrupt(char_t port);

#endif /* GPIO_H_ */
