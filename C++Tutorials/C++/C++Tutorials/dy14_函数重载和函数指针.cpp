#include<iostream>

using namespace std;

void myfunc00000(int a)
{
	cout << a << endl;
}

void myfunc00000(char* p)
{
	cout << *p << endl;
}


void myfunc00000(int a, int b)
{
	cout << a << endl;
	cout << b << endl;
}

void myfunc00000(char* p1, char* p2)
{
	cout << *p1 << endl;
	cout << *p2 << endl;
}

/*
	函数指针
		1. 申明一个函数类型
	*/

typedef void (myTypeFunc)(int a, int b);

/*
		2. myTypeFunc* fuc = NULL;//定义一个函数指针 指向函数入口地址
	*/


	/*
			3. 申明一个函数指针类型
		*/
typedef void(*myPTypeFuc)(int a, int b);

/*
		4. myPTypeFunc fp = NULL;//通过 函数指针类型定义了一个函数指针
	*/


	/*
			5. 定义了一个函数指针变量
		*/

void (*myVarPFunc)(int a, int b);


int maindy014()
{
	myTypeFunc* fuc = NULL;//定义一个函数指针 指向函数入口地址

	myPTypeFuc pfunc = NULL;

	pfunc = myfunc00000;

	pfunc(1, 4);

	/*pfunc("kang", "zhen");*/

	system("pause");

	return 0;
}