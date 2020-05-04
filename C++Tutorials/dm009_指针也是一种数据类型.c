//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void maindm00901()
{
	int a = 10;
	char* p1 = 100;
	char**** p2 = 200;

	int* p3 = NULL;
	p3 = &a;

	printf("a:%d\n", a);
	*p3 = 20;//间接的修改a的值
	//*就向一把钥匙，通过一个地址（&a）,去修改a变量的标示的内存空间

	{
		//*p放在=号左边 写内存
		//*p放=号的右边 读内存
		int c = 0;
		c = *p3;
		printf("c:%d\n", c);
	}
	{
		//不断的给指针赋值相当于不停的改变指针的指向
		char* p4 = NULL;
		p4 = (char*)malloc(sizeof(char) * 100);
		p4 = (char*)malloc(sizeof(char) * 100);
	}

	printf("a:%d\n", a);

	printf("a:%d,p1:%d,p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));

	system("pause");
}

char* getStrdm009()
{
	char* p = NULL;
	p = "abcd";
	return p;
}

//指针作函数参数
//形成作函数参数 形参有多级指针的时候，站在编译器的角度，只需要分配4个字节的内存（32平台）
//当我们使用内存的时候，我们才关心指针指向的内存是一维还是二维的
//指针也是一种数据类型，是指它指向内存空间的数据来确定
//指针类型决定了指针的步长

int getABC1(char* P1);
int getABC2(char** P2);
int getABC3(char*** P3);
int getABC4(char(*p4)[30]);
int getABC5(char p5[10][30]);

void maindm009()
{
	char* p = getStrdm009();
	printf("%s\n", p);

	/**(p + 2) = 'r';*///经常出现错误，保证指针所指向的内存空间可以被修改
	printf("%s\n", p);
	system("pause");
}

int getABC1(char* P1)
{
	return 0;
}

int getABC2(char** P2)
{
	return 0;
}

int getABC3(char*** P3)
{
	return 0;
}

int getABC4(char(*p4)[30])
{
	return 0;
}

int getABC5(char p5[10][30])
{
	return 0;
}
