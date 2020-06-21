
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//静态链接 
//规定大小 节点内存的生命周期
//动态链表

typedef struct PearonD
{
	int data;
	struct PearonD* p;
} PearonD;

PearonD* CreateList()
{
	PearonD p1, p2, p3;
	PearonD* p = NULL;
	p1.data = 1;
	p2.data = 2;
	p3.data = 3;

	p1.p = &p2;
	p2.p = &p3;
	p3.p = NULL;

	p = &p1;

	while (p!=NULL)
	{
		printf("data:%d\n", p->data);
		p = p->p;
	}
	return &p1;
}


void maindy047()
{
	PearonD* p = NULL;
	CreateList();
	system("pause");
}
