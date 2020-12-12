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
typedef struct TriTNode {
	int data;
	struct TriTNode* lChild, * rChild;
	struct TriTNode* parent;
} TriTNode, * TriTNode;


//树的双亲表示法

#define MAX_TREE_SIZE 100;

typedef struct BPNode
{
	int data;
	int parentPoistion;//指向双亲的指针 //数组下表
	char LRTag;//左右孩子标志域
}BPNode;


typedef struct BPTree
{
	BPNode nodes[100];//因为节点是分散的，需要把节点存储到数组中
	int num_node;//节点数目
	int root;//根节点的位置 //注意此域存储的是父节点在数组的下标
} BPTree;

//子节点中保存了双亲的位置信息

//树的遍历
/*
	DLR 先序遍历，即先根再左再右
	LER 中序遍历，即先左再根再右
	LRD 后序遍历，即先左再右再根
	*/


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

int main02()
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

int main03()
{
	BPTree tree;

	//根节点
	tree.nodes[0].parentPoistion = 1000;

	//B
	tree.nodes[1].parentPoistion = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;

	//C
	tree.nodes[2].parentPoistion = 0;
	tree.nodes[2].data = 'C';
	tree.nodes[2].LRTag = 2;


	return 0;
}