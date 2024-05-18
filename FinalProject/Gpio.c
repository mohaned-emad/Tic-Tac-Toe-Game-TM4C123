#include "Gpio.h"
#include "../DataSheets/tm4c123gh6pm11.h"

Gpio_Ret_t Gpio_init(Gpio_config_t *config, Gpio_port_t portNum){
	volatile int delay;
	int flag;
	int pinNum;
    switch (portNum)
    {
    case GPIO_PORT_A:
        SYSCTL_RCGC2_R |= (1 << portNum);
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        delay = SYSCTL_RCGC2_R;
        flag = 0;
        for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            // set commit register
            GPIO_PORTA_CR_R |= (1 << pinNum);
            // Set pin direction
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                GPIO_PORTA_DIR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTA_DIR_R &= ~(1 << pinNum);
            }
            // set alternate function
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTA_AFSEL_R |= (1 << pinNum);
                GPIO_PORTA_PCTL_R |= (0xf << 4 * pinNum);
            }
            else{
                GPIO_PORTA_AFSEL_R &= ~(1 << pinNum);
                GPIO_PORTA_PCTL_R &= ~(0xf << 4 * pinNum);
            }
            // set digital or analog functionality
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTA_DEN_R |= (1 << pinNum);
                GPIO_PORTA_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTA_DEN_R &= ~(1 << pinNum);
                GPIO_PORTA_AMSEL_R |= (1 << pinNum);
            }

            // set pollup resistor
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTA_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTA_PUR_R &= ~(1 << pinNum);
            }

            // set interrupt
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTA_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTA_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTA_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTA_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTA_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTA_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTA_ICR_R |= (1 << pinNum);
                GPIO_PORTA_IM_R |= (1 << pinNum);
            }
        }
        if (flag == 1){
          NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFF00)|0x000000A0; // (g) priority 5
					NVIC_EN0_R = 1;
					EnableInterrupts();
        }
        break;
    case GPIO_PORT_B:
        SYSCTL_RCGC2_R |= (1 << portNum);
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        delay = SYSCTL_RCGC2_R;
        flag = 0;
        for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            // set commit register
            GPIO_PORTB_CR_R |= (1 << pinNum);
            // Set pin direction
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                GPIO_PORTB_DIR_R &= ~(1 << pinNum);
            }
            else{
                GPIO_PORTB_DIR_R |= (1 << pinNum);
            }
            // set alternate function
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTB_AFSEL_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTB_AFSEL_R &= ~(1 << pinNum);
            }
            // set digital or analog functionality
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTB_DEN_R |= (1 << pinNum);
                GPIO_PORTB_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTB_DEN_R &= ~(1 << pinNum);
                GPIO_PORTB_AMSEL_R |= (1 << pinNum);
            }

            // set pollup resistor
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTB_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTB_PUR_R &= ~(1 << pinNum);
            }

            // set interrupt
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTB_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTB_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTB_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTB_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTB_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTB_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTB_ICR_R |= (1 << pinNum);
                GPIO_PORTB_IM_R |= (1 << pinNum);
            }
        }
        if (flag == 1){
          NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFF00)|0x000000A0; // (g) priority 5
					NVIC_EN0_R = 1 << 1;
					EnableInterrupts();
        }
        break;
				
		case GPIO_PORT_C:
				SYSCTL_RCGC2_R |= (1 << portNum);
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        delay = SYSCTL_RCGC2_R;
        flag = 0;
        for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {
            // set commit register
            GPIO_PORTC_CR_R |= (1 << pinNum);
            // Set pin direction
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                GPIO_PORTC_DIR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTC_DIR_R &= ~(1 << pinNum);
            }
            // set alternate function
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTC_AFSEL_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTC_AFSEL_R &= ~(1 << pinNum);
            }
            // set digital or analog functionality
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTC_DEN_R |= (1 << pinNum);
                GPIO_PORTC_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTC_DEN_R &= ~(1 << pinNum);
                GPIO_PORTC_AMSEL_R |= (1 << pinNum);
            }

            // set pollup resistor
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTC_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTC_PUR_R &= ~(1 << pinNum);
            }

            // set interrupt
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTC_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTC_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTC_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTC_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTC_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTC_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTC_ICR_R |= (1 << pinNum);
                GPIO_PORTC_IM_R |= (1 << pinNum);
            }
        }
        if (flag == 1){
          NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFF00)|0x000000A0; // (g) priority 5
					NVIC_EN0_R = 1 << 2;
					EnableInterrupts();
        }
        break;
		
		case GPIO_PORT_E:
        SYSCTL_RCGC2_R |= (1 << portNum);
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        delay = SYSCTL_RCGC2_R;
        flag = 0;
        for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {	
						if(pinNum > 4){
							break;
						}
            // set commit register
            GPIO_PORTE_CR_R |= (1 << pinNum);
            // Set pin direction
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                GPIO_PORTE_DIR_R &= ~(1 << pinNum);
            }
            else{
                GPIO_PORTE_DIR_R |= (1 << pinNum);
            }
            // set alternate function
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTE_AFSEL_R |= (1 << pinNum);
								GPIO_PORTE_PCTL_R |= (0xf << 4 * pinNum);
            }
            else{
                GPIO_PORTE_AFSEL_R &= ~(1 << pinNum);
								GPIO_PORTE_PCTL_R &= ~(0xf << 4 * pinNum);
            }
            // set digital or analog functionality
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTE_DEN_R |= (1 << pinNum);
                GPIO_PORTE_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTE_DEN_R &= ~(1 << pinNum);
                GPIO_PORTE_AMSEL_R |= (1 << pinNum);
            }

            // set pollup resistor
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTE_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTE_PUR_R &= ~(1 << pinNum);
            }
					}
        break;
				
    case GPIO_PORT_F:
        SYSCTL_RCGC2_R |= (1 << portNum);
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        delay = SYSCTL_RCGC2_R;
        flag = 0;
        for (pinNum = 0; pinNum < PIN_MAX_NUM; pinNum++)
        {	
						if(pinNum > 4){
							break;
						}
            // set commit register
            GPIO_PORTF_CR_R |= (1 << pinNum);
            // Set pin direction
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].pinDirection == GPIO_DIRECTION_INPUT){
                GPIO_PORTF_DIR_R &= ~(1 << pinNum);
            }
            else{
                GPIO_PORTF_DIR_R |= (1 << pinNum);
            }
            // set alternate function
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].alternateFunction == GPIO_ENABLE)
            {
                GPIO_PORTF_AFSEL_R |= (1 << pinNum);
								GPIO_PORTF_PCTL_R |= (0xf << 4 * pinNum);
            }
            else{
                GPIO_PORTF_AFSEL_R &= ~(1 << pinNum);
								GPIO_PORTF_PCTL_R &= ~(0xf << 4 * pinNum);
            }
            // set digital or analog functionality
            if(config->portsCfgs[portNum].pinsCfgs[pinNum].digitalAnalogSelector == GPIO_MODE_DIGITAL){
                GPIO_PORTF_DEN_R |= (1 << pinNum);
                GPIO_PORTF_AMSEL_R &= ~(1 << pinNum);
            }
            else {
                GPIO_PORTF_DEN_R &= ~(1 << pinNum);
                GPIO_PORTF_AMSEL_R |= (1 << pinNum);
            }

            // set pollup resistor
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].pullUp == GPIO_ENABLE){
                GPIO_PORTF_PUR_R |= (1 << pinNum);
            }
            else{
                GPIO_PORTF_PUR_R &= ~(1 << pinNum);
            }

            // set interrupt
            if (config->portsCfgs[portNum].pinsCfgs[pinNum].interrupts == GPIO_ENABLE){
                flag = 1;
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].sense == GPIO_EDGE) {
                    GPIO_PORTF_IS_R &= ~(1 << pinNum);
                }
                else {
                    GPIO_PORTF_IS_R |= (1 << pinNum);
                }
                if (config->portsCfgs[portNum].pinsCfgs[pinNum].edge == GPIO_SINGLE_EDGE){
                    GPIO_PORTF_IBE_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTF_IBE_R |= (1 << pinNum);
                }
                if(config->portsCfgs[portNum].pinsCfgs[pinNum].level == GPIO_FALLING_EDGE){
                    GPIO_PORTF_IEV_R &= ~(1 << pinNum);
                }
                else{
                    GPIO_PORTF_IEV_R |= (1 << pinNum);
                }
                GPIO_PORTF_ICR_R |= (1 << pinNum);
                GPIO_PORTF_IM_R |= (1 << pinNum);
            }
        }
        if (flag == 1){
          NVIC_PRI7_R = (NVIC_PRI0_R&0xFF00FFFF)|0x00A00000;
          NVIC_EN0_R = (1 << 30);
					EnableInterrupts();
        }
        break;
    default:
        break;
    }
		return GPIO_RET_OK;
}

void LED_ON(Gpio_pin_t pinNum){
	GPIO_PORTE_DATA_R = (1 << pinNum);
}
void LED_OFF(Gpio_pin_t pinNum){
	GPIO_PORTE_DATA_R = (0 << pinNum);
}


