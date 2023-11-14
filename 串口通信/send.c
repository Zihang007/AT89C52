#include <REGX52.H>
#include<intrins.h>
#include"UART.H"
unsigned char sec=0;
void Delay1000ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void main(){
	Uart_Init();
	while(1){
		Uart_SendByte(sec);
		Delay1000ms();
		sec++;
	}
}

