#include <iostream>
using namespace std;

/// <summary>
/// 返回值
/// </summary>
/// <returns></returns>
int getA1()
{
	int a;
	a = 10;
	return a;
}

/// <summary>
/// 返回引用 返回a的一个副本10
/// </summary>
/// <returns></returns>
int& getA2()
{
	int a;
	a = 20;
	return a;
}

/// <summary>
/// 返回指针
/// </summary>
/// <returns></returns>
int* getA3()
{
	int a = 5;
	a = 30;
	return &a;
}

/*
	c++中使用引用难点：
		当函数返回值为引用时
			若返回栈变量，不能成为其它引用的初始值，不能作为左值使用；
			若返回静态变量或全局变量，即可作为右值使用，也可以作为左值使用；
*/

int j1()
{
	static int a = 1;
	a++;
	return a;
}

int& j2()
{
	static int a = 1;
	a++;
	return a;
}

void maindy08001()
{
	int a1 = getA1();

	int a2 = getA2();

	int* a3 = getA3();

	int& a4 = getA2();//若返回栈变量，不能成为其它引用的初始值，不能作为左值使用；

	cout << a1 << endl;
	cout << a2 << endl;
	cout << *a3 << endl;


	//返回变量时static或者是全局变量

	int a5 = j1();
	int a6 = j1();
	int& a7 = j2();

	cout << a5 << endl;
	cout << a6 << endl;
	cout << a7 << endl;

	system("pause");
}

//函数当左值

//返回变量的值
int g1()
{
	static int a = 1;
	a++;
	return a;
}

//返回变量本身
int& g2()
{
	static int a = 1;
	a++;
	cout << a << endl;
	return a;
}

void maindy08()
{
	//g1() = 10;
	g2() = 20;
	g2();
	system("pause");
}