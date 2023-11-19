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
