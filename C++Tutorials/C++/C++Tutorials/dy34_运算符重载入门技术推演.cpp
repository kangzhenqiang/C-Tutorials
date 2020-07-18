#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(int a = 0, int b = 0);
	~Complex();

	int a;
	int b;

	//��Ա���� ��� - ������ ����
	Complex operator-(const Complex& obj);

private:

};

Complex::Complex(int a, int b)//��������������
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

//ȫ�ֺ��� ��� + ������ ����
Complex operator+(Complex& c1, Complex& c2)
{
	Complex tempC(c1.a + c1.a, c1.b + c2.b);
	return tempC;
}


//����ҵ����Ҫ�������á�ָ�롢Ԫ�� 

int maindy034()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//�������� ������֪���������

	Complex c1(1, 2), c2(3, 4);
	Complex c3;
	//c3 = c1 + c2;//��Ҳ��һ������ �û��Զ����������� c++������ �ǲ�֪����ν�������

	//c++�����������ǳ���Ա�ṩһ�ֻ���...
	//���Զ����������ͻ��� �л������ ��������� ===>��������ػ���
	//Ԫ�ط����ػ���

	//���� 1
	//c3 = Add(c1, c2);

	//���� 2
	c3 = operator+(c1, c2);

	//���� 3
	c3 = c1 + c2;

	/*
		���������
			1. ��������صı����Ǻ�������

	*/
	c3 = c1 - c2;
	cout << c3.a << endl;
	cout << c3.b << endl;

	system("pause");
	return 0;
}