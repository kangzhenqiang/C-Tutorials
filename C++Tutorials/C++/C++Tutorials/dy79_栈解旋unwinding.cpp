
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Test
{
public:
	Test(int a,int b);
	~Test();

private:
	int a;
	int b;
};

Test::Test(int a, int b)
{
	this->a = a;
	this->b = b;
	cout << "构造函数" << endl;
}

Test::~Test()
{
	cout << "析构函数" << endl;
}

void divide() throw(int, char)//抛出异常类型范围
{

}

void divide() throw()//不抛出异常类型
{

}

void divide()//抛出任何异常类型
{

}



int main()
{
	try
	{
		Test t1(10,20);
		throw 1;
	}
	catch (const std::exception&)
	{

	}
	catch (...)
	{

	}
	system("pause");
	return 0;
}
