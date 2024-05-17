#ifndef GPTM_H
#define GPTM_H
#include "Gptm_cfg.h"

typedef enum Gptm_Ret_e{
  GPTM_OK,
  GPTM_ERROR,
}Gptm_Ret_t;

typedef enum Gptm_Timer_e{
  GPTM_TIMER_0,
  GPTM_TIMER_1,
  GPTM_TIMER_2,
  GPTM_TIMER_3,
  GPTM_TIMER_4,
  GPTM_TIMER_5,
}Gptm_Timer_t;

typedef enum Gptm_Mode_e{
  GPTM_MODE_ONESHOT,
  GPTM_MODE_PERIODIC,
  GPTM_MODE_CAPTURE,
  GPTM_MODE_PWM,
}Gptm_Mode_t;

typedef enum Gptm_Direction_e{
    GPTM_DIRECTION_UP,
    GPTM_DIRECTION_DOWN,
}Gptm_Direction_t;

typedef enum Gptm_Control_e{
  GPTM_CONTROL_ENABLE,
  GPTM_CONTROL_DISABLE,
}Gptm_Control_t;

typedef enum Gptm_Configuration_e{
  GPTM_CONFIGURATION_16_BIT,
  GPTM_CONFIGURATION_32_BIT,
}Gptm_Configuration_t;

typedef struct Gptm_Timer_Config_s {
  Gptm_Mode_t Mode;
  Gptm_Control_t Control;
  Gptm_Configuration_t Configuration;
  Gptm_Direction_t Direction;
}Gptm_Timer_Config_t;


typedef struct Gptm_Config_s{
  Gptm_Timer_Config_t Timer[MAX_TIMERS_NUM];
}Gptm_Config_t;

Gptm_Ret_t Gptm_Init(Gptm_Config_t* Config, Gptm_Timer_t Timer, unsigned long period);

extern Gptm_Config_t Timer0_Config;
extern Gptm_Config_t Timer1_Config;
extern Gptm_Config_t Timer2_Config;
extern Gptm_Config_t Timer3_Config;
extern Gptm_Config_t Timer4_Config;
extern Gptm_Config_t Timer5_Config;

#endif
