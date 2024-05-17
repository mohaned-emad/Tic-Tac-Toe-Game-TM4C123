#include "Gptm.h"

Gptm_Config_t Timer0_Config = {
  .Timer[GPTM_TIMER_0] = {
    .Mode = GPTM_MODE_ONESHOT,
    .Control = GPTM_CONTROL_ENABLE,
    .Configuration = GPTM_CONFIGURATION_32_BIT,
    .Direction = GPTM_DIRECTION_DOWN,
  },
};
