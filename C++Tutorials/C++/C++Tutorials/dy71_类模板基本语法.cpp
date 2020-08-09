
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	��ģ��Ķ���
	��ģ���ʹ��
	��ģ������������
*/


template<typename T>
class A
{
public:
	A(T a) {
		this->a = a;
	}
	~A() {

	}

	void printfA()
	{
		cout << a << endl;
	}

private:
	T a;
};


//��ģ��������ʱ����Ҫ���廯ģ���࣬c++��������Ҫ֪��������������;�����ʲô���ӵģ�Ҫ֪��������ռ�ڴ�Ĵ�С�Ƕ��٣�ֻ���������͹̶���������֪����η����ڴ�
//��ģ����������ͨ��
class B:public A<int>
{
public:
	B(int a=10,int b=20):A<int>(a)
	{
		this->b = b;
	}
	~B() {

	}

	void printfB()
	{
		cout << b << endl;
	}

private:
	int b;
};


template<typename T>
class C:public A<T>
{
public:
	C(T c,T a) :A<T>(a)
	{
		this->c = c;
	}
	~C() {

	}

	void printfC();

private:
	T c;
};

template<typename T>
void C<T>::printfC()
{
	cout << c << endl;
}


//��ģ������������
void UseA(A<int>& a)
{
	a.printfA();
}

int main()
{
	A<int> a(100);//ģ����ʱ����� =====>��Ҫ���� �����
	a.printfA();

	UseA(a);

	B b(200, 300);
	b.printfA();
	b.printfA();

	C<int> c(100, 200);
	c.printfA();
	c.printfC();//ģ�庯��һ��Ҫ���ϵ��ò�������

	system("pause");
	return 0;
}

