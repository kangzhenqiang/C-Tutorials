#include <iostream>

using namespace std;

/*
	1. 当函数明和不同的参数搭配是函数的含义不相同
	2. 函数重载的判断标准
	3. 名称 参数 返回值
	4. 名称相同 参数不一样（个数、类型）
	5. 返回值 不是 判断函数重载的标准

	将所有同名函数作为候选者
	尝试寻找可行的候选函数
	精确匹配实参
	通过默认参数能够匹配参数
	通过默认类型转换匹配实参
	匹配失败
	最重寻找到可行候选函数不唯一，则出现二义性，编译失败
	无法匹配所有候选者，函数未定义，编译失败
*/


void myPrint001(int a)
{
	cout << a << endl;
}

void myPrint001(char* p)
{
	cout << *p << endl;
}

void myPrint001(int a, int b)
{
	cout << a << endl;
	cout << b << endl;
}

void maindy13001()
{

	system("pause");
}