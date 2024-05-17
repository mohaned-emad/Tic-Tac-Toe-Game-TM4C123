#include "Gpio.h"

Gpio_config_t portFCfg = {
	.portsCfgs[GPIO_PORT_F] = {
		.portEnable = GPIO_PORT_ENABLE,
		.pinsCfgs[GPIO_PIN_0] = {
			.digitalAnalogSelector = GPIO_MODE_DIGITAL,
			.pinDirection = GPIO_DIRECTION_INPUT,
			.pullUp = GPIO_ENABLE,
			.pullDown = GPIO_DISABLE,
			.alternateFunction = GPIO_DISABLE,
			.interrupts = GPIO_ENABLE,
			.sense = GPIO_EDGE,
			.edge = GPIO_SINGLE_EDGE,
			.level = GPIO_FALLING_EDGE,
			.mask = GPIO_NOT_MASKED,
		},
		.pinsCfgs[GPIO_PIN_1] = {
			.digitalAnalogSelector = GPIO_MODE_DIGITAL,
			.pinDirection = GPIO_DIRECTION_OUTPUT,
			.pullUp = GPIO_DISABLE,
			.pullDown = GPIO_DISABLE,
			.alternateFunction = GPIO_DISABLE,
		},
		.pinsCfgs[GPIO_PIN_2] = {
			.digitalAnalogSelector = GPIO_MODE_DIGITAL,
			.pinDirection = GPIO_DIRECTION_OUTPUT,
			.pullUp = GPIO_DISABLE,
			.pullDown = GPIO_DISABLE,
			.alternateFunction = GPIO_DISABLE,
		},
		.pinsCfgs[GPIO_PIN_3] = {
			.digitalAnalogSelector = GPIO_MODE_DIGITAL,
			.pinDirection = GPIO_DIRECTION_OUTPUT,
			.pullUp = GPIO_DISABLE,
			.pullDown = GPIO_DISABLE,
			.alternateFunction = GPIO_DISABLE,
		},
		.pinsCfgs[GPIO_PIN_4] = {
			.digitalAnalogSelector = GPIO_MODE_DIGITAL,
			.pinDirection = GPIO_DIRECTION_INPUT,
			.pullUp = GPIO_ENABLE,
			.pullDown = GPIO_DISABLE,
			.alternateFunction = GPIO_DISABLE,
			.interrupts = GPIO_ENABLE,
			.sense = GPIO_EDGE,
			.edge = GPIO_SINGLE_EDGE,
			.level = GPIO_FALLING_EDGE,
			.mask = GPIO_NOT_MASKED,
		},
	},	
};

Gpio_config_t portBCfg = {
	.portsCfgs[GPIO_PORT_B] = {
		.portEnable = GPIO_PORT_ENABLE,
		.pinsCfgs[GPIO_PIN_0] = {
			.digitalAnalogSelector = GPIO_MODE_DIGITAL,
			.pinDirection = GPIO_DIRECTION_INPUT,
			.pullUp = GPIO_ENABLE,
			.pullDown = GPIO_DISABLE,
			.alternateFunction = GPIO_DISABLE,
			.interrupts = GPIO_ENABLE,
			.sense = GPIO_EDGE,
			.edge = GPIO_SINGLE_EDGE,
			.level = GPIO_FALLING_EDGE,
			.mask = GPIO_NOT_MASKED,
		},
	},	
};
