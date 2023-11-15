//点阵屏上初步显示，显示固定图形；
#include <REGX52.H>
#include"MatrixLED.h"

void main(){
	MatrixLED_Init();
	while(1){
	MatrixLED_ShowColumn(3,0xaa);//根据自身需求自行补充；
	}
}
