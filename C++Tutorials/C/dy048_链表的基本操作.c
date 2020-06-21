
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct Node {
	int data;
	struct Node* next;
} Node;


/// <summary>
/// ��������
/// </summary>
/// <returns></returns>
Node* SList_Create()
{
	//1 ���ϵĽ������� mallco�½ڵ�
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

	//2 �½ڵ���ջ��
	printf("\nplease enter you data:");
	scanf("%d", &data);

	pCurrent = pHead;

	while (data != -1)
	{
		//1 ����ҵ��ڵ� ����ʼ�� ���Ͻ������� mallco�½ڵ�
		pNew = (Node*)malloc(sizeof(Node));
		if (pHead == 0)
		{
			return NULL;
		}
		pNew->data = data;
		pNew->next = NULL;

		//2 �½ڵ� ������
		pCurrent->next = pNew;

		//3 �½ڵ��ɵ�ǰ�ڵ��
		pCurrent = pNew;

		//4 ���½ڵ�����
		printf("\nplease enter you data:");
		scanf("%d", &data);
	}
	return pHead;
}

/// <summary>
/// ��ӡ�б�
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
/// ����ڵ�
/// </summary>
/// <param name="node"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int SList_Insert(Node* node, int x, int y)
{
	Node* pHead, * pNode, * pCurrent;
	int data;

	//�����ǵ���ģ���ǰ�ڵ��λ�ñ�����ǰ���ڵ��next����


}

/// <summary>
/// ɾ������
/// </summary>
/// <param name="node"></param>
/// <param name="y"></param>
/// <returns></returns>
int SList_Delet(Node* node, int y)
{

}

/// <summary>
/// ��������
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
