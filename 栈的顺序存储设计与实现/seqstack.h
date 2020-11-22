#pragma once

#ifndef _MY_SEQSTACH_H

#define _MY_SEQSTACH_H


typedef void SeqStack;

//创建栈
SeqStack* SeqStack_Create(int capacity);

//销毁栈
void SeqStack_Destory(SeqStack* stack);

//清空栈
void SeqStack_Clear(SeqStack* stack);

//压入栈
int SeqStack_Push(SeqStack* stack, void* item);

//移除栈
void* SeqStack_Pop(SeqStack* stack);

//栈顶部
void* SeqStack_Top(SeqStack* stack);

//栈存储对象数量
int SeqStack_Size(SeqStack* stack);

//栈大小
int SeqStack_Capacity(SeqStack* stack);


#endif // _MY_SEQSTACH_H

