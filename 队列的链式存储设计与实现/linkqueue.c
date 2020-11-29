#include "linkqueue.h"
#include "linklist.h"

//����Ҳ��һ���������Ա�

//���е�ҵ��ڵ�����ݽṹ

typedef struct _tag_LinkQueueNode {
	LinkListNode node;
	void* item;
} TLinkQueueNode;

//���������൱�ڴ������Ա�
LinkQueue* LinkQueue_Create()
{
	return LinktList_Create();
}

//ɾ�������൱���������Ա����ǽڵ��ڴ�
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destory(queue);
}

//��� ����
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue)>0)
	{
		LinkQueue_Retrieve(queue);
	}
}

//����������Ԫ�� �൱�� �����Ա�β�����Ԫ��
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	TLinkQueueNode* tmp = NULL;
	tmp = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	if (tmp==NULL)
	{
		printf("func LINKQueue_Append() mallco err:%d\n", -1);
		return -1;
	}

	memset(tmp, 0, sizeof(TLinkQueueNode));//��һ�������˵���
	tmp->item = item;

	//��Ҫ�Ѷ��е�itemת��Ϊ�����Ա��ҵ��ڵ㣩
	return LinkList_Insert(queue, (LinkListNode*)tmp, LinkQueue_Length(queue));;
}

//�Ƴ����еĶ����൱�� �Ƴ����Ա�ͷ��Ԫ��
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

//��ȡ���е�ͷ��Ԫ�� �൱�ڻ�ȡ���Ա��ͷ��Ԫ��
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

//��ȡ���еĳ����൱�ڻ�ȡ���Ա�ĳ���
int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}
