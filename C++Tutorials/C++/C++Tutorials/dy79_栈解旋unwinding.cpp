
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
	cout << "���캯��" << endl;
}

Test::~Test()
{
	cout << "��������" << endl;
}

void divide() throw(int, char)//�׳��쳣���ͷ�Χ
{

}

void divide() throw()//���׳��쳣����
{

}

void divide()//�׳��κ��쳣����
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
