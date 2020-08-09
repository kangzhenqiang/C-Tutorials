#pragma once
#include<iostream>

using namespace std;

/*
	运算符重载的正规写法
	重载 << >> 只能用友元函数，其它运算符重载都要写成成员函数，不要滥用友元函数
	*/

template<typename T>
class Complex
{
	friend ostream& operator<< <T> (ostream& out, Complex<T>& c);
public:
	Complex(T a, T b);
	~Complex();

	Complex operator+(Complex& complex);

	void PrintCom();

private:
	T a;
	T b;
};

