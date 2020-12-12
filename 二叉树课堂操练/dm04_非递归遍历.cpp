#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

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
	����1��
		����ڵ������������ý����ջ��
		������û�������������ʸýڵ㣻
	����2��
		����ڵ������������ظ�����1��
		����ڵ�û������������������ϣ�������ջ��ָʾ���ˣ�����ջ��Ԫ�أ����������������ظ�����1
		���ջΪ�գ���ʾ��������
	
	*/


/// <summary>
/// һֱ�����ߣ��ҵ��������
/// </summary>
/// <param name="T"></param>
/// <param name="s"></param>
BiTNode* goLeft(BiTNode* T, stack<BiTNode*>& s)
{
	if (T==NULL)
	{
		return NULL;
	}
	//�ж�T��û�����ӣ�û�а�T����
	//����� T��ջ����������
	while (T->lChild!=NULL)
	{
		s.push(T);
		T = T->lChild;
	}
	return T;
}

void Inoder(BiTNode* T)
{
	if (T==NULL)
	{
		return;
	}
	BiTNode* t = NULL;
	stack<BiTNode*> s;

	t = goLeft(T, s);

	while (t)
	{
		printf("%d ", t->data);

		//���tû�������� �ظ�����1
		if (t->rChild!=NULL)
		{
			t = goLeft(t->rChild,s);//��������������������
		}
		else if (!s.empty())//���tû��������������ջ��ָʾ
		{
			t = s.top();
			s.pop();
		}
		else//���tû�������� ����ջΪ��
		{
			t = NULL;
		}
	}
}


void inOder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//����������
	inOder(root->lChild);

	printf("%d ", root->data);

	//����������
	inOder(root->rChild);
}

int Depth(BiTNode* root)
{
	int deptLeft = 0;
	int deptRight = 0;
	int deptav = 0;
	if (root == NULL)
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

	printf("�ݹ����:\n");
	//�ݹ����
	inOder(&t1);

	printf("\n");

	printf("�ǵݹ������\n");

	Inoder(&t1);

	//int dept = Depth(&t1);
	//inOder(cpNode);
	//printf("dept:%d\n", dept);

	return 0;
}
