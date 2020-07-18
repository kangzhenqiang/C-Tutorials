#include <iostream>

using namespace std;

/*
	全局函数，类成员函数方法实现运算符重载步骤：
		1. 要承认操作符重载是一个函数，写出函数名称
		2. 根据操作舒，写出函数参数
		2. 根据业务，完善函数返回值（看函数是返回引用、还是指针、还是元素），及实现函数业务
*/


class Complex
{
public:
	Complex(int a = 0, int b = 0);
	~Complex();
	
	//使用全局函数 实现了+重载运算符 借助友元函数实现私有字段访问
	friend Complex operator+(Complex& obj1, Complex& obj2);

	friend Complex& operator++(Complex& obj);

	friend Complex operator++(Complex& obj, int);

	//成员函数重载
	Complex operator- (Complex& obj);
	//前置--
	Complex& operator--();
	//后置--
	Complex operator--(int);

	void printf()
	{
		cout << a << endl;
		cout << b << endl;
	}
private:
	int a;
	int b;
};

Complex::Complex(int a, int b)
{
	this->a = a;
	this->b = b;
}

Complex::~Complex()
{
}

Complex Complex::operator--(int)
{
	Complex temp = *this;
	this->a--;
	this->b--;
	return temp;
}

Complex Complex::operator-(Complex& obj)
{
	Complex temp(this->a - obj.a, this->b - obj.b);
	return temp;
}

Complex& Complex::operator--()
{
	// TODO: 在此处插入 return 语句
	this->a--;
	this->b--;
	return *this;
}

//全局函数 实现了+重载运算符
Complex operator+(Complex& obj1, Complex& obj2)
{
	Complex temp(obj1.a - obj2.a, obj1.b - obj2.b);
	return Complex();
}

//重载前置++
Complex& operator++(Complex& obj)
{
	obj.a++;
	obj.b++;
	return obj;
}

//重载后置++
Complex operator++(Complex& obj,int)
{
	//先使用 在让obj++
	Complex tem = obj;
	obj.a++;
	obj.b++;
	return tem;
}

int maindy035()
{
	Complex c1(1, 1), c2(2, 2);
	//1 全局函数法 实现 + 运算符重载
	// Complex opreatr+(Complex &c1,Complex &c2)

	//2 成员函数法 实现 + 运算符重载
	//c1.operator+(c2)
	//Complex opreator+(Complex &c2)

	Complex c = c1 - c2;

	//前置++操作符 用全局函数实现

	++c;
	c.printf();

	--c;
	c.printf();

	//使用后置操作符

	c++;
	c.printf();

	//用成员函数方法实现后置--
	c--;
	c.printf();

	
	system("pause");
	return 0;
}