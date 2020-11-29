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


//����������ʽ�б�
LinkList* LinktList_Create();

//����������ʽ�б�
void LinkList_Destory(LinkList* list);

//���������ʽ�б�
void LinkList_Clear(LinkList* list);

//��ȡ����������
int LinkList_Length(LinkList* list);

//������������ڵ�
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//��ȡ�ڵ�
LinkListNode* LinkList_Get(LinkList* list, int pos);

//ɾ����������ڵ�
LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif // 


