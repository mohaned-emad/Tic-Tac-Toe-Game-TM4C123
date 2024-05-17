#ifndef GPIO_H
#define GPIO_H
#include "Gpio_cfg.h"

void enableInterrupts(void);

typedef enum Gpio_Ret_e{
  GPIO_RET_OK,
  GPIO_RET_ERROR,
}Gpio_Ret_t;

typedef enum Gpio_port_e{
	GPIO_PORT_A = 0,
  GPIO_PORT_B,
  GPIO_PORT_C,
  GPIO_PORT_D,
  GPIO_PORT_E,
  GPIO_PORT_F,
}Gpio_port_t;

typedef enum Gpio_pin_e{
	GPIO_PIN_0 = 0,
  GPIO_PIN_1,
  GPIO_PIN_2,
  GPIO_PIN_3,
  GPIO_PIN_4,
  GPIO_PIN_5,
  GPIO_PIN_6,
  GPIO_PIN_7,
}Gpio_pin_t;

typedef enum Gpio_direction_e{
  GPIO_DIRECTION_INPUT = 0,
	GPIO_DIRECTION_OUTPUT,
}Gpio_direction_t;

typedef enum Gpio_DigitalAnalog_e{
  GPIO_MODE_DIGITAL = 0,
	GPIO_MODE_ANALOG,
}Gpio_DigitalAnalog_t;

typedef enum Gpio_Enable_e{
	GPIO_DISABLE = 0,
  GPIO_ENABLE,
}Gpio_Enable_t;

typedef enum Gpio_InterruptSense_e{
	GPIO_EDGE = 0,
	GPIO_LEVEL,
}Gpio_InterruptSense_t;

typedef enum Gpio_Interrupt_Edge_e{
	GPIO_SINGLE_EDGE = 0,
	GPIO_BOTH_EDGES,
}Gpio_Interrupt_Edge_t;

typedef enum Gpio_Interrupt_Level_e{
	GPIO_FALLING_EDGE = 0,
	GPIO_RISING_EDGE,
}Gpio_Interrupt_Level_t;

typedef enum Gpio_Interrupt_Mask_e{
	GPIO_MASKED = 0,
	GPIO_NOT_MASKED,
}Gpio_Interrupt_Mask_t;

typedef enum Gpio_portEnable_e{
	GPIO_PORT_ENABLE = 0,
	GPIO_PORT_DISABLE
}Gpio_portEnable_t;

typedef struct Gpio_pinConfig_s{
	Gpio_DigitalAnalog_t digitalAnalogSelector;
	Gpio_direction_t pinDirection;
	Gpio_Enable_t pullUp;
	Gpio_Enable_t pullDown;
	Gpio_Enable_t alternateFunction;
	Gpio_Enable_t interrupts;
	Gpio_InterruptSense_t sense;
	Gpio_Interrupt_Edge_t edge;
	Gpio_Interrupt_Level_t level;
	Gpio_Interrupt_Mask_t mask;
}Gpio_pinConfig_t;

typedef struct Gpio_portConfig_s{
	Gpio_pinConfig_t pinsCfgs[PIN_MAX_NUM];
	Gpio_portEnable_t portEnable;
}Gpio_portConfig_t;

typedef struct Gpio_config_s{
    Gpio_portConfig_t portsCfgs[PORT_MAX_NUM];
}Gpio_config_t;


Gpio_Ret_t Gpio_init(Gpio_config_t *config, Gpio_port_t portNum);

Gpio_Ret_t Gpio_setDirection(Gpio_port_t port, Gpio_pin_t pin, Gpio_direction_t direction);

Gpio_Ret_t Gpio_DigitalAnalogSelector(Gpio_port_t port, Gpio_pin_t pin, Gpio_DigitalAnalog_t digitalAnalogSelector);

extern Gpio_config_t portFCfg;
extern Gpio_config_t portBCfg;

void EnableInterrupts(void);

#endif
