#include <iostream>

using namespace std;

/*
	��Ԫ��  ��Ԫ����

	Ϊʲô�����Ԫ�����Ԫ������
	1. java----->class(�ֽ���) ====>������Ʒ��� class �ҵ���Ķ��� ֱ���޸����˽������
	������Ƴ�Ϊһ�ֱ�׼ jdk sun���ɱ�׼ jdk��API������������
	AOP
	2. cpp===>
	Ԥ���� ���� ���� ���� ..gcc -E //gcc -s
	gcc -o ..exe .c
	��������� ����
	3. ��Ԫ�����Ԫ����
	*/


class A
{
public:

	A();
	~A();
	friend class B;
private:
	int x;
};

A::A()
{
	x = 0;
}

A::~A()
{
}

class B
{
public:
	B();
	~B();

	void setObjA()
	{
		objA.x = 100;
	}

	int getObjA()
	{
		return objA.x;
	}

private:
	A objA;
};

B::B()
{
}

B::~B()
{
}


int maindy033()
{
	B b;
	b.setObjA();

	cout << b.getObjA() << endl;
	system("pause");

	return 0;
}