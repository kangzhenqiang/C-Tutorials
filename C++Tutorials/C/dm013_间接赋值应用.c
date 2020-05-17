//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//指针作函数参数异常重要
//函数调用时，形参传给实参，用实参取地址，传给形参，在被调用函数里面用*p,来改变实参，把运算结果传出来

void getContentLength(char** myContent1, int* myContentLength1,
	char** myContent2, int* myContentLength2)
{
	char* temp1 = NULL;
	char* temp2 = NULL;

	temp1 = (char*)malloc(sizeof(char) * 128);
	strcpy(temp1, "wangjing");
	*myContentLength1 = strlen(temp1);

	temp2 = (char*)malloc(sizeof(char) * 128);
	strcpy(temp2, "kangzhenqiang");
	*myContentLength2 = strlen(temp2);

	*myContent1 = temp1;
	*myContent2 = temp2;
}


void maindm013()
{
	char* content1 = NULL;
	int length1 = 0;
	char* content2 = NULL;
	int length2 = NULL;

	getContentLength(&content1, &length1, &content2, &length2);

	printf("content1:%s,length:%d\n", content1, length1);
	printf("content1:%s,length:%d\n", content2, length2);

	if (content1!=NULL)
	{
		free(content1);
		content1 = NULL;
	}

	if (content2!=NULL)
	{
		free(content2);
		content2 = NULL;
	}

	system("pause");
}

//间接赋值成立的三个条件
//条件1：//定义1个变量（实参） //定义一个变量（形参）
//条件2：//建立关联：把实参的地址传递给形参
//条件3：//*形参去间接地修改实参的值

//间接赋值应用场景
void maindm01302()
{
	//1 2 3 这3个条件 写在一个函数	
	//12 写在一块 3 单独写在另一个函数里面 =====>函数调用
	//1  23写在一块 ==>抛砖 ====>c++会有，到时别不认识...

	char from[128];
	char to[128];
	char* p1 = from;
	char* p2 = to;

	strcpy(from, "kangzhenqiang");

	while (*p1!='\0')
	{
		*p2 = *p1;
		p1++;
		p2++;
	}

	system("pasue");
}


//用1级指针形参，去间接修改0级指针（实参）的值
//用2级指针形参，去间接修改1级指针（实参）的值
//用3级指针形参，去间接修改2级指针（实参）的值
//用n级指针形参，去间接修改n-1级指针（实参）的值
//指针做函数参数时研究重点

//理解指针必须结合内存四区概念
//1.主调函数 被调函数
//a）主调函数可把堆区、栈区、全局区内存地址传递给被调用函数
//b) 被调用函数只能返回堆区、全局区数据
//2.内存分配方式
//a)指针做函数参数，是有输入和输出特性的
//在主调函数中分配输入到调用函数中叫输入
//在被调用函数中分配输出到主调函数中叫输出