//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getFileLength(int* p) {
	*p = 50;//p的值是a的地址间接修改a的值，形参间接取修改实参的值
}

//具有对外属性，初始化和函数体内int p没有区别
int getFile(int p) {
	p = 60;//p的值是a的地址间接修改a的值
}

//一级指针技术推演
void maindm01201()
{
	int a = 0;
	int* p = NULL;

	//直接修改
	a = 20;

	printf("a:%d\n", a);

	p = &a;
	*p = 30;

	{
		*p = 40;
	}

	getFileLength(&a);

	printf("a:%d\n", a);

	getFile(a);
	printf("a:%d\n", a);

	system("pause");
}

void getMember(int** p)
{
	*p = 300;
}


//一级指针到二级指针推演
void maindm01202()
{
	char* p1 = NULL;//条件1 定义了两个变量
	char** p2 = NULL;

	//直接修改p1的值

	//间接修改p1的值

	p2 = &p1;//建立关联

	*p2 = 20;//p2是p1的地址，通过*p间接取修改值

	printf("p1:%d\n", p1);


	{
		*p2 = 200;
		printf("p1:%d\n", p1);
	}

	getMember(&p1);
	printf("p1:%d\n", p1);

	system("pause");
	return;
}