
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<math.h>

using namespace std;

//面向接口编程（面向预先定义好的一套接口）
//解耦...模块划分

class Figure//抽象类
{
public:
	Figure();
	~Figure();
	//提供一个同一的界面（接口），让子类使用，让子类必须去实现
	virtual int getArea() = 0;//纯虚函数
private:

};

Figure::Figure()
{
}

Figure::~Figure()
{
}



class Circle :public Figure
{
public:
	Circle(int a);
	~Circle();

	virtual int getArea()
	{
		return 3.14 * m_a * m_a;
	}


private:
	int m_a;
};

Circle::Circle(int a)
{
	m_a = a;
}

Circle::~Circle()
{
}

class Squre :public Figure
{
public:
	Squre(int a, int b);
	~Squre();

	virtual int getArea()
	{
		return m_a * m_b;
	}


private:
	int m_a;
	int m_b;
};

Squre::Squre(int a, int b)
{
	m_a = a;
	m_b = b;
}

Squre::~Squre()
{
}


void Play(Figure* base)
{
	base->getArea();//会发生多态
}


int main()
{
	//Figer f;//抽象类不能实例化

	Circle c(10);
	Play(&c);

	Squre s(10, 10);
	Play(&s);


	system("pause");
	return 0;
}
