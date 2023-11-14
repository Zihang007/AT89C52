#include <REGX52.H>
#include"UART.h"

void UART_Routine () interrupt 4
{
	if(RI==1){
		P2=~SBUF;
		RI=0;
		Uart_SendByte(SBUF);
	}
}

/*void UART_Routine () interrupt 4
{
	if(RI==1){
 
		RI=0;
	}
}*/
//这是一个中断模块；

void main(){
	Uart_Init();
	while(1){
		
	}
}
//在单片机接受由串口发来的信号时，记得要修改自定义函数“Uart_init”中的scon,使其允许串行接受控制位；
//并且要在函数中加上 “EA=1;“ ”ES=1; “ 使其串口的中断打开；
