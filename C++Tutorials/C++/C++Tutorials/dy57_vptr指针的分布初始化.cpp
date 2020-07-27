
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
	��̬����������������
		1��Ҫ�м̳�
		2���麯����д
		3������ָ��ָ���������
*/

class Parent
{
public:
	Parent(int a = 0);
	~Parent();

	virtual void Print()//1 ���ֽŵط� д��virtual�ؼ��� �����⴦�� //�麯����
	{
		cout << "Parent" << endl;
	}

private:
	int a;
};

Parent::Parent(int a)
{
	this->a = a;
	Print();
}

Parent::~Parent()
{
}

class Child :public Parent
{
public:
	Child(int a = 0, int b = 0);
	~Child();

	void Print()
	{
		cout << "Child" << endl;
	}

private:
	int b;
};

Child::Child(int a, int b) :Parent(a)
{
	this->b = b;
	Print();
}

Child::~Child()
{
}

void Play(Parent* base)
{
	base->Print();//��̬���� //2 ���ֽ�
	//��������ʱ ִ�������print���� ��������ִ�и����print����
	//c++��������������Ҫ������������� ���Ǹ������
	//���������������ֱ���vptrָ�룬===>�麯����===>��������ڵ�ַ
	//�ٰ󶨣����е�ʱ��c++��������ȥ�жϣ�
}


int main()
{

	//����һ�������������������У��ڸ��๹�캯���е����麯��print�ܷ�����

	Child c;//3 ���ֽ� ���ඨ�����ʱ c++���������ڶ��������һ��vptrָ��
	//1 Ҫ��ʼ��c1.vptr ָ�룬��ʼ���Ƿֲ�
	//2 ��ִ�и���Ĺ��캯��ʱ��c1.vptrָ������麯����
	//  ������Ĺ��캯��������Ϻ󣬻��c1.cotrָ��������麯����
	//3 ���ۣ������c1.vptrָ��ֲ����
	Parent p;
	Play(&c);
	Play(&p);

	system("pause");
	return 0;
}

