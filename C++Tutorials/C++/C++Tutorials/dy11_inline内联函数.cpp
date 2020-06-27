#include<iostream>

using namespace std;

/*
	内联函数：推荐使用内联函数方案替代宏代码片断
	内联函数inline void printA()必须和实现写在一个地方
	c++编译器直接将内联函数的函数体插入在函数调用地方
	不能存在任何形式的循环语句
	不能存在过多的条件判断语句
	函数体不能过大

	结论：
		1. 内联函数在编译时直接将函数体插入函数调用的地方
		2. inline只是一种请求，编译器不一定允许这种请求
		3. 内联函数省去了普通函数调用时压栈，跳转和返回的开销
	*/

inline void printA()
{
	int a = 10;
	cout << a << endl;
}

void maindy11001()
{
	printA();
	system("pause");
}

//宏定义
#define MYFUNC(a,b) ((a)<(b)?(a):(b))

inline int myfun(int a,int b)
{
	return a < b ? a : b;
}

void maindy11002()
{
	int a = 1;
	int b = 3;
	//一般不用++a、和--a作函数参数

	int c = MYFUNC(++a, b);//====>宏替换并展开 ((a)<(b)?(a):(b))

	int d = myfun(++a, b);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	system("pause");
}

