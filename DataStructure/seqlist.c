#include <stdint.h>
#include "seqlist.h"


//�ڽṹ����һ��ָ��
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int* node;

} TSeqList;



//���������б�
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

	//����capacity�Ĵ�С����ڵ�Ŀռ�
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

//���������б�
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

//��������б�
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

//��ȡ�����б���
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


//��ȡ�����б��ٿռ䳤��
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

//�����Ա��в���һ����Ԫ��
int SeqList_Insert(TSeqList* list, SeqListNode* node, int pos)
{
	return 0;
}

//��ȡ���Ա���posλ�ó���Ԫ��
SeqListNode* SeqList_Get(TSeqList* list, int post)
{

	return NULL;
}

//ɾ��һ�����Ա�λ�ó���Ԫ�أ�����ֵΪɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
SeqListNode* SeqList_Delete(TSeqList* list, int post)
{

	return NULL;
}