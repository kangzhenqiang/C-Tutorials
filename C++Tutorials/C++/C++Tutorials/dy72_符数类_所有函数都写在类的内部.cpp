
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
class Complex
{
	friend ostream& operator<<(ostream& out, Complex& c);

public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	~Complex()
	{

	}


	Complex operator+(Complex& complex) {
		Complex c(this->a + complex.a, this->b + complex.b);
		return c;
	}


	void PrintCom()
	{
		cout << "a:" << a << "," << "b:" << b << endl;
	}

private:
	int a;
	int b;
};

ostream& operator<<(ostream& out, Complex& c) {
	out << c.a << endl;
	out << c.b << endl;
	return out;
}
*/


/*
	��������ص�����д��
	���� << >> ֻ������Ԫ������������������ض�Ҫд�ɳ�Ա��������Ҫ������Ԫ����
	*/

template<typename T>
class Complex
{
	friend ostream& operator<<(ostream& out, Complex<T>& c) {
		out << c.a << endl;
		out << c.b << endl;
		return out;
	}

	friend Complex<T> MySub(Complex<T>& c1, Complex<T>& c2)
	{
		Complex<T> temp(c1.a - c2.a, c1.b - c2.b);
		return temp;
	}

public:
	Complex(T a, T b)
	{
		this->a = a;
		this->b = b;
	}
	~Complex()
	{

	}

	Complex operator+(Complex& complex) {
		Complex c(this->a + complex.a, this->b + complex.b);
		return c;
	}


	void PrintCom()
	{
		cout << "a:" << a << "," << "b:" << b << endl;
	}


private:
	T a;
	T b;
};



int main()
{
	/*Complex c1(10, 20);
	Complex c2(10, 20);

	Complex c3 = c1 + c2;

	cout << c3 << endl;*/

	Complex<int> c1(10, 20);
	Complex<int> c2(20, 30);

	Complex<int> c3 = c1 + c2;

	cout << c3 << endl;

	//������Ԫ����
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	system("pause");
	return 0;
}
