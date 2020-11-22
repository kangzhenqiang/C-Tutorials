#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkstack.h"
#include "linklist.h"


typedef struct TLinkStackNode//链表业务节点
{
	LinkListNode node;//第一个域（第一个元素）
	void* item;//栈的业务节点
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

//清空栈的时候涉及到栈元素生命周期管理,所有入栈的节点都是malloc
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

//往栈中添加元素，相当于往线性列表头部添加对象
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

//往栈中添移除素，相当于从线性列表头部移除对象
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

	//因为LinkList_Insert的时候 分配了内存，所以LinkList_Delete释放内存
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
