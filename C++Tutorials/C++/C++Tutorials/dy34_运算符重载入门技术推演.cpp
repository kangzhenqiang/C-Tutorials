#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(int a = 0, int b = 0);
	~Complex();

	int a;
	int b;

	//成员函数 完成 - 操作符 重载
	Complex operator-(const Complex& obj);

private:

};

Complex::Complex(int a, int b)//函数不进行重载
{
	this->a = a;
	this->b = b;
}

Complex::~Complex()
{
}

Complex Complex::operator-(const Complex& obj)
{
	Complex temp(this->a - obj.a, this->b - obj.b);
	return temp;
}

Complex Add(Complex& c1, Complex& c2)
{
	Complex tempC(c1.a + c1.a, c1.b + c2.b);
	return tempC;
}

//全局函数 完成 + 操作符 重载
Complex operator+(Complex& c1, Complex& c2)
{
	Complex tempC(c1.a + c1.a, c1.b + c2.b);
	return tempC;
}


//根据业务需要返回引用、指针、元素 

int maindy034()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//基础类型 编译器知道如何运算

	Complex c1(1, 2), c2(3, 4);
	Complex c3;
	//c3 = c1 + c2;//类也是一种类型 用户自定义数据类型 c++编译器 是不知道如何进行运算

	//c++编译器给我们程序员提供一种机制...
	//让自定义数据类型机制 有机会进行 运算符操作 ===>运算符重载机制
	//元素符重载机制

	//步骤 1
	//c3 = Add(c1, c2);

	//步骤 2
	c3 = operator+(c1, c2);

	//步骤 3
	c3 = c1 + c2;

	/*
		运算符重载
			1. 运算符重载的本质是函数调用

	*/
	c3 = c1 - c2;
	cout << c3.a << endl;
	cout << c3.b << endl;

	system("pause");
	return 0;
}