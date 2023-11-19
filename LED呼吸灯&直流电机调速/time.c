#include <REGX52.H>


void Timer0_Init(void)		//10毫秒@12.000MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;		//使能定时器0中断
	EA=1;
	PT0=0;
}
