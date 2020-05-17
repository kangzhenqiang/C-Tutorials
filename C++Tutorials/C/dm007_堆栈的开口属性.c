//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一般情况认为：栈开口向上向下，测试release和debug
//一般认为：栈开口向下 避免栈的溢出
//不管栈开口向上还是向下,buf的内存地址：buf+1永远是向上的
//栈的生长方向和buf的内存增长方向是两个不同概念

void maindm007()
{
	int a;
	int b;
	//栈去开口向上
	printf("&a:%d, &b:%d\n", &a, &b);

	char buf[128];//静态编译的时候buf所代表的内存空间标号就已经定义下来了

	system("pause");
}