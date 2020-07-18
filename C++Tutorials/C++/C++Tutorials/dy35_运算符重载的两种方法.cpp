#include <iostream>

using namespace std;

/*
	ȫ�ֺ��������Ա��������ʵ����������ز��裺
		1. Ҫ���ϲ�����������һ��������д����������
		2. ���ݲ����棬д����������
		2. ����ҵ�����ƺ�������ֵ���������Ƿ������á�����ָ�롢����Ԫ�أ�����ʵ�ֺ���ҵ��
*/


class Complex
{
public:
	Complex(int a = 0, int b = 0);
	~Complex();
	
	//ʹ��ȫ�ֺ��� ʵ����+��������� ������Ԫ����ʵ��˽���ֶη���
	friend Complex operator+(Complex& obj1, Complex& obj2);

	friend Complex& operator++(Complex& obj);

	friend Complex operator++(Complex& obj, int);

	//��Ա��������
	Complex operator- (Complex& obj);
	//ǰ��--
	Complex& operator--();
	//����--
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
	// TODO: �ڴ˴����� return ���
	this->a--;
	this->b--;
	return *this;
}

//ȫ�ֺ��� ʵ����+���������
Complex operator+(Complex& obj1, Complex& obj2)
{
	Complex temp(obj1.a - obj2.a, obj1.b - obj2.b);
	return Complex();
}

//����ǰ��++
Complex& operator++(Complex& obj)
{
	obj.a++;
	obj.b++;
	return obj;
}

//���غ���++
Complex operator++(Complex& obj,int)
{
	//��ʹ�� ����obj++
	Complex tem = obj;
	obj.a++;
	obj.b++;
	return tem;
}

int maindy035()
{
	Complex c1(1, 1), c2(2, 2);
	//1 ȫ�ֺ����� ʵ�� + ���������
	// Complex opreatr+(Complex &c1,Complex &c2)

	//2 ��Ա������ ʵ�� + ���������
	//c1.operator+(c2)
	//Complex opreator+(Complex &c2)

	Complex c = c1 - c2;

	//ǰ��++������ ��ȫ�ֺ���ʵ��

	++c;
	c.printf();

	--c;
	c.printf();

	//ʹ�ú��ò�����

	c++;
	c.printf();

	//�ó�Ա��������ʵ�ֺ���--
	c--;
	c.printf();

	
	system("pause");
	return 0;
}