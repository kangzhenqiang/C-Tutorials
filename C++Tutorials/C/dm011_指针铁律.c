//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void maindm01001()
{
	//指针铁律

	//指针指向NULL时内存空间不允许拷贝数据，因为该内存区间受系统保护
	char *p = NULL;
	strcpy(p, "kangzhenqiang");
	system("pause");
}

void maindm01002()
{
	int i;
	int j;
	char buf[128];

	char* p = NULL;

	char* p1 = NULL;

	p = &buf[0];//不断修改p1的指向相当于不断的修改指针的指向
	p = &buf[1];
	p = &buf[2];
	p = &buf[3];

	for (int i=0;i<10;i++)
	{
		p = &buf[i];
	}

	p1 = (char*)malloc(128);

	for (int i = 0; i < 10; i++)
	{
		p = p1[i];
	}

	system("pause");
}