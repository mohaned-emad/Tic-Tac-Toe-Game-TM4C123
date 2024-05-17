#include "Gptm.h"
#include "../DataSheets/tm4c123gh6pm11.h"

Gptm_Ret_t Gptm_Init(Gptm_Config_t* Config, Gptm_Timer_t Timer, unsigned long period){
  volatile unsigned long delay;
  switch (Timer)
  {
  case GPTM_TIMER_0:
    SYSCTL_RCGCTIMER_R |= (1 << 0);
    delay = SYSCTL_RCGCTIMER_R;
    TIMER0_CTL_R = 0x0;

    if (Config->Timer[GPTM_TIMER_0].Mode == GPTM_MODE_ONESHOT)
      TIMER0_TAMR_R = 0x1;
    else if (Config->Timer[GPTM_TIMER_0].Mode == GPTM_MODE_PERIODIC)
      TIMER0_TAMR_R = 0x2;

    if (Config->Timer[GPTM_TIMER_0].Configuration == GPTM_CONFIGURATION_16_BIT)
      TIMER0_CFG_R = 0x4;
    else
      TIMER0_CFG_R = 0x0;

    TIMER0_TAILR_R = 80000000 * period;
    TIMER0_TAPR_R = 0;
    TIMER0_ICR_R |= 0x1;
    TIMER0_IMR_R |= 0x1;
    NVIC_PRI4_R = (NVIC_PRI4_R & 0x00FFFFFF) | 0x80000000;
    NVIC_EN0_R = 1 << 19;
    TIMER0_CTL_R |= 0x1;

    break;
  
  case GPTM_TIMER_1:
    SYSCTL_RCGCTIMER_R |= (1 << 1);
    delay = SYSCTL_RCGCTIMER_R;
    TIMER1_CTL_R = 0x0;

    if (Config->Timer[GPTM_TIMER_1].Mode == GPTM_MODE_ONESHOT)
        TIMER1_TAMR_R = 0x1;
    else if (Config->Timer[GPTM_TIMER_1].Mode == GPTM_MODE_PERIODIC)
        TIMER1_TAMR_R = 0x2;

    if (Config->Timer[GPTM_TIMER_1].Configuration == GPTM_CONFIGURATION_16_BIT)
        TIMER1_CFG_R = 0x4;
    else
        TIMER1_CFG_R = 0x0;

    TIMER1_TAILR_R = period - 1;
    TIMER1_TAPR_R = 0;
    TIMER1_ICR_R |= 0x1;
    TIMER1_IMR_R |= 0x1;
    NVIC_PRI5_R = (NVIC_PRI5_R & 0x00FFFFFF) | 0x80000000;
    NVIC_EN0_R |= 1 << 21;
    TIMER1_CTL_R |= 0x1;
    
    break;

  case GPTM_TIMER_2:
    SYSCTL_RCGCTIMER_R |= (1 << 2);
    delay = SYSCTL_RCGCTIMER_R;
    TIMER2_CTL_R = 0x0;

    if (Config->Timer[GPTM_TIMER_2].Mode == GPTM_MODE_ONESHOT)
        TIMER2_TAMR_R = 0x1;
    else if (Config->Timer[GPTM_TIMER_2].Mode == GPTM_MODE_PERIODIC)
        TIMER2_TAMR_R = 0x2;
    
    if (Config->Timer[GPTM_TIMER_2].Configuration == GPTM_CONFIGURATION_16_BIT)
        TIMER2_CFG_R = 0x4;
    else
        TIMER2_CFG_R = 0x0;

    TIMER2_TAILR_R = period - 1;
    TIMER2_TAPR_R = 0;
    TIMER2_ICR_R |= 0x1;
    TIMER2_IMR_R |= 0x1;

    NVIC_PRI5_R = (NVIC_PRI5_R & 0x00FFFFFF) | 0x80000000;
    NVIC_EN0_R |= 1 << 23;
    TIMER2_CTL_R |= 0x1;

    break;

  case GPTM_TIMER_3:
    SYSCTL_RCGCTIMER_R |= (1 << 3);
    delay = SYSCTL_RCGCTIMER_R;
    TIMER3_CTL_R = 0x0;

    if (Config->Timer[GPTM_TIMER_3].Mode == GPTM_MODE_ONESHOT)
        TIMER3_TAMR_R = 0x1;
    else if (Config->Timer[GPTM_TIMER_3].Mode == GPTM_MODE_PERIODIC)
        TIMER3_TAMR_R = 0x2;

    if (Config->Timer[GPTM_TIMER_3].Configuration == GPTM_CONFIGURATION_16_BIT)
        TIMER3_CFG_R = 0x4;
    else
        TIMER3_CFG_R = 0x0;

    TIMER3_TAILR_R = period - 1;
    TIMER3_TAPR_R = 0;
    TIMER3_ICR_R |= 0x1;
    TIMER3_IMR_R |= 0x1;
    
    NVIC_PRI8_R = (NVIC_PRI8_R & 0x00FFFFFF) | 0x80000000;
    NVIC_EN1_R |= 1 << 3;
    TIMER3_CTL_R |= 0x1;

    break;

  case GPTM_TIMER_4:
    SYSCTL_RCGCTIMER_R |= (1 << 4);
		delay = SYSCTL_RCGCTIMER_R;
    TIMER4_CTL_R = 0x0;

    if (Config->Timer[GPTM_TIMER_3].Mode == GPTM_MODE_ONESHOT)
        TIMER4_TAMR_R = 0x1;
    else if (Config->Timer[GPTM_TIMER_3].Mode == GPTM_MODE_PERIODIC)
        TIMER4_TAMR_R = 0x2;

    if (Config->Timer[GPTM_TIMER_3].Configuration == GPTM_CONFIGURATION_16_BIT)
        TIMER4_CFG_R = 0x4;
    else
        TIMER4_CFG_R = 0x0;

    TIMER4_TAILR_R = period - 1;
    TIMER4_TAPR_R = 0;
    TIMER4_ICR_R |= 0x1;
    TIMER4_IMR_R |= 0x1;
    
    NVIC_PRI8_R = (NVIC_PRI8_R & 0x00FFFFFF) | 0x80000000;
    NVIC_EN1_R |= 1 << 3;
    TIMER4_CTL_R |= 0x1;
	
    break;

  case GPTM_TIMER_5:
    SYSCTL_RCGCTIMER_R |= (1 << 5);
    delay = SYSCTL_RCGCTIMER_R;
    TIMER5_CTL_R = 0x0;

    if (Config->Timer[GPTM_TIMER_3].Mode == GPTM_MODE_ONESHOT)
        TIMER5_TAMR_R = 0x1;
    else if (Config->Timer[GPTM_TIMER_3].Mode == GPTM_MODE_PERIODIC)
        TIMER5_TAMR_R = 0x2;

    if (Config->Timer[GPTM_TIMER_3].Configuration == GPTM_CONFIGURATION_16_BIT)
        TIMER5_CFG_R = 0x4;
    else
        TIMER5_CFG_R = 0x0;

    TIMER5_TAILR_R = period - 1;
    TIMER5_TAPR_R = 0;
    TIMER5_ICR_R |= 0x1;
    TIMER5_IMR_R |= 0x1;
    
    NVIC_PRI8_R = (NVIC_PRI8_R & 0x00FFFFFF) | 0x80000000;
    NVIC_EN1_R |= 1 << 3;
    TIMER5_CTL_R |= 0x1;  
	
		break;

  default:
    break;
  }
  
  return GPTM_OK;
}
