
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
	函数指针的基本语法
	1 如何定义一个函数类型
	2 如何定义一个函数指针类型
	3 如何定义一个 函数指针 （指向一个函数的入口地址）
	*/

int add(int a, int b)
{
	cout << "fun add .." << endl;
	cout << a + b << endl;
	return a + b;
}


int main()
{
	add(4, 5);//直接调用 函数吗就是函数的入口地址

	//定义一个函数类型
	{
		typedef int (MyfuncType)(int a, int b);
		MyfuncType* myPointterFucn = NULL;
		myPointterFucn = &add;//细节
		myPointterFucn(7, 8);

		myPointterFucn = add;//细节 c是逐步完善起来的，兼容力时版本的原因
		myPointterFucn(7, 8);
	}

	//定义一个函数指针类型
	{
		typedef int (*MyPointrtFucType)(int a, int b);
		MyPointrtFucType myPointer;
		myPointer = &add;
		myPointer(6, 7);
	}

	//直接定义一个函数类型
	{
		int (*MyPoimtFuc)(int a, int b);//定义一个变量
		MyPoimtFuc = add;
		MyPoimtFuc(1, 2);
	}

	system("pause");
	return 0;
}
