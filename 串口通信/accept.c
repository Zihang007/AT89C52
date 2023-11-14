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

void main(){
	Uart_Init();
	while(1){
		
	}
}
