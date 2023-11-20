#include <REGX52.H>
#include"LCD1602.h"
#include"Delay.h"
#include"XPT2046.h"
unsigned int ADValue;
void main (){
	LCD_Init();
	LCD_disp_string(1,0,"ADJ NTC RG");
	while(1)
	{
		ADValue=XPT2046_ReadAD(XPT2046_XP_8);
		LCD_disp_number(2,0,ADValue,3);
		Delay(10);
		ADValue=XPT2046_ReadAD(XPT2046_YP_8);
		LCD_disp_number(2,4,ADValue,3);
		Delay(10);
		ADValue=XPT2046_ReadAD(XPT2046_VBAT_8);
		LCD_disp_number(2,8,ADValue,3);
		Delay(10);
		
	}


}
