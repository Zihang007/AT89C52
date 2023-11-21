#ifndef __IR_H__
#define __IR_H__

#define IR_1 0x0c
#define IR_2 0x18
#define IR_3 0x5e
#define IR_0 0x16

void IR_Init();
unsigned char IR_GetDataFlag();
unsigned char IR_GetRepeatFlag();
unsigned char IR_GetAddress();
unsigned char IR_GetCommand();

#endif
