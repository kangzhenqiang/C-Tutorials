#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include "linklist.h"

/*
	因为链表是单向的，3号位置报错2号位置的next域中

	1. 指针标列只想谁就把谁的地址赋给指针
	2. 分清楚链表的操作逻辑和辅助指针变量之间的关系
*/

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;

} TLinkList;


//创建线性链式列表
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

//销毁线性链式列表
void LinkList_Destory(LinkList* list) {

	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//清空线性链式列表
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

//获取线性链表长度
int LinkList_Length(LinkList* list) {
	TLinkList* ret = NULL;
	if (list == NULL)
	{
		return 0;
	}
	ret = (TLinkList*)list;
	return ret->length;
}

//插入线性链表节点
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
	current = &(tList->header);//让辅助指针变量指向链表头部

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	//1 让node连接后续链表
	node->next = current->next;

	//2 让前面链表链接新的节点node节点
	current->next = node;

	tList->length++;

	return ret;
}

//获取链表节点
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
	current = &(tList->header);//让辅助指针变量指向链表头部

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//删除线性链表节点
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
	current = &(tList->header);//让辅助指针变量指向链表头部

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	//删除缓存节点
	ret = current->next;

	//连线
	current->next = ret->next;

	//减少元素数量
	tList->length--;

	return ret;
}