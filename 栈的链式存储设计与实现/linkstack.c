#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkstack.h"
#include "linklist.h"


typedef struct TLinkStackNode//����ҵ��ڵ�
{
	LinkListNode node;//��һ���򣨵�һ��Ԫ�أ�
	void* item;//ջ��ҵ��ڵ�
} TLinkStackNode;


LinkStack* LinkStack_Create()
{
	return LinktList_Create();
}

void LinkStack_Destory(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
}

//���ջ��ʱ���漰��ջԪ���������ڹ���,������ջ�Ľڵ㶼��malloc
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	while (LinkStack_Size(stack))
	{
		LinkStack_Pop(stack);
	}
	LinkList_Clear(stack);
}

//��ջ�����Ԫ�أ��൱���������б�ͷ����Ӷ���
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* temp = NULL;
	int ret = 0;
	temp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (temp == NULL)
	{
		return -1;
	}
	memset(temp, 0, sizeof(TLinkStackNode));

	temp->item = item;

	ret = LinkList_Insert(stack, (LinkListNode*)temp, 0);
	if (ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", -2);
		if (temp != NULL)
		{
			free(temp);
			temp = NULL;
		}
		return-2;
	}
	return ret;
}

//��ջ�����Ƴ��أ��൱�ڴ������б�ͷ���Ƴ�����
void* LinkStack_Pop(LinkStack* stack)
{
	void* ret = NULL;
	TLinkStackNode* temp = NULL;
	temp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (temp == NULL)
	{
		return NULL;
	}
	ret = temp->item;

	//��ΪLinkList_Insert��ʱ�� �������ڴ棬����LinkList_Delete�ͷ��ڴ�
	free(temp);
	temp = NULL;

	return ret;
}

void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode* temp = NULL;
	temp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (temp == NULL)
	{
		return NULL;
	}

	return temp->item;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}
