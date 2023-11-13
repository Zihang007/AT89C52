#include <REGX52.H>
#include "LCD1602.h"
void Delay20ms(void)	//@12.000MHz
{
	unsigned char data i, j;

	i = 234;
	j = 115;
	do
	{
		while (--j);
	} while (--i);
}

	unsigned char second=0,min=0,hour=0;
	void Timer0_Init(void)		//1??@12.000MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0xF4;				//设置定时初始值
	TH0 = 0xFF;			//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;						//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}
	static unsigned int T0_count=0;
void Time0_Routine () interrupt 1
{
	TL0 = 0x20;				//???????
	TH0 = 0xD1;	
	T0_count++;
	}
void main(){
	LCD_init();
	Timer0_Init();
	while(1){
		while(T0_count>=1000){
			T0_count=0;
			if(second<59){
				second++;
			}
			else{
				second=0;
				min++;
				if(min>59){
					min=0;
					hour++;
					if(hour==23)
						hour=0;
				}
			}
			LCD_disp_number(2,0,hour,2);
			LCD_disp_number(2,3,min,2);
			LCD_disp_number(2,6,second,2);
			LCD_disp_string(1,0,"time:");
			LCD_disp_char(2,2,':');
			LCD_disp_char(2,5,':');
		}
		if(P3_1==0){
			Delay20ms;
		while(P3_1==0);
		Delay20ms();
		min=0;
		second=0;
		hour=0;
		}
}
}
	
