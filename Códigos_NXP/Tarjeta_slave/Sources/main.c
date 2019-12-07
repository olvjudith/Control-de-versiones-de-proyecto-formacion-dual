#include <window.h>
#include <LPSPI1.h>

uint8_t windowPosition = 00;
uint8_t windowMovement = INITIALIZE;
uint8_t antiPinchFlag = FALSE;

uint16_t LPSPI1_16bits_read=0x00;


int main(void)
{
	WINDOW_State_Initialize();

  while(1)
  {
  LPSPI1_16bits_read = LPSPI1_v_Receive_16bits_Data ();

    switch(LPSPI1_16bits_read)
    {
      case (0xef):
      {

      GPIO_Set_On_Output(PRT_E, PIN_5);
     GPIO_Set_Off_Output(PRT_A,  PIN_11);
     GPIO_Set_Off_Output(PRT_E,  PIN_4);

  	 GPIO_Set_Off_Output(PRT_A,  PIN_17);

      } break;
      case (0xf0):
      {

   	   GPIO_Set_On_Output(PRT_E,   PIN_4);
       GPIO_Set_On_Output(PRT_E, PIN_5);
       GPIO_Set_Off_Output(PRT_A,  PIN_11);
       GPIO_Set_Off_Output(PRT_A,  PIN_17);
      } break;
      case (0xf1):
      {
      	  GPIO_Set_On_Output(PRT_E,   PIN_4);
          GPIO_Set_On_Output(PRT_E, PIN_5);
      	  GPIO_Set_On_Output(PRT_A,  PIN_11);
      	  GPIO_Set_Off_Output(PRT_A,  PIN_17);


      } break;
      case (0xf2):
      {
      	  GPIO_Set_On_Output(PRT_E,   PIN_4);
          GPIO_Set_On_Output(PRT_E, PIN_5);
      	  GPIO_Set_On_Output(PRT_A,  PIN_11);
     	  GPIO_Set_On_Output(PRT_A,  PIN_17);



      } break;


      default:
          GPIO_Set_Off_Output(PRT_E, PIN_5);
         GPIO_Set_Off_Output(PRT_A,  PIN_11);
         GPIO_Set_Off_Output(PRT_E,  PIN_4);

      	 GPIO_Set_Off_Output(PRT_A,  PIN_17);
        break;
    }
  }
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  //for(;;) {
    //if(exit_code != 0) {
     // break;
    //}
  //}
  return 0;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
