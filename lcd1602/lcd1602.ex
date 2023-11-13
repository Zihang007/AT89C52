#include <REGX52.H>
#include<lcd1602.h>
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

int i=9;
void main(){
	Lcd_init();
	LCD_disp_string(1,0,"C4 will explode in ");
	LCD_disp_string(2,5,"seconds!");
		do{
	LCD_disp_number(2,3,i,1);
	i--;
			Delay1000ms();
		}
			while(i>0);
			if(i==0){
			LCD_clear();
			while(1)
			LCD_disp_string(1,0,"you're dead!");
			}
		while(1);
}
