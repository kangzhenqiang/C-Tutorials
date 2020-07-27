
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Interface1
{
public:
	Interface1();
	~Interface1();

	virtual int Add(int a, int b) = 0;
	virtual void Print() = 0;

private:

};

Interface1::Interface1()
{
}

Interface1::~Interface1()
{
}

class Interface2
{
public:
	Interface2();
	~Interface2();

	virtual int Mult(int a, int b) = 0;
	virtual void Print() = 0;

private:

};


class Parent
{
public:
	Parent();
	~Parent();

	int getA()
	{
		return a;
	}

private:
	int a;
};

Parent::Parent()
{
	a = 10;
}

Parent::~Parent()
{
}

Interface2::Interface2()
{
}

Interface2::~Interface2()
{
}

class Child :public Parent, public Interface1, public Interface2
{
public:
	Child();
	~Child();

	virtual int Add(int a, int b) {
		return a + b;
	}
	virtual void Print() {
		cout << "Child print" << endl;
	}

	virtual int Mult(int a, int b) {
		return a * b;
	}

private:

};

Child::Child()
{
}

Child::~Child()
{
}

int main()
{
	Child child;
	child.Print();

	Interface1 *one = &child;
	one->Add(10, 20);

	Interface2* two = &child;
	two->Mult(10, 20);


	system("pause");
	return 0;
}
