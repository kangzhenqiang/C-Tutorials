/*
	在c语言中 表达式的元素结果放在什么地方 寄存器
	在c语言中，表达式的返回值是一个数
	在c++语言中，表达式返回的是变量的自身
	在C语言中如何实现c++一样效果

	本质
	c++编译器 帮助我们实现这边工作
	*(a<b?&a:&b)30;

	c语言返回变量值，c++返回变量
	*/

#include <iostream>

int maindy03001()
{
	int a = 10;
	int b = 20;

	//返回一个最小数，并且给最小数值赋值成3

	//三目运算是一个表达，表达式不可能做左值

	(a < b ? a : b) = 3;

	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	system("pause");
	return 1;
}