/*
 * window.c
*/
#include "window.h"



void WINDOW_State_Initialize()
{
  CLOCK_SOSC_Init_8MHz();
  CLOCK_SPLL_Init_160MHz();
  CLOCK_Setup_80MHz();
  CLOCK_Disable_Watchdog();
  PORT_v_InitializeSPI_Pins ();
  LPSPI1_v_Initialization();


  GPIO_Clock_Set_Up(PRT_A);
  GPIO_Clock_Set_Up(PRT_C);
  GPIO_Clock_Set_Up(PRT_D);
  GPIO_Clock_Set_Up(PRT_E);

  GPIO_Init_As_Input(PRT_C,  PIN_12);
  GPIO_Init_As_Input(PRT_C,  PIN_13);
  GPIO_Init_As_Input(PRT_C,  PIN_17);

  GPIO_Enable_Port_Interrupt(PRT_C);


  GPIO_Init_As_Output(PRT_A,  PIN_11);
  GPIO_Init_As_Output(PRT_A,  PIN_17);
  GPIO_Init_As_Output(PRT_D,   PIN_0);//Se cambia por led rojo
  GPIO_Init_As_Output(PRT_D,   PIN_3);
  GPIO_Init_As_Output(PRT_D,   PIN_5);
  GPIO_Init_As_Output(PRT_D,  PIN_10);
  GPIO_Init_As_Output(PRT_D,  PIN_11);
  GPIO_Init_As_Output(PRT_D,  PIN_12);
  GPIO_Init_As_Output(PRT_D,  PIN_16);
  GPIO_Init_As_Output(PRT_E,   PIN_3);
  GPIO_Init_As_Output(PRT_E,   PIN_4);
  GPIO_Init_As_Output(PRT_E,   PIN_5);

  GPIO_Set_Off_Output(PRT_A,  PIN_11);
  GPIO_Set_Off_Output(PRT_A,  PIN_17);
  GPIO_Set_On_Output(PRT_D,    PIN_0);
  GPIO_Set_On_Output(PRT_D,   PIN_16);
  GPIO_Set_Off_Output(PRT_D,   PIN_3);
  GPIO_Set_Off_Output(PRT_D,   PIN_5);
  GPIO_Set_Off_Output(PRT_D,  PIN_10);
  GPIO_Set_Off_Output(PRT_D,  PIN_11);
  GPIO_Set_Off_Output(PRT_D,  PIN_12);
  GPIO_Set_Off_Output(PRT_E,   PIN_3);
  GPIO_Set_Off_Output(PRT_E,   PIN_4);
  GPIO_Set_Off_Output(PRT_E,   PIN_5);
}


