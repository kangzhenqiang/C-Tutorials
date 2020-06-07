
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void getLen(int *p)
{
	*p = 40;//*谁的地址 就间接修改谁的值
}


void maindy045001()
{
	int a = 10;
	int* p = NULL;
	printf("a:%d\n", a);
	a = 11;
	printf("a:%d\n", a);
	p = &a;
	printf("a:%d\n", a);
	*p = 30;
	printf("a:%d\n", a);
	{
		*p = 40;
		printf("a:%d\n", a);
	}
	system("pause");
}

int getMem045(char** p/*20*/)
{
	*p = 30;//间接赋值，p2是p的地址

	*p = (char**)malloc(1000);

}


void maindy045002()
{
	char* p = NULL;
	char** p2 = NULL;

	p = 1;//直接修改
	printf("a:%d\n", p);
	p2 = &p;

	*p2 = 30;
	printf("a:%d\n", p);
	{
		*p2 = 40;//间接修改值
		printf("a:%d\n", p);
	}
	system("pause");
}