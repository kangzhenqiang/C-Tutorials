#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include "linklist.h"

/*
	��Ϊ�����ǵ���ģ�3��λ�ñ���2��λ�õ�next����

	1. ָ�����ֻ��˭�Ͱ�˭�ĵ�ַ����ָ��
	2. ���������Ĳ����߼��͸���ָ�����֮��Ĺ�ϵ
*/

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;

} TLinkList;


//����������ʽ�б�
LinkList* LinktList_Create() {

	TLinkList* ret = NULL;
	ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret == NULL)
	{
		return NULL;
	}
	memset(ret, 0, sizeof(TLinkList));
	ret->length = 0;
	ret->header.next = NULL;

	return ret;
}

//����������ʽ�б�
void LinkList_Destory(LinkList* list) {

	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//���������ʽ�б�
void LinkList_Clear(LinkList* list) {

	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return;
	}
	tList = (TLinkList*)list;
	tList->length = 0;
	tList->header.next = NULL;
	return;
}

//��ȡ����������
int LinkList_Length(LinkList* list) {
	TLinkList* ret = NULL;
	if (list == NULL)
	{
		return 0;
	}
	ret = (TLinkList*)list;
	return ret->length;
}

//������������ڵ�
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) {

	int ret = 0;
	LinkListNode* current = NULL;
	TLinkList* tList = NULL;

	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("fun LinkList_Insert() err:%d\n", ret);
		return ret;
	}

	tList = (TLinkList*)list;
	if (tList == NULL)
	{
		ret = -2;
		printf("fun LinkList_Insert() err:%d\n", ret);
		return ret;
	}
	current = &(tList->header);//�ø���ָ�����ָ������ͷ��

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	//1 ��node���Ӻ�������
	node->next = current->next;

	//2 ��ǰ�����������µĽڵ�node�ڵ�
	current->next = node;

	tList->length++;

	return ret;
}

//��ȡ����ڵ�
LinkListNode* LinkList_Get(LinkList* list, int pos) {
	int ret = 0;
	LinkListNode* current = NULL;
	TLinkList* tList = NULL;

	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("fun LinkList_Get() err:%d\n", ret);
		return current;
	}

	tList = (TLinkList*)list;
	if (tList == NULL)
	{
		ret = -2;
		printf("fun LinkList_Get() err:%d\n", ret);
		return current;
	}
	current = &(tList->header);//�ø���ָ�����ָ������ͷ��

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//ɾ����������ڵ�
LinkListNode* LinkList_Delete(LinkList* list, int pos) {

	LinkListNode* ret = 0;
	LinkListNode* current = NULL;
	TLinkList* tList = NULL;

	if (list == NULL || pos < 0)
	{
		printf("fun LinkList_Delete() err:%d\n", -1);
		return current;
	}

	tList = (TLinkList*)list;
	if (tList == NULL)
	{
		printf("fun LinkList_Delete() err:%d\n", -2);
		return NULL;
	}
	current = &(tList->header);//�ø���ָ�����ָ������ͷ��

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	//ɾ������ڵ�
	ret = current->next;

	//����
	current->next = ret->next;

	//����Ԫ������
	tList->length--;

	return ret;
}