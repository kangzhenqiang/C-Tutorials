#include "linkqueue.h"
#include "linklist.h"

//队列也是一种特殊线性表

//队列的业务节点的数据结构

typedef struct _tag_LinkQueueNode {
	LinkListNode node;
	void* item;
} TLinkQueueNode;

//创建队列相当于创建线性表
LinkQueue* LinkQueue_Create()
{
	return LinktList_Create();
}

//删除队列相当于销毁线性表，考虑节点内存
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destory(queue);
}

//清空 对象
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue)>0)
	{
		LinkQueue_Retrieve(queue);
	}
}

//向队列中添加元素 相当于 向线性表尾部添加元素
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	TLinkQueueNode* tmp = NULL;
	tmp = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	if (tmp==NULL)
	{
		printf("func LINKQueue_Append() mallco err:%d\n", -1);
		return -1;
	}

	memset(tmp, 0, sizeof(TLinkQueueNode));//做一个负责人的人
	tmp->item = item;

	//需要把队列的item转换为（线性表的业务节点）
	return LinkList_Insert(queue, (LinkListNode*)tmp, LinkQueue_Length(queue));;
}

//移除队列的对象相当于 移除线性表头部元素
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	void* ret = NULL;

	TLinkQueueNode* temp = NULL;

	temp= (TLinkQueueNode*)LinkList_Delete(queue, 0);

	if (temp==NULL)
	{
		printf("LinkList_Delete fun err:d%\n", -1);
		return NULL;
	}

	ret = temp->item;
	if (temp!=NULL)
	{
		free(temp);
		temp = NULL;
	}

	return ret;
}

//获取队列的头部元素 相当于获取线性表的头部元素
void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueueNode* temp = NULL;
	void* ret = NULL;
	temp = (TLinkQueueNode*)LinkList_Get(queue, 0);
	if (temp==NULL)
	{
		printf("func LinkList_Get() err:%d\n", -1);
		return ret;
	}
	ret = temp->item;
	return ret;
}

//获取队列的长度相当于获取线性表的长度
int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}
