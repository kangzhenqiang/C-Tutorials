
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
	多态成立的三个条件：
		1、要有继承
		2、虚函数重写
		3、父类指针指向子类对象
*/

class Parent
{
public:
	Parent(int a = 0);
	~Parent();

	virtual void Print()//1 动手脚地方 写了virtual关键字 会特殊处理 //虚函数表
	{
		cout << "Parent" << endl;
	}

private:
	int a;
};

Parent::Parent(int a)
{
	this->a = a;
}

Parent::~Parent()
{
}

class Child :public Parent
{
public:
	Child(int a = 0, int b = 0);
	~Child();

	void Print()
	{
		cout << "Child" << endl;
	}

private:
	int b;
};

Child::Child(int a, int b) :Parent(a)
{
	this->b = b;
}

Child::~Child()
{
}

void Play(Parent* base)
{
	base->Print();//多态发生 //2 动手脚
	//传来子类时 执行子类的print函数 传来父类执行父类的print函数
	//c++编译器根本不需要区分是子类对象 还是父类对象
	//父类对象和子类对象分别有vptr指针，===>虚函数表===>函数的入口地址
	//迟绑定（运行的时候，c++编译器才去判断）
}


int main()
{
	Child c;//3 动手脚 用类定义对象时 c++编译器会在对象中添加一个vptr指针
	Parent p;
	Play(&c);
	Play(&p);

	system("pause");
	return 0;
}
