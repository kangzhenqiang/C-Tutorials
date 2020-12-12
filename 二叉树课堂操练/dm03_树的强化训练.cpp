#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/// <summary>
/// �����ʾ��
/// </summary>
typedef struct BiTNode
{
	int data;
	struct BiTNode* lChild, * rChild;
};

typedef BiTNode BiTNode;

typedef BiTNode* BiTree;


//���ı���
/*
	DLR ������������ȸ���������
	LER ����������������ٸ�����
	LRD ��������������������ٸ�
	*/



void inOder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//����������
	inOder(root->lChild);

	printf("%d\n", root->data);

	//����������
	inOder(root->rChild);
}

int Depth(BiTNode *root)
{
	int deptLeft = 0;
	int deptRight = 0;
	int deptav = 0;
	if (root==NULL)
	{
		return 0;
	}
	//���������߶�
	deptLeft = Depth(root->lChild);
	//���������߶�
	deptRight = Depth(root->rChild);

	deptav = 1 + (deptLeft > deptRight ? deptLeft : deptRight);
	return deptav;
}


BiTNode* Copy(BiTNode* root)
{
	BiTNode* newNode = NULL;
	BiTNode* newLeftNode = NULL;
	BiTNode* newRightNode = NULL;

	if (root==NULL)
	{
		return NULL;
	}
	if (root->lChild!=NULL)
	{
		newLeftNode = Copy(root->lChild);
	}
	if (root->rChild!=NULL)
	{
		newRightNode = Copy(root->rChild);
	}

	newNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (newNode==NULL)
	{
		return newNode;
	}

	newNode->lChild = newLeftNode;
	newNode->rChild = newRightNode;
	newNode->data = root->data;

	return newNode;
}


int main()
{
	BiTNode t1, t2, t3, t4, t5;

	memset(&t1, 0, sizeof(t1));
	memset(&t2, 0, sizeof(t2));
	memset(&t3, 0, sizeof(t3));
	memset(&t4, 0, sizeof(t4));
	memset(&t5, 0, sizeof(t5));

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//��������
	t1.lChild = &t2;
	t1.rChild = &t3;
	t2.lChild = &t4;
	t3.lChild = &t5;

	//���ı���
	 

	inOder(&t1);

	printf("\n");

	int dept= Depth(&t1);

	BiTNode* cpNode = Copy(&t1);

	inOder(cpNode);
	
	printf("dept:%d\n", dept);

	return 0;
}
