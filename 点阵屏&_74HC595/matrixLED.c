//点阵屏上初步显示，显示固定图形；
#include <REGX52.H>

sbit RCK=P3^5;     //RCLK
sbit SCK=P3^6;     //SLK
sbit SER=P3^4;     //SER

void _74HC595_WriteByte(unsigned char Byte){
	unsigned char i;
	for(i=0;i<8;i++){
	SER=	Byte&(0x80>>i);
	SCK=1;
	SCK=0;
	}
	RCK=1;
	RCK=0;
}

void MatrixLED_ShowColumn(unsigned char Column,Data){
	_74HC595_WriteByte(Data);
	P0=~(0x08>>Column);
}

void main(){
	while(1){
		SCK=0;
	RCK=0;
	MatrixLED_ShowColumn(3,0xaa);//根据自身需求自行补充；
	}
}
