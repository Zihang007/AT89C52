#include <REGX52.H>
#include"time1.h"
unsigned char count,compare;

void Motor_Init(){
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char Speed){
	
compare=Speed;
}
void Timer1_Isr(void) interrupt 3
{
	TL1 = 0x9C;				//设置定时初始值
	TH1 = 0xFF;;	
	count++;
	count%=100;
	if(compare>count){
		P1_0=1;
		P2_0=0;
	}
	else{
		P1_0=0;
		P2_0=1;
	}
}
