#include <REGX52.H>
#include"Delay.h"
#include"Motor.h"
#include"IR.h"
unsigned char t,Command;
unsigned char Num[]={0x3F,0x06,0x5B,0x4F, 0x86,0xcf,0x7D,0x87,0x7F,0x6F,0x7f};
void fun(unsigned char location,num){
	switch(location){
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}	
	P0=Num[num];
	Delay(1);
	P0=0x00;

}
void main(){
	Motor_Init();
	IR_Init();
	fun(1,t);
	while(1)
	{
		fun(1,t);
		if(P3_1==0){
			Delay(1);
		  while(P3_1==0);
			Delay(1);
			t++;
			t%=4;
				if(t==1)
			Motor_SetSpeed(40);
		else if(t==2)
			Motor_SetSpeed(70);
		else if(t==3)
			Motor_SetSpeed(100);
		else if(t==0)
			Motor_SetSpeed(0);
		}
		if(IR_GetDataFlag())
		{
			Command=IR_GetCommand();
			if(Command==IR_0)
				t=0;
			if(Command==IR_1)
				t=1;
			if(Command==IR_2)
				t=2;
			if(Command==IR_3)
				t=3;
		if(t==1)
			Motor_SetSpeed(40);
		else if(t==2)
			Motor_SetSpeed(70);
		else if(t==3)
			Motor_SetSpeed(100);
		else if(t==0)
			Motor_SetSpeed(0);
	}
		fun(1,t);
}
	}
