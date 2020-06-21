
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct Node {
	int data;
	struct Node* next;
} Node;


/// <summary>
/// 创建链表
/// </summary>
/// <returns></returns>
Node* SList_Create()
{
	//1 不断的接收输入 mallco新节点
	Node* pHead = NULL;
	Node* pCurrent = NULL;
	Node* pNew = NULL;
	int data = 0;
	pHead = (Node*)malloc(sizeof(Node));
	if (pHead == 0)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2 新节点入栈表
	printf("\nplease enter you data:");
	scanf("%d", &data);

	pCurrent = pHead;

	while (data != -1)
	{
		//1 创建业务节点 并初始化 不断接收输入 mallco新节点
		pNew = (Node*)malloc(sizeof(Node));
		if (pHead == 0)
		{
			return NULL;
		}
		pNew->data = data;
		pNew->next = NULL;

		//2 新节点 入链表
		pCurrent->next = pNew;

		//3 新节点变成当前节点间
		pCurrent = pNew;

		//4 重新节点输入
		printf("\nplease enter you data:");
		scanf("%d", &data);
	}
	return pHead;
}

/// <summary>
/// 打印列表
/// </summary>
/// <param name="node"></param>
int SList_Print(Node* node)
{
	if (node==NULL)
	{
		return 0;
	}
	Node* pTemp = NULL;
	pTemp = node->next;

	printf("Begin print ...\n");

	while (pTemp!=NULL)
	{
		printf("Node value:%d\n", pTemp->data);
		pTemp = pTemp->next;
	}
	printf("End print ...\n");
}

/// <summary>
/// 插入节点
/// </summary>
/// <param name="node"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int SList_Insert(Node* node, int x, int y)
{
	Node* pHead, * pNode, * pCurrent;
	int data;

	//链表是单向的，当前节点的位置保存在前驱节点的next域中


}

/// <summary>
/// 删除链表
/// </summary>
/// <param name="node"></param>
/// <param name="y"></param>
/// <returns></returns>
int SList_Delet(Node* node, int y)
{

}

/// <summary>
/// 销毁链表
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
int SList_Destory(Node* node)
{

}

void main()
{
	Node* pHead = NULL;
	int ret = 0;
	pHead = SList_Create();
	ret = SList_Print(pHead);
	ret = SList_Insert(pHead, 20, 19);
	ret = SList_Delet(pHead, 20);
	ret = SList_Destory(pHead);
	system("pause");
}
