#include <iostream>

using namespace std;

//同名成员变量
//同名成员函数
class A
{
public:
	A();
	~A();
	int a;
	int b;
	void get_b()
	{
		cout << b << endl;
	}
private:

};

A::A()
{
	a = 0;
	b = 0;
}

A::~A()
{
}

class B :public A
{
public:
	B();
	~B();
	int a;
	int b;
	void get_b()
	{
		cout << b << endl;
	}
private:

};

B::B()
{
	a = 0;
	b = 0;
}

B::~B()
{
}

int main()
{
	B b;
	b.b = 1;
	b.A::a = 2;


	system("pause");
	return 0;
}