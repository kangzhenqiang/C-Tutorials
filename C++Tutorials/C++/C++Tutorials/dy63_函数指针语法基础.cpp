
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
   数组类型基本语法梳理
   定义一个数组类型
   int a[10]

   定义一个指针数组类型

   定义 一个指向 数组类型的指针 数组类指针
*/

int main()
{
	int a[10];//a代表的是数组首元素的地址 &a代表整个数组的地址 a+1 4 &a+1 40

	{
		typedef int(myTypeArray)[10];
		myTypeArray arr;
		arr[0] = 10;
		cout << arr[0] << endl;

	}

	{
		typedef int(*pType)[10];//int *p

		pType p;//sizeof(int) * 10
		p = &a;
		(*p)[0] = 20;
		cout << (*p)[0] << endl;
	}

	{
		//定义一个指向 数值类的的指针 数组类的指针

		int(*Myp)[10];//变量 告诉c编译器 给我分配内存

		Myp = &a;

		(*Myp)[0] = 40;
		cout << (*Myp)[0] << endl;
	}

	system("pause");
	return 0;
}
