
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class A
{
public:
	A();
	/*virtual*/ ~A();

private:
	char* p;
};

A::A()
{
	p = new char[20];
	strcpy(p, "kang");
	cout << "构造A" << endl;
}

A::~A()
{
	cout << "析构A" << endl;
	delete[] p;
}


class B :public A
{
public:
	B();
	~B();

private:
	char* p;
};

B::B()
{
	p = new char[20];
	strcpy(p, "wang");
	cout << "构造B" << endl;
}

B::~B()
{
	cout << "析构B" << endl;
	delete[] p;
}


class C :public B
{
public:
	C();
	~C();

private:
	char* p;
};

C::C()
{
	p = new char[20];
	strcpy(p, "hao");
	cout << "构造C" << endl;
}

C::~C()
{
	cout << "析构C" << endl;
	delete[] p;
}

//只执行了 父类的析构函数
//向通过父类指针 把所有的子类对象的析构函数都析构一遍
//向通过父类指针 释放所有的子类资源
//直接通过子类指针释放资源不需要写vitural
void howtodelete(A* base)
{
	delete base;
}

int main()
{
	C* myC = new C;// new delete匹配
	//howtodelete(myC);
	delete myC;
	system("pause");
	return 0;
}
