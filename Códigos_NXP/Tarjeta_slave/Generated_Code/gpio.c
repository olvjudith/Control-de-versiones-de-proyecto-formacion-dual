/*
 * gpio.c
 *
 *  Created on: 05/11/2018
 *      Author: azpei
 */

#include "S32K144.h"
#include <gpio.h>

void GPIO_Clock_Set_Up(uint8_t port)
{
	  switch (port)
	  {
	    case 'A':
	    	PCC-> PCCn[PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK;
	      break;
	    case 'B':
	    	PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK;
	      break;
	    case 'C':
	    	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;
	      break;
	    case 'D':
	    	PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
	      break;
	    case 'E':
	    	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
	      break;
	    default:
	      break;
	  }

}

void GPIO_Init_As_Input(char_t port, uint8_t pinNumber)
{
  uint32_t pinAsGpioInterrputEnable = 0x00098110;
  switch (port)
  {
    case 'A':
      PTA->PDDR &= ~(1<<pinNumber);
      PORTA->PCR[pinNumber] = pinAsGpioInterrputEnable;
      break;
    case 'B':
      PTB->PDDR &= ~(1<<pinNumber);
      PORTB->PCR[pinNumber] = pinAsGpioInterrputEnable;
      break;
    case 'C':
      PTC->PDDR &= ~(1<<pinNumber);
      PORTC->PCR[pinNumber] = pinAsGpioInterrputEnable;
      break;
    case 'D':
      PTD->PDDR &= ~(1<<pinNumber);
      PORTD->PCR[pinNumber] = pinAsGpioInterrputEnable;
      break;
    case 'E':
      PTE->PDDR &= ~(1<<pinNumber);
      PORTE->PCR[pinNumber] = pinAsGpioInterrputEnable;
      break;
    default:
      break;
  }
}

uint8_t GPIO_Read_Input(char_t port, uint8_t pinNumber)
{
  uint8_t output = 0;
  switch (port)
  {
    case 'A':
      output = (PTA->PDIR & (1<<pinNumber))>>pinNumber;
      break;
    case 'B':
      output = (PTB->PDIR & (1<<pinNumber))>>pinNumber;
      break;
    case 'C':
      output = (PTC->PDIR & (1<<pinNumber))>>pinNumber;
      break;
    case 'D':
      output = (PTD->PDIR & (1<<pinNumber))>>pinNumber;
      break;
    case 'E':
      output = (PTE->PDIR & (1<<pinNumber))>>pinNumber;
      break;
    default:
      break;
  }
  return output;
}

uint8_t GPIO_Read_Input_Interrupt(char_t port, uint8_t pinNumber)
{
  uint8_t output = 0;
  switch (port)
  {
    case 'A':
      output = (PORTA->ISFR & (1<<pinNumber))>>pinNumber;
      break;
    case 'B':
      output = (PORTB->ISFR & (1<<pinNumber))>>pinNumber;
      break;
    case 'C':
      output = (PORTC->ISFR & (1<<pinNumber))>>pinNumber;
      break;
    case 'D':
      output = (PORTD->ISFR & (1<<pinNumber))>>pinNumber;
      break;
    case 'E':
      output = (PORTE->ISFR & (1<<pinNumber))>>pinNumber;
      break;
    default:
      break;
  }
  return output;
}

void GPIO_Init_As_Output(char_t port, uint8_t pinNumber)
{
  uint32_t pinAsGpio = 0x00000100;
  switch (port)
  {
    case 'A':
      PTA->PDDR |= 1<<pinNumber;
      PORTA->PCR[pinNumber] = pinAsGpio;
      break;
    case 'B':
      PTB->PDDR |= 1<<pinNumber;
      PORTB->PCR[pinNumber] = pinAsGpio;
      break;
    case 'C':
      PTC->PDDR |= 1<<pinNumber;
      PORTC->PCR[pinNumber] = pinAsGpio;
      break;
    case 'D':
      PTD->PDDR |= 1<<pinNumber;
      PORTD->PCR[pinNumber] = pinAsGpio;
      break;
    case 'E':
      PTE->PDDR |= 1<<pinNumber;
      PORTE->PCR[pinNumber] = pinAsGpio;
      break;
    default:
      break;
  }
}

void GPIO_Set_Off_Output(char_t port, uint8_t pinNumber)
{
  switch (port)
  {
	case 'A':
	  PTA->PCOR |= 1<<pinNumber;
	  break;
	case 'B':
	  PTB->PCOR |= 1<<pinNumber;
	  break;
	case 'C':
	  PTC->PCOR |= 1<<pinNumber;
	  break;
	case 'D':
	  PTD->PCOR |= 1<<pinNumber;
	  break;
	case 'E':
	  PTE->PCOR |= 1<<pinNumber;
	  break;
	default:
	  break;
  }
}

void GPIO_Set_On_Output(char_t port, uint8_t pinNumber)
{
  switch (port)
  {
	case 'A':
	  PTA->PSOR |= 1<<pinNumber;
	  break;
	case 'B':
	  PTB->PSOR |= 1<<pinNumber;
	  break;
	case 'C':
	  PTC->PSOR |= 1<<pinNumber;
	  break;
	case 'D':
	  PTD->PSOR |= 1<<pinNumber;
	  break;
	case 'E':
	  PTE->PSOR |= 1<<pinNumber;
	  break;
	default:
	  break;
  }
}


void GPIO_Toggle(char_t port, uint8_t pinNumber)
{
  switch (port)
  {
	case 'A':
	  PTA->PTOR |= 1<<pinNumber;
	  break;
	case 'B':
	  PTB->PTOR |= 1<<pinNumber;
	  break;
	case 'C':
	  PTC->PTOR |= 1<<pinNumber;
	  break;
	case 'D':
	  PTD->PTOR |= 1<<pinNumber;
	  break;
	case 'E':
	  PTE->PTOR |= 1<<pinNumber;
	  break;
	default:
	  break;
  }
}

void GPIO_Clear_Interrupt(char_t port, uint8_t pinNumber)
{
  uint32_t regValue = 0;
  switch (port)
  {
	case 'A':
	  /* DEV_ASSERT(pinNumber < PORT_PCR_COUNT); */
	  regValue = PORTA->PCR[pinNumber];
	  regValue &= ~(PORT_PCR_ISF_MASK);
	  regValue |= PORT_PCR_ISF(1);
	  PORTA->PCR[pinNumber] = regValue;
	  break;
	case 'B':
	  /* DEV_ASSERT(pinNumber < PORT_PCR_COUNT); */
	  regValue = PORTB->PCR[pinNumber];
	  regValue &= ~(PORT_PCR_ISF_MASK);
	  regValue |= PORT_PCR_ISF(1);
	  PORTB->PCR[pinNumber] = regValue;
	  break;
	case 'C':
	  /* DEV_ASSERT(pinNumber < PORT_PCR_COUNT); */
	  regValue = PORTC->PCR[pinNumber];
	  regValue &= ~(PORT_PCR_ISF_MASK);
	  regValue |= PORT_PCR_ISF(1);
	  PORTC->PCR[pinNumber] = regValue;
	  break;
	case 'D':
	  /* DEV_ASSERT(pinNumber < PORT_PCR_COUNT); */
	  regValue = PORTD->PCR[pinNumber];
	  regValue &= ~(PORT_PCR_ISF_MASK);
	  regValue |= PORT_PCR_ISF(1);
	  PORTD->PCR[pinNumber] = regValue;
	  break;
	case 'E':
	  /* DEV_ASSERT(pinNumber < PORT_PCR_COUNT); */
	  regValue = PORTE->PCR[pinNumber];
	  regValue &= ~(PORT_PCR_ISF_MASK);
	  regValue |= PORT_PCR_ISF(1);
	  PORTE->PCR[pinNumber] = regValue;
	  break;
	default:
	  break;
  }
}

  void GPIO_Enable_Port_Interrupt(char_t port)
  {
	  switch (port)
	  {
	    case 'A':
	    	S32_NVIC->ISER[(uint32_t)(PORTA_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(PORTA_IRQn) & (uint32_t)0x1FU));
	      break;
	    case 'B':
	    	S32_NVIC->ISER[(uint32_t)(PORTB_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(PORTB_IRQn) & (uint32_t)0x1FU));
	      break;
	    case 'C':
	    	S32_NVIC->ISER[(uint32_t)(PORTC_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(PORTC_IRQn) & (uint32_t)0x1FU));
	      break;
	    case 'D':
	    	S32_NVIC->ISER[(uint32_t)(PORTD_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(PORTD_IRQn) & (uint32_t)0x1FU));
	      break;
	    case 'E':
	    	S32_NVIC->ISER[(uint32_t)(PORTE_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(PORTE_IRQn) & (uint32_t)0x1FU));
	      break;
	    default:
	      break;
	  }
  }

