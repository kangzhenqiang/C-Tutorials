
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	1.基本语法
	2.发生异常后是跨函数
	3.接收异常后可不处理，再此抛出
	4.异常捕捉是类型匹配，不是参数匹配
	5.catch异常的时候，按照类型进行catch

	*/


void divide(int a, int b)
{
	if (b == 0)
	{
		throw b;//抛出 int 类型异常
	}
	cout << "divide结果：" << a / b << endl;
}


void myDivide(int a, int b)
{
	divide(a, b);
}

int main()
{
	try
	{
		/*divide(10, 2);
		divide(10, 0);*/
		//myDivide(100, 0);

		throw "Z";
	}
	catch (int e)
	{
		cout << "被零除" << endl;
	}
	catch (const std::exception&)
	{

	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	system("pause");
	return 0;
}
