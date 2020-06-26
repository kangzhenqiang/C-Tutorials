#include<iostream>

using namespace std;


/*
	实用性增强

	1. c 语言中的变量都必须在作用域开始的位置定义;
	2. c++中更强调语言的“实用性”，所有的变量都可以在需要使用时再定义；
	*/

void maindy01001()
{
	int i = 0;

	cout << i << endl;

	int k = 5;

	system("pause");
}

/*
	register关键字增强

	register 关键字在c语言中请求编译器让变量直接放在寄存器里面，速度快，不能取地址

	1. c++中有自己的优化方式，不适用register也能做优化

	2. c++编译器发现程序中需要取register变量的地址时，register对变量的声明变得无效

	3. 早期c语言编译器不会对代码进行优化，因此register变量是一个很好的补充

	*/

void maindy01002()
{
	register int a = 0;
}


/*
	变量检测增强 
	函数检查增强
	struct类型加强 struct和class关键字实现的功能时一样的
	c++中所有的变量和函数都必须有类型
	c语言中的默认类型在c++中时不合法的
	新增的bool类型关键字
	在c语言中 表达式的元素结果放在什么地方 寄存器
	在c语言中，表达式的返回值是一个数
	在c++语言中，表达式返回的是变量的自身
	*/

void maindy02003()
{
	bool b = true;//告诉编译器给分配1个内存

	cout << "sizeof bool:" << sizeof(bool) << endl;

	//b = 10;

	cout << b << endl;

	system("pause");
}