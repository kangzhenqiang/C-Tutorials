#pragma once

#ifndef _MY_SEQSTACH_H

#define _MY_SEQSTACH_H


typedef void SeqStack;

//����ջ
SeqStack* SeqStack_Create(int capacity);

//����ջ
void SeqStack_Destory(SeqStack* stack);

//���ջ
void SeqStack_Clear(SeqStack* stack);

//ѹ��ջ
int SeqStack_Push(SeqStack* stack, void* item);

//�Ƴ�ջ
void* SeqStack_Pop(SeqStack* stack);

//ջ����
void* SeqStack_Top(SeqStack* stack);

//ջ�洢��������
int SeqStack_Size(SeqStack* stack);

//ջ��С
int SeqStack_Capacity(SeqStack* stack);


#endif // _MY_SEQSTACH_H

