#include <REGX52.H>
void Delay(unsigned char t){
	while(t--);
}
void main(){
	while(1){
		unsigned char Time,i;
		for(Time=0;Time<100;Time++){
			for(i=0;i<20;i++){
				P2_0=0;
				Delay(Time);
				P2_0=1;
				Delay(100-Time);
			}
	}
				for(Time=0;Time<100;Time++){
			for(i=0;i<20;i++){
				P2_0=1;
				Delay(Time);
				P2_0=0;
				Delay(100-Time);
			}
	}
}
}
//更高级的单片机都会有硬件的PWM，由于STC89C52没有这个功能，所以采用定时器中断来实现这个功能；
