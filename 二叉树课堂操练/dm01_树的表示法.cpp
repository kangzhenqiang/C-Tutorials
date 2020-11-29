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


//树的三叉表示法


//树的双亲表示法




int main01()
{
	BiTNode t1, t2, t3, t4, t5;
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

	return 0;
}

int main()
{
	BiTNode* p1, * p2, * p3, * p4, * p5;
	p1 = (BiTNode*)malloc(sizeof(BiTNode));
	p2 = (BiTNode*)malloc(sizeof(BiTNode));
	p3 = (BiTNode*)malloc(sizeof(BiTNode));
	p4 = (BiTNode*)malloc(sizeof(BiTNode));
	p5 = (BiTNode*)malloc(sizeof(BiTNode));

	p1->data = 1;
	p2->data = 1;
	p3->data = 1;
	p4->data = 1;
	p5->data = 1;

	//建立管理
	p1->lChild = p2;
	p1->rChild = p3;
	p2->lChild = p4;
	p3->lChild = p5;

	//树的遍历

	return 0;
}