#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

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
	步骤1：
		如果节点有左子树，该借点入栈；
		如果结点没有左子树，访问该节点；
	步骤2：
		如果节点有右字树，重复步骤1；
		如果节点没有右子树（结点访问完毕），根据栈顶指示回退，访问栈顶元素，并访问右子树，重复步骤1
		如果栈为空，表示遍历结束
	
	*/


/// <summary>
/// 一直往左走，找到遍历起点
/// </summary>
/// <param name="T"></param>
/// <param name="s"></param>
BiTNode* goLeft(BiTNode* T, stack<BiTNode*>& s)
{
	if (T==NULL)
	{
		return NULL;
	}
	//判断T有没有左孩子，没有把T返回
	//如果有 T入栈，再往左走
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

		//如果t没有右字树 重复步骤1
		if (t->rChild!=NULL)
		{
			t = goLeft(t->rChild,s);//右子树中中序遍历的起点
		}
		else if (!s.empty())//如果t没有右子树，根据栈顶指示
		{
			t = s.top();
			s.pop();
		}
		else//如果t没有右子树 并且栈为空
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

	//遍历左子树
	inOder(root->lChild);

	printf("%d ", root->data);

	//遍历右子树
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
	//求组子树高度
	deptLeft = Depth(root->lChild);
	//求右字数高度
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

	//建立管理
	t1.lChild = &t2;
	t1.rChild = &t3;
	t2.lChild = &t4;
	t3.lChild = &t5;

	//树的遍历

	printf("递归遍历:\n");
	//递归遍历
	inOder(&t1);

	printf("\n");

	printf("非递归遍历：\n");

	Inoder(&t1);

	//int dept = Depth(&t1);
	//inOder(cpNode);
	//printf("dept:%d\n", dept);

	return 0;
}
