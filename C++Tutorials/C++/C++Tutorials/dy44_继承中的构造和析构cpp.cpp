#include <iostream>

using namespace std;


/*
	���ͼ���ԭ��
		���������Ե����������ʹ��
		����������ֱ�Ӹ�ֵ���������
		����������ֱ�ӳ�ʼ���������
		����������ֱ��ָ���������
		�������ÿ���ֱ�������������
	*/


class Parent
{
public:
	Parent();
	~Parent();

	void PrintP()
	{
		cout << "Parent" << endl;
	}

private:

};

Parent::Parent()
{
}

Parent::~Parent()
{
}

class Child :public Parent
{
public:
	Child();
	~Child();

	void PrintC()
	{
		cout << "Child" << endl;
	}

private:

};

Child::Child()
{
}

Child::~Child()
{
}

void howToPrint(Parent *p)
{
	p->PrintP();
}

void printP(Parent& p)
{
	p.PrintP();
}

int main()
{
	Parent p;
	Child c;
	p.PrintP();
	c.PrintC();
	c.PrintP();

	//1 ��ֵ������ԭ��
	//1-1����ָ�루���ã�ָ���������
	Parent* pp = NULL;
	pp = &c;
	pp->PrintP();

	//1-2 ָ������������
	howToPrint(&c);

	//1-3 ��������������
	printP(c);

	//2 �ڶ��κ���
	//�����ø�������ʼ��������� �������һ������ĸ���
	Parent p3 = c;


    system("pause");
	return 0;
}