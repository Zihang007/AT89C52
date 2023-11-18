#include <REGX52.H>
#include"Delay.h"
sbit Buzzer = P2^5;
void Buzzer_Time(unsigned int ms){
	 unsigned char i, KeyNum;
            if (P3_1 == 0) {
                Delay(20);
                while (P3_1 == 0);
                Delay(20);
                KeyNum = 1;
                P2 = 0;
            }
        if (KeyNum) {
            for (i = 0; i < ms; i++) {
                Buzzer = !Buzzer;
                Delay(1);
            }
						KeyNum=0;
        }
}
