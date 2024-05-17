#include "TExaS.h"
#include "Nokia5110.h"
#include "Random.h"
#include "Gpio.h"
#include "Gptm.h"
#include "..//tm4c123gh6pm11.h"
#include "GameArt.h"

// 2. Declarations Section
//   Function Prototypes
void Delay(void);
void Timer0A_Handler(void);
void EnableInterrupts(void);
void WaitForInterrupt(void);

void GPIOPortF_Handler(void){
	if(GPIO_PORTF_RIS_R & (1 << 4)){
		GPIO_PORTF_ICR_R = (1 << 4);      // acknowledge flag4
		right = 1;
		GPIO_PORTF_DATA_R = 0x02;
	}
	
	if(GPIO_PORTF_RIS_R & (1 << 0)){
		GPIO_PORTF_ICR_R = (1 << 0);      // acknowledge flag0
		enter = 1;
		GPIO_PORTF_DATA_R = 0x04;
	}	
}

void GPIOPortB_Handler(void){
	if(GPIO_PORTB_RIS_R & (1 << 0)){
		GPIO_PORTB_ICR_R = (1 << 0);      // acknowledge flag7
		down = 1;
		GPIO_PORTB_DATA_R = 0x06;
	}
}
int main(void){    
  TExaS_Init(SW_PIN_PF40,LED_PIN_PF321); 
  Nokia5110_Init();	
  Gpio_init(&portFCfg, GPIO_PORT_F);
  Gpio_init(&portBCfg, GPIO_PORT_B);
  while(1){
  }
}
