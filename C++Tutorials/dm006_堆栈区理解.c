//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//理解指针的关键是内存，没有内存那来的指针
//

//堆
char *getMem(int num)
{
	char* p = NULL;
	p = (char *)malloc(sizeof(char) * num);
	if (p==NULL)
	{
		return NULL;
	}
	return p;
}

//栈
//注意：return不是把内存块64个字节给return出来，而是把内存块的首地址返回给temp
char* getStr()
{
	char buf[64];
	strcpy(buf, "kan");
	printf("buf:%s\n", buf);
	return buf;
}

void maindm006()
{
	char *temp = NULL;
	temp = getMem(20);
	if (temp==NULL)
	{
		return;
	}
	//向temp指向的内存空间中拷贝数据	
	strcpy(temp, "1111");
	printf("temp:%s\n", temp);
	temp = getStr();
	printf("temp:%s\n", temp);
	system("pause");
}