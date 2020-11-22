#include <stdlib.h>
#include <stdio.h>

#include "linkstack.h"


/*
	���Ա��˳����ģ��ջʱ����β����ӻ�ɾ��Ԫ�أ������漰�������Ԫ�ش����ƶ�������β����
	�����Ա����ʽ�洢��ģ��ջ�����Դ洢 

	��ô��ջ�Ķ���ת����ջ����ʽ�洢�Ķ���

	��linklist ģ��linklist
*/


int main()
{
	LinkStack* stack = NULL;
	int a[10], i = 0;

	//������ʽ�洢ջ
	stack = LinkStack_Create();
	if (stack==NULL)
	{
		return -1;
	}

	//��ջ��ѹ�����
	for ( i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}

	//��ӡ��ʽջ����
	printf("stack len:%d\n", LinkStack_Size(stack));
	
	while (LinkStack_Size(stack)>0)
	{
		int temp = *((int*)LinkStack_Pop(stack));
		printf("temp:%d\n", temp);
	}

	//���ջ
	LinkStack_Clear(stack);

	//����ջ
	LinkStack_Destory(stack);

	return 0;
}