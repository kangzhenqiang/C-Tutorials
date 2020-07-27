#include <iostream>

using namespace std;


/*
	类型兼容原则：
		子类对象可以当作父类对象使用
		子类对象可以直接赋值给父类对象
		子类对象可以直接初始化父类对象
		父类对象可以直接指向子类对象
		父类引用可以直接引用子类对象
	*/


class Parent
{
public:
	Parent();
	~Parent();

	void PrintP()
	{
		cout << "Parent" << endl;
	}

private:

};

Parent::Parent()
{
}

Parent::~Parent()
{
}

class Child :public Parent
{
public:
	Child();
	~Child();

	void PrintC()
	{
		cout << "Child" << endl;
	}

private:

};

Child::Child()
{
}

Child::~Child()
{
}

void howToPrint(Parent *p)
{
	p->PrintP();
}

void printP(Parent& p)
{
	p.PrintP();
}

int main()
{
	Parent p;
	Child c;
	p.PrintP();
	c.PrintC();
	c.PrintP();

	//1 赋值兼容性原则
	//1-1基类指针（引用）指向子类对象
	Parent* pp = NULL;
	pp = &c;
	pp->PrintP();

	//1-2 指针作函数参数
	howToPrint(&c);

	//1-3 引用做函数参数
	printP(c);

	//2 第二次含义
	//可以让父类对象初始化子类对象 子类就是一种特殊的父类
	Parent p3 = c;


    system("pause");
	return 0;
}