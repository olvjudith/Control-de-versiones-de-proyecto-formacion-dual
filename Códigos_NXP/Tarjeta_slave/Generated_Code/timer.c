#include <timer.h>
#include "S32K144.h"

#ifndef GPIO_H_
#include <gpio.h>
#endif

#ifndef STDINT_H_
#include <stdint.h>
#endif

void TIMER_Delay_Milliseconds (uint32_t msTimerDuration) {
  PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(SPLL2_DIV2_CLK); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
  LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
  LPIT0->MIER = 0x00000001; /*Timer Interrupt Enabled for Chan 0 */
  LPIT0->TMR[0].TVAL = msTimerDuration*CLOCK_BASE; /* Timer period */
  LPIT0->TMR[0].TCTRL = 0x00000001; /* Timer enable */
  while(0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK));
  LPIT0->MSR |= LPIT_MSR_TIF0_MASK;
  LPIT0->TMR[0].TCTRL = 0x00000000; /* Timer disable */
}

uint8_t TIMER_Button_Pressed_With_Duration_Criteria (uint8_t port, uint8_t pinNumber, uint32_t msTimerDuration)
{
  uint8_t finished = 0;
  PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(SPLL2_DIV2_CLK); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
  LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
  LPIT0->MIER = 0x00000002; /*Timer Interrupt Enabled for Chan 1 */
  LPIT0->TMR[1].TVAL = msTimerDuration*CLOCK_BASE; /* Timer period */
  LPIT0->TMR[1].TCTRL = 0x00000001; /* Timer enable */
  while((0 == (LPIT0->MSR & LPIT_MSR_TIF1_MASK)) && (GPIO_Read_Input(port, pinNumber)==1));
  if ((LPIT_MSR_TIF1_MASK == (LPIT0->MSR & LPIT_MSR_TIF1_MASK)) && (GPIO_Read_Input(port, pinNumber)==1))
  {
    finished = 1;
  }
  LPIT0->MSR |= LPIT_MSR_TIF1_MASK;
  LPIT0->TMR[1].TCTRL = 0x00000000; /* Timer disable */

  return finished;
}
