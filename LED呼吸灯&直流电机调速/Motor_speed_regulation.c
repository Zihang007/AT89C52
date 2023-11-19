#include <REGX52.H>
#include"Delay.h"
#include"time.h"
unsigned char t,count,compare;
unsigned char Num[]={0x3F,0x06,0x5B,0x4F, 0x86,0xcf,0x7D,0x87,0x7F,0x6F,0x7f};
void fun(unsigned char location,num){
	switch(location){
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}	
	P0=Num[num];
	Delay(1);
	P0=0x00;

}
void main(){
	Timer0_Init();
	while(1)
	{
		fun(1,t);
		if(P3_1==0){
			Delay(20);
		  while(P3_1==0);
			Delay(20);
			t++;
			t%=4;
		}
		if(t==1)
			compare=40;
		else if(t==2)
			compare=60;
		else if(t==3)
			compare=80;
		else if(t==0)
			compare=0;
	}
}
void Timer0_Isr(void) interrupt 1
{
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;;	
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
