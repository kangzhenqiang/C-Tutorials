#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "seqstack.h"
#include "seqlist.h"


//��������ջ �൱�ڴ�����������
SeqStack* SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//��������ջ �൱���������Ա�
void SeqStack_Destory(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

//�������ջ �൱��������Ա�
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}


//ѹ��ջ�����൱��β����������������
int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

//�Ƴ�ջ�������� �൱���Ƴ���������β��Ԫ��
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

//��ȡջ�������� �൱�ڻ�ȡ�����б�β��Ԫ��
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

//��ȡջԪ������ �൱�ڻ�ȡ���������Ԫ�ض�������
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

//��ȡջ������ �൱�ڻ�ȡ�������������
int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}
