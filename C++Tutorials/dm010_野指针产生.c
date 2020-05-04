//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//野指针产生的原因
//指针变量和它所指向的内存空间变量是两个不同概念
//释放了指针所致的内存空间 但指针变量本身没有重置为NULL
//造成释放的时候 通过if（p!=null）
//避免方法：1）定义指针的时候 初始化为NULL  2）释放指针所指向的内存空间以后把指针重置为NULL

void maindm010()
{
	char* p1 = NULL;
	p1 = (char*)malloc(100);
	if (p1==NULL)
	{
		return;
	}
	strcpy(p1, "1111222");
	if (p1!=NULL)
	{
		//指针变量释放指向内存块时，把指针变量置为NULL
		free(p1);
		p1 = NULL;
	}
	if (p1!=NULL)
	{
		free(p1);
	}

	system("pause");
}