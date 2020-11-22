// 栈的顺序存储设计与实现.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "seqstack.h"


/*
	栈是一种特殊的线性表
	栈只能在线性表的一端操作
	在cpp文件申明，在c文件中条用会出错1120

*/


int main()
{
	SeqStack* stack = NULL;
	int a[10] = {0}, i = 0;

	//创建一个栈
	stack = SeqStack_Create(10);

	if (stack == NULL)
	{
		return -1;
	}

	//压栈
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		SeqStack_Push(stack, &a[i]);
	}

	//获取栈容量
	printf("Capacity:%d\n", SeqStack_Capacity(stack));

	//获取栈存储对象数量
	printf("Length:%d\n", SeqStack_Size(stack));

	//获取最后入栈对象
	printf("top:%d\n", *((int*)SeqStack_Top(stack)));

	//移除栈对象
	while (SeqStack_Size(stack)>0)
	{
		int temp = *((int*)SeqStack_Pop(stack));
		printf("pop:%d\n", temp);
	}

	//销毁栈
	SeqStack_Destory(stack);

	/*
	//创建栈
	SeqStack* SeqStack_Create(int capacity);

	//销毁栈
	void SeqStack_Destory(SeqStack * stack);

	//清空栈
	void SeqStack_Clear(SeqStack * stack);

	//压入栈
	int SeqStack_Push(SeqStack * stack, void* item);

	//移除栈
	void* SeqStack_Pop(SeqStack * stack);

	//栈顶部
	void* SeqStack_Top(SeqStack * stack);

	//栈存储对象数量
	int SeqStack_Size(SeqStack * stack);

	//栈大小
	int SeqStack_Capacity(SeqStack * stack);

	*/

	printf("Hello World");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
