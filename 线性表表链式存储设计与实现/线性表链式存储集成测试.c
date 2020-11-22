#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include "linklist.h"


typedef struct Teacher {
	LinkListNode node;//第一个域 （第一个元素） 专门被业务节点包含
	int age;
	char name[64];
} Teacher;


void main()
{
	/*
		//创建线性链式列表
		LinkList* LinktList_Create();

		//销毁线性链式列表
		void LinkList_Destory(LinkList* list);

		//清空线性链式列表
		void LinkList_Clear(LinkList* list);

		//获取线性链表长度
		void LinkList_Length(LinkList* list);

		//插入线性链表节点
		void LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
		LinkListNode* LinkList_Get(LinkList* list, int pos);

		//删除线性链表节点
		LinkListNode* LinkList_Delete(LinkList* list, int pos);
	*/

	LinkList* list;
	int length = 0, ret = 0;

	Teacher t1, t2;
	t1.age = 32;
	strcpy(t1.name, "kangzhenqiang");

	t2.age = 32;
	strcpy(t2.name, "wangjing");


	list = LinktList_Create();
	if (list == NULL)
	{
		ret = -1;
		printf("fun LinktList_Create() err: %d\n", ret);
		return;
	}

	length = LinkList_Length(list);

	LinkList_Insert(list, (LinkListNode*)(&t1), 0);
	LinkList_Insert(list, (LinkListNode*)(&t2), 0);

	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher* temp = (Teacher*)LinkList_Get(list, i);
		if (temp == NULL)
		{
			ret = -2;
			printf("fun LinkList_Get() err: %d\n", ret);
			return;
		}
		printf("temp->age:%d\n", temp->age);
	}

	while (LinkList_Length(list)>0)
	{
		Teacher* temp = (Teacher*)LinkList_Delete(list, 0);
		if (temp == NULL)
		{
			ret = -3;
			printf("fun LinkList_Delete() err: %d\n", ret);
			return;
		}
		printf("temp->age:%d\n", temp->age);
	}

	LinkList_Destory(list);

	system("pause");
	return;
}