#include <stdlib.h>
#include <stdio.h>

#include "linkstack.h"


/*
	线性表的顺序来模拟栈时，在尾部添加或删除元素，不会涉及到数组的元素大量移动，所以尾部好
	用线性表的链式存储来模拟栈的线性存储 

	怎么把栈的对象转换成栈的链式存储的对象

	用linklist 模拟linklist
*/


int main()
{
	LinkStack* stack = NULL;
	int a[10], i = 0;

	//创建链式存储栈
	stack = LinkStack_Create();
	if (stack==NULL)
	{
		return -1;
	}

	//往栈中压入对象
	for ( i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}

	//打印链式栈属性
	printf("stack len:%d\n", LinkStack_Size(stack));
	
	while (LinkStack_Size(stack)>0)
	{
		int temp = *((int*)LinkStack_Pop(stack));
		printf("temp:%d\n", temp);
	}

	//清空栈
	LinkStack_Clear(stack);

	//销毁栈
	LinkStack_Destory(stack);

	return 0;
}