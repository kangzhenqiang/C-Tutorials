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


void preOrder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d\n", root->data);

	//����������
	preOrder(root->lChild);

	//����������
	preOrder(root->rChild);
}

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

void postOder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	postOder(root->lChild);

	//����������
	postOder(root->rChild);

	printf("%d\n", root->data);

}

int sum = 0;

void countLeaf(BiTNode* root)
{
	if (root != NULL)
	{
		if (root->lChild == NULL && root->rChild == NULL)
		{
			sum++;
		}
		if (root->lChild)
		{
			countLeaf(root->lChild);
		}
		if (root->rChild)
		{
			countLeaf(root->rChild);
		}
	}
}


void countLeaf(BiTNode* root,int * sum)
{
	if (root != NULL)
	{
		if (root->lChild == NULL && root->rChild == NULL)
		{
			(*sum)++;
		}
		if (root->lChild)
		{
			countLeaf(root->lChild, sum);
		}
		if (root->rChild)
		{
			countLeaf(root->rChild, sum);
		}
	}
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
	preOrder(&t1);

	inOder(&t1);

	postOder(&t1);

	countLeaf(&t1,&sum);

	printf("count leaf:%d\n", sum);

	return 0;
}
