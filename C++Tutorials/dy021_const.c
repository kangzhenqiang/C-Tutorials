#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void getConstModel(const char* p)
{
	p = 1;
}


void maindy021()
{
	/*
	//整形变量不能被修改
	const int a;
	//整形变量不能被修改
	int const b;
	//上述两种写法一样，代表一个常整形数

	//c是一个指向常整形数的指针（所指向的内存数据不能被修改，但本身可以被修改）
	const char* c;

	//d是常指针（指针变量不能被修改，但是它所指向的内存空间可以被修改）
	char* const d;//char buf[100];

	//e是一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）
	const char* const e;

	//指针变量和它所指向的内存空间变量，是两个不同的概念
	//看const是放在*的左边还是右边 看const是修饰指针变量，还是修饰所指向的内存空间变量
	*/
	char* p = NULL;
	const char* p2 = NULL;
	p2 = 1;

	//结论C语言中的const修饰的比哪里是假的，c语言中const是一个冒牌货
	const int a = 100;
	//a = 200;

	{
		int* p = &a;
		*p = 200;
		printf("a:%d\n", a);
	}

	system("pause");
}