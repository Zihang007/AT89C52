#include <REGX52.H>
#include"LCD1602.h"
#include"DS1302.h"
unsigned char Second,min,hour,day,month,year;
void main(){
	LCD_init();
	DS1302_Init();
	DS1302_SetTime();
	
	while(1){
		LCD_disp_char(1,2,'-');
		LCD_disp_char(1,5,'-');
		LCD_disp_char(2,2,':');
		LCD_disp_char(2,5,':');
		DS1302_ReadTime();
		
		LCD_disp_number(2,6,DS1302_Time[5],2);
		LCD_disp_number(2,0,DS1302_Time[3],2);
		LCD_disp_number(2,3,DS1302_Time[4],2);
		LCD_disp_number(1,0,DS1302_Time[0],2);
		LCD_disp_number(1,3,DS1302_Time[1],2);
		LCD_disp_number(1,6,DS1302_Time[2],2);
	}
	
}
