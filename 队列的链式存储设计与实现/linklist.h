#pragma once

#ifndef _MYLINKLIST_H_
#define _MYLINKLIST_H_

typedef void LinkList;

//
//typedef struct _tag_LinkListNode LinkListNode;
//
//struct _tag_LinkListNode
//{
//	LinkListNode* next;
//};

typedef struct _tag_LinkListNode {

	struct _tag_LinkListNode* next;

} LinkListNode;


//创建线性链式列表
LinkList* LinktList_Create();

//销毁线性链式列表
void LinkList_Destory(LinkList* list);

//清空线性链式列表
void LinkList_Clear(LinkList* list);

//获取线性链表长度
int LinkList_Length(LinkList* list);

//插入线性链表节点
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//获取节点
LinkListNode* LinkList_Get(LinkList* list, int pos);

//删除线性链表节点
LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif // 


