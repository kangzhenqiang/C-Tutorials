//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//一级指针典型用法
//数组 int a[10]
//字符串
//1 C语言的字符串 以零结尾的字符串
//2 在C语言中没有字符串类型 通过字符数组 来模拟字符串
//3 字符串的内存分配 堆上 栈上 全局区（很重要）

//字符数组 初始化
void maindm015()
{
	//1 指定长度
	char buf1[100] = { 'a','b','c','d' };
	char buf2[3] = { 'a','b' ,'\0' };
	//如果初始化的个数大于内存的个数 编译错误
	//未初始化的buf为0

	//2 不指定长度 C编译器会自动帮程序员求元素个数
	char buf3[] = { 'a','b','c','d','\0' };//buf3不是一个数组 不是一个以0结尾的字符串

	printf("buf1:%s\n", buf1);
	printf("buf2:%s\n", buf2);
	printf("buf3:%s\n", buf3);

	//用字符串来初始化字符数组
	char buf4[] = "abcd";//buf4作为字符数据应该是5个字节 //作为字符串 应该4个字节
	int len = sizeof(buf4);
	printf("buf4:%s，len:%d\n", buf4, len);
	//数组是一种数据类型 固定大小内存块别名

	char buf5[128] = "abcd";
	len = sizeof(buf5);
	printf("buf5:%s，len:%d\n", buf4, len);

	system("pause");
}


void maindm01502()
{
	int i = 0;
	char buf5[128] = "abcde";
	char* p = NULL;

	for (size_t i = 0; i < strlen(buf5); i++)
	{
		printf("%c\n", buf5[i]);
	}

	p = buf5;//buf 代表首元素地址
	for (size_t i = 0; i < strlen(buf5); i++)
	{
		printf("%c\n", *(p + i));
	}

	system("pause");
}

//[] *的推导结果
//buf[i] ====>buf[0+i] ====>*(buf+i)
//buf 是一个常量指针，只读的常量 buf是一个常量指针

//p普通指针和内存首地址区别