#include<iostream>

using namespace std;

class A
{
public:
	A();
	~A();
	int a;

private:
	
};

A::A()
{
	a = 0;
}

A::~A()
{
}


class B1 :public A
{
public:
	B1();
	~B1();

private:

};

B1::B1()
{
}

B1::~B1()
{
}

class B2 :public A
{
public:
	B2();
	~B2();

private:

};

B2::B2()
{
}

B2::~B2()
{
}

class C :public B1, public B2
{
public:
	C();
	~C();

private:

};

C::C()
{
}

C::~C()
{
}

int main()
{
	C c;
	//多继承二义性
	//c.a = 100;

	system("pause");
	return 0;
}