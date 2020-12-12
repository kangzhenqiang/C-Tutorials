#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/// <summary>
/// 二叉表示法
/// </summary>
typedef struct BiTNode
{
	int data;
	struct BiTNode* lChild, * rChild;
};

typedef BiTNode BiTNode;

typedef BiTNode* BiTree;


//树的遍历
/*
	DLR 先序遍历，即先根再左再右
	LER 中序遍历，即先左再根再右
	LRD 后序遍历，即先左再右再根
	*/



void inOder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//遍历左子树
	inOder(root->lChild);

	printf("%d\n", root->data);

	//遍历右子树
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
	//求组子树高度
	deptLeft = Depth(root->lChild);
	//求右字数高度
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

	//建立管理
	t1.lChild = &t2;
	t1.rChild = &t3;
	t2.lChild = &t4;
	t3.lChild = &t5;

	//树的遍历
	 

	inOder(&t1);

	printf("\n");

	int dept= Depth(&t1);

	BiTNode* cpNode = Copy(&t1);

	inOder(cpNode);
	
	printf("dept:%d\n", dept);

	return 0;
}
