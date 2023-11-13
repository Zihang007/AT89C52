#include <REGX52.H>
#include"LCD1602.h"
#include"Matrixkey.h"
#include<intrins.h>

void Delay1000ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 154;
	k = 122;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

unsigned char KeyNum;
unsigned long Key=0,i,j=3;
void main()
{
	LCD_init();
	LCD_disp_string(1,0,"password:");
	LCD_disp_number(2,0,0,4);
	while(1){
		while(Key<10000){
		KeyNum=Matrixkey();
			if(KeyNum){
			if(KeyNum<=10){
				i=KeyNum%10;
				Key=Key*10+i;
					if(Key>=10000)//判断是否是四位有效数字
						Key=0;
				 LCD_disp_number(2,0,Key,4);
			}
				else
			if(KeyNum==11){
				if(Key==8051){
					LCD_disp_string(1,12,"work");
					Delay1000ms();
					LCD_disp_string(1,12,"----");
					
				}
				else{
					LCD_disp_string(1,13,"err");
					Delay1000ms();
					LCD_disp_string(1,13,"---");
					j--;//判断输入错误次数
				}
				LCD_disp_number(2,0,0,4);
				Key=0;
			}
			if(j==0){
				 int s=5;
				do{
					LCD_disp_string(2,0,"TRY AGAIN IN ");
					LCD_disp_string(2,14,"s!");
					LCD_disp_number(2,13,s,1);
					s--;
					Delay1000ms();
				}while(s>0);
				LCD_disp_string(2,0,"                ");//清空液晶屏上显示的提示
				LCD_disp_number(2,0,0,4);
				j=3;
			}
			else
		if(KeyNum==12){
			LCD_disp_number(2,0,0,4);
			Key=0;
				}
		
			}
			}
		}
	}
