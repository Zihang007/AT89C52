//显示动画；
#include <REGX52.H>
#include"Matrix.h"

unsigned char Animation[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0x49,0x49,0x26,0x00,0x7f,0x08,0x08,0x7f,0x00,0x3f,0x48,0x48,0x3f,0x00,0x7f,0x20,0x10,0x20,0x7f,0x00,0x7f,0x49,
0x49,0x00,0x7f,0x01,0x01,0x00,0x7f,0x49,0x49,0x00,0x32,0x49,0x49,0x26,0x00,0x32,0x49,0x49,0x26,0x00,0x04,0x1e,0x7e,0x1e,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void main(){
	unsigned int i,j,count=0;
	MatrixLED_Init();
	while(1){
		for(i=0;i<8;i++){
			MatrixLED_ShowColumn(i,0x00);
			MatrixLED_ShowColumn(i,Animation[i+j]);
			}
		count++;
			if(count>10){
				count=0;
				j++;
				if(j>56){
					j=0;
				}
			}
	}
}
//此函数延迟不能运用Delay，因为运动是一个持续的过程；
//可以运用定时器；
