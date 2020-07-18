#include<iostream>

using namespace std;

/*
	1. 运算符正规写法是类的成员函数
	2. 友元函数应用场景
	*/

class Complex
{
public:
	Complex(int a = 0, int b = 0);
	~Complex();

	friend ostream& operator<<(ostream& out, Complex& c);

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

/*
void operator<<(ostream& out, Complex& c)
{
	out << "123" << endl;
	out << c.a << endl;
	out << c.b << endl
}
*/

ostream& operator<<(ostream& out, Complex& c)
{
	out << "123" << endl;
	out << c.a << endl;
	out << c.b << endl;
	return out;
}


int maindy036()
{
	Complex c(1, 2);
	//函数返回值当左值需要返回一个引用
	cout << c << endl;

	system("pause");
	return 0;
}