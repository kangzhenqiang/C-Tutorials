//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void maindm016()
{
	char buf1[20] = "aaaa";
	char buf2[] = "bbbb";
	char* p1 = "1111";
	char* p2 = (char)malloc(100);
	strcpy(p2, "3333");
	system("pause");
}