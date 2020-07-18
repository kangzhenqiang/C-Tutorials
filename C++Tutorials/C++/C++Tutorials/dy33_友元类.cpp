#include <iostream>

using namespace std;

/*
	友元类  有元函数

	为什么设计友元类和友元函数？
	1. java----->class(字节码) ====>反射机制分析 class 找到类的对象 直接修改类的私有属性
	反射机制成为一种标准 jdk sun做成标准 jdk的API函数中有体现
	AOP
	2. cpp===>
	预编译 编译 链接 生成 ..gcc -E //gcc -s
	gcc -o ..exe .c
	汇编往回找 很难
	3. 友元类和友元函数
	*/


class A
{
public:

	A();
	~A();
	friend class B;
private:
	int x;
};

A::A()
{
	x = 0;
}

A::~A()
{
}

class B
{
public:
	B();
	~B();

	void setObjA()
	{
		objA.x = 100;
	}

	int getObjA()
	{
		return objA.x;
	}

private:
	A objA;
};

B::B()
{
}

B::~B()
{
}


int maindy033()
{
	B b;
	b.setObjA();

	cout << b.getObjA() << endl;
	system("pause");

	return 0;
}