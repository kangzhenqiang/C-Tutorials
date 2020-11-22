#include <stdint.h>
#include "seqlist.h"


//在结构体套一级指针
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int* node;

} TSeqList;



//创建线性列表
TSeqList* SeqList_Create(int capacty)
{
	int err = 0;
	TSeqList* temp;
	temp = (TSeqList*)malloc(sizeof(TSeqList));
	if (temp == NULL)
	{
		err = 1;
		printf("fun SeqList_Create() err:%d\n", err);
		return NULL;
	}

	//根据capacity的大小分配节点的空间
	temp->node = (unsigned int*)malloc(sizeof(unsigned int*) * capacty);
	if (temp->node == NULL)
	{
		err = 2;
		printf("fun SeqList_Create() err:%d\n", err);
		return NULL;
	}
	temp->length = 0;
	temp->capacity = capacty;

	return temp;
}

//销毁线性列表
void SeqList_Destroy(TSeqList* list)
{
	int ret = 0;
	TSeqList* temp = NULL;
	if (list==NULL)
	{
		ret = -1;
		return;
	}

	temp = (TSeqList*)list;
	if (temp->node!=NULL)
	{
		free(temp->node);
	}

	free(temp);
}

//清空线性列表
void SeqList_Clear(TSeqList* list)
{
	TSeqList* temp = NULL;
	if (list == NULL)
	{
		return;
	}
	temp = (TSeqList*)list;
	temp->length = 0;
	return;
}

//获取线性列表长度
int SeqList_Length(TSeqList* list)
{
	TSeqList* temp = NULL;
	if (list == NULL)
	{
		return -1;
	}
	temp = (TSeqList*)list;

	return temp->length;
}


//获取线性列表开辟空间长度
int SeqList_Capacity(TSeqList* list)
{
	TSeqList* temp = NULL;
	if (list == NULL)
	{
		return -1;
	}
	temp = (TSeqList*)list;

	return temp->capacity;
}

//向线性表中插入一个新元素
int SeqList_Insert(TSeqList* list, SeqListNode* node, int pos)
{
	return 0;
}

//获取线性表在pos位置出的元素
SeqListNode* SeqList_Get(TSeqList* list, int post)
{

	return NULL;
}

//删除一个线性表位置出的元素，返回值为删除的元素，NULL表示删除失败
SeqListNode* SeqList_Delete(TSeqList* list, int post)
{

	return NULL;
}