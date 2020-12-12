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


//���������ʾ��
typedef struct TriTNode {
	int data;
	struct TriTNode* lChild, * rChild;
	struct TriTNode* parent;
} TriTNode, * TriTNode;


//����˫�ױ�ʾ��

#define MAX_TREE_SIZE 100;

typedef struct BPNode
{
	int data;
	int parentPoistion;//ָ��˫�׵�ָ�� //�����±�
	char LRTag;//���Һ��ӱ�־��
}BPNode;


typedef struct BPTree
{
	BPNode nodes[100];//��Ϊ�ڵ��Ƿ�ɢ�ģ���Ҫ�ѽڵ�洢��������
	int num_node;//�ڵ���Ŀ
	int root;//���ڵ��λ�� //ע�����洢���Ǹ��ڵ���������±�
} BPTree;

//�ӽڵ��б�����˫�׵�λ����Ϣ

//���ı���
/*
	DLR ������������ȸ���������
	LER ����������������ٸ�����
	LRD ��������������������ٸ�
	*/


int main01()
{
	BiTNode t1, t2, t3, t4, t5;
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

	//��������
	p1->lChild = p2;
	p1->rChild = p3;
	p2->lChild = p4;
	p3->lChild = p5;

	//���ı���

	return 0;
}

int main03()
{
	BPTree tree;

	//���ڵ�
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