
//sizeof(求内存大小)操作符
//内存四区模型
	//栈区（stack）：由编译器自动分配释放，存放函数的参数，局部变量的值
	//堆区（heap）：一般由程序员分配释放（动态内存申请与释放），若程序员不释放，程序结束时可能由操作系统回收
	//全局区（静态区）static：全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和未初始化的静态变量在相邻一块区域，该区域在程序结束后由系统释放
	//常量区：字符串常量和其它常量的存储位置，程序结束后由操作系统释放
	//代码区：存放函数体的二进制代码

//指针指向谁就把谁的地址赋给指针
//指针变量和它指向的内存空间变量是两个不同概念

#include <stdio.h>

char* getStr1()
{
	char* p = "kang zhen qiang";
	return p;
}

char* getStr2()
{
	char* p = "kang zhen qiang";
	return p;
}


void maindm005()
{
	char* p1 = NULL;
	p1 = getStr1();
	printf("p=%s\n", p1);
	printf("p=%d\n", p1);

	char* p2 = NULL;
	p2 = getStr2();
	printf("p=%s\n", p2);
	printf("p=%d\n", p2);

	system("pause");
}