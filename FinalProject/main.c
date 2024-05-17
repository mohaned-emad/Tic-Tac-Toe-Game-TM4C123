// 1. Include Necessary headers
#include "TExaS.h"
#include "Nokia5110.h"
#include "Random.h"
#include "Gpio.h"
#include "Gptm.h"
#include "../DataSheets/tm4c123gh6pm11.h"
#include "GameArt.h"

// 2. Declarations Section
//   Function Prototypes
void Delay(void);
void Timer0A_Handler(void);
void EnableInterrupts(void);
void WaitForInterrupt(void);

// *************************** Capture image dimensions out of BMP**********
#define ow     		((unsigned char)O[18])
#define oh     		((unsigned char)O[22])
#define gridw     ((unsigned char)grid[18])
#define gridh     ((unsigned char)grid[22])

// global variables
unsigned long right, down , enter;
int i = 0, j = 0, x = 0 , y = 0, time = 0;
int currentTurn = 0;
char xo[3][3];


//   Function Prototypes
void display_cursor(int x, int y){
	// done
	Nokia5110_PrintBMP(y*28+3, (x+1)*14-1, cursor, 0);
	Nokia5110_DisplayBuffer();
}

void end_game(char ch)
{
	// done by outstring
	Nokia5110_Clear();
	if(currentTurn)
		Nokia5110_PrintBMP(0, gridh-1, xwon, 0);
	else
		Nokia5110_PrintBMP(0, gridh-1, owon, 0);
	Nokia5110_DisplayBuffer();
	Delay();
}
int draw(){
		for(i=0;i<3;++i)
			for(j=0;j<3;j++)
				if(xo[i][j]==' ') 
					return 0;
		return 1;
}
void end_game_draw()
{
		// done
	Nokia5110_Clear();
	Nokia5110_PrintBMP(0, gridh-1, drawbg, 0);
	Nokia5110_DisplayBuffer();
	Delay();
}
void xo_init(){
		// initializing the grid
		for(i=0;i<3;++i)
			for(j=0;j<3;j++)
				xo[i][j]=' ';
}
int check_winner(){
			
			// check horiziontal
			if(xo[0][0] == xo[0][1] && xo[0][2] == xo[0][1] && xo[0][0]!= ' ')
				return 1;
			if(xo[1][0] == xo[1][1] && xo[1][2] == xo[1][1] && xo[1][0]!= ' ')
				return 1;
			if(xo[2][0] == xo[2][1] && xo[2][2] == xo[2][1] && xo[2][0]!= ' ')
				return 1;
			// check vertical
			if(xo[2][0] == xo[1][0] && xo[1][0] == xo[0][0] && xo[2][0]!= ' ')
				return 1;
			if(xo[1][1] == xo[0][1] && xo[2][1] == xo[0][1] && xo[0][1]!= ' ')
				return 1;
			if(xo[2][2] == xo[1][2] && xo[0][2] == xo[1][2] && xo[1][2]!= ' ')
				return 1;
			// digonals
			if(xo[0][0]==xo[1][1]&&xo[2][2]==xo[0][0]&&xo[0][0]!=' ')
				return 1;
			if(xo[0][2]==xo[1][1]&&xo[2][0]==xo[0][2]&&xo[1][1]!=' ')
				return 1;
			return 0;
}

void printGrid(void){
	Nokia5110_ClearBuffer();
	Nokia5110_DisplayBuffer();      // draw buffer		
	Nokia5110_PrintBMP(0, gridh - 1, grid, 0);
	Nokia5110_DisplayBuffer();
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(xo[i][j]=='O')
				Nokia5110_PrintBMP(j*30+5, (i+1)*15-1, O, 0);
			else if(xo[i][j]=='X')
				Nokia5110_PrintBMP(j*30+5, (i+1)*15-1, X, 0);
			Nokia5110_DisplayBuffer();      
		}
	}
}

void GPIOPortF_Handler(void){
	if(GPIO_PORTF_RIS_R & (1 << 4)){
		GPIO_PORTF_ICR_R = (1 << 4);      // acknowledge flag for PF4
		right = 1;
		GPIO_PORTF_DATA_R = 0x02;
	}
	
	if(GPIO_PORTF_RIS_R & (1 << 0)){
		GPIO_PORTF_ICR_R = (1 << 0);      // acknowledge flag for PF0
		enter = 1;
		GPIO_PORTF_DATA_R = 0x04;
	}	
}

void GPIOPortB_Handler(void){
	if(GPIO_PORTB_RIS_R & (1 << 0)){
		GPIO_PORTB_ICR_R = (1 << 0);      // acknowledge flag for PB0
		down = 1;
		GPIO_PORTB_DATA_R = 0x06;
	}
}

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable

int main(void){    
  TExaS_Init(SW_PIN_PF40,LED_PIN_PF321); 
	Nokia5110_Init();	
	Gpio_init(&portFCfg, GPIO_PORT_F);
	Gpio_init(&portBCfg, GPIO_PORT_B);
	while(1){
		x=y=currentTurn=0;
		xo_init();
		Nokia5110_PrintBMP(0, gridh - 1, introbg, 0);
		Nokia5110_DisplayBuffer(); 
		Delay();
		printGrid();
		display_cursor(x,y);
		while(1){
			right = down = enter = 0;
			WaitForInterrupt();
			int edit = 0;
			if(right){
				++x;
				if(x == 3) x=0;
				edit=1;
			}
			if(down){
				++y;
				if(y == 3) y = 0;
				edit=1;
			}
			if(enter){
				edit=1;
				if(xo[x][y] == ' '){
					if(currentTurn)	
						xo[x][y]= 'X';
					else						
						xo[x][y]= 'O';
					if(check_winner()){
						end_game(xo[x][y]);
						break;
					}
					if(draw()){
						end_game_draw();
						break;
					}
					currentTurn ^= 1; // alternate the turn
				}
				else{
					// zamr nawr a3ml ally t7bo
			}			
		} 	
			if(edit){
			printGrid();
			display_cursor(x,y);
			}	
		}
	}
}


void Delay(void){
	time = 0;
	Gptm_Init(&Timer0_Config, GPTM_TIMER_0, 5);
	while(!time){
	}
}

void Timer0A_Handler(){
	TIMER0_ICR_R = 0x00000001;
	time = 1;
}
