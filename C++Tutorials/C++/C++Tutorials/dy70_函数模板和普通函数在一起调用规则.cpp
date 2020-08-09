
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
	函数模板不允许自动类型转换
	普通函数能够进行自动类型转换
	*/

	/*
		1 函数模板可以像普通函数一样重载
		2 c++编译器有限考虑普通函数
		3 如果函数模板可以产生一个更好的匹配，那么选择模板
		4 可以通过空模板实参列表的语法限定编译器只通过模板匹配
		*/

int Max(int a, int b)
{
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	cout << "T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b, T c)
{
	cout << "T Max(T a, T b,T c)" << endl;
	return Max(Max(a, b), c);
}

int main()
{
	int a = 10;
	int b = 20;

	cout << Max(a, b) << endl;//当模板函数和普通函数都符合调用时，优先选择普通函数

	cout << Max(a, b) << endl;//若显示的使用函数模板，则使用<>类型列表

	cout << Max(3.5, 5.8)<<endl;//如果函数模板产生更好的匹配 使用函数模板

	cout << Max(3.5, 5.8, 7.0) << endl;//重载

	cout << Max('a', 10) << endl;//调用普通函数 可以隐式类型转换

	system("pause");
	return 0;
}

/*
	编译器并不会把函数模板模板处理成能够处理任意类的函数
	编译器从函数模板通过具体类型产生不同的函数
	编译器会对函数模板进行两次编译
	在声明的地方对模板代码本身进行编译
	在调用的地方对参数替换后的代码进行编译
	*/
