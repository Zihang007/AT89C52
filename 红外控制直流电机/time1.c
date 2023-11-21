#include <REGX52.H>


void Timer1_Init(void)		//10毫秒@12.000MHz
{
	TMOD &= 0x0F;	//设置定时器模式
	TMOD |= 0x10;	
	TL1 = 0x9C;				//设置定时初始值
	TH1 = 0xFF;				//设置定时初始值
	TF1 = 0;				//清除TF0标志
	TR1 = 1;				//定时器0开始计时
	ET1 = 1;		//使能定时器0中断
	EA=1;
	PT1=0;
}
