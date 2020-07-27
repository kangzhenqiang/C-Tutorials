
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

class ParentParent
{
public:
	ParentParent(int a = 0);
	~ParentParent();

	void Print()//1 动手脚地方 写了virtual关键字 会特殊处理 //虚函数表
	{
		cout << "Parent" << endl;
	}

private:
	int a;
};

ParentParent::ParentParent(int a)
{
	this->a = a;
}

ParentParent::~ParentParent()
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
	Parent p;
	ParentParent pp;
	cout << sizeof(p) << endl;
	cout << sizeof(pp) << endl;
	system("pause");
	return 0;
}
