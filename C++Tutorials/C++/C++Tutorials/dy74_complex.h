#pragma once
#include<iostream>

using namespace std;

/*
	��������ص�����д��
	���� << >> ֻ������Ԫ������������������ض�Ҫд�ɳ�Ա��������Ҫ������Ԫ����
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

