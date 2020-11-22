#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "seqstack.h"
#include "seqlist.h"


//创建线性栈 相当于创建线性链表
SeqStack* SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//销毁线性栈 相当于销毁线性表
void SeqStack_Destory(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

//清空线性栈 相当于清空线性表
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}


//压入栈对象，相当于尾部添加线性链表对象
int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

//移除栈顶部对象 相当于移除线性链表尾部元素
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

//获取栈顶部对象 相当于获取线性列表尾部元素
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

//获取栈元素数量 相当于获取线性链表的元素对象数量
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

//获取栈的容量 相当于获取线性链表的容量
int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}
