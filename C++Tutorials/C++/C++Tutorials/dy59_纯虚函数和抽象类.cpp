
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<math.h>

using namespace std;

//����ӿڱ�̣�����Ԥ�ȶ���õ�һ�׽ӿڣ�
//����...ģ�黮��

class Figure//������
{
public:
	Figure();
	~Figure();
	//�ṩһ��ͬһ�Ľ��棨�ӿڣ���������ʹ�ã����������ȥʵ��
	virtual int getArea() = 0;//���麯��
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
	base->getArea();//�ᷢ����̬
}


int main()
{
	//Figer f;//�����಻��ʵ����

	Circle c(10);
	Play(&c);

	Squre s(10, 10);
	Play(&s);


	system("pause");
	return 0;
}
