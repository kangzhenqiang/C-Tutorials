
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
}

Parent::~Parent()
{
}

class ParentParent
{
public:
	ParentParent(int a = 0);
	~ParentParent();

	void Print()//1 ���ֽŵط� д��virtual�ؼ��� �����⴦�� //�麯����
	{
		cout << "Parent" << endl;
	}

private:
	int a;
};

ParentParent::ParentParent(int a)
{
	this->a = a;
}

ParentParent::~ParentParent()
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
	Parent p;
	ParentParent pp;
	cout << sizeof(p) << endl;
	cout << sizeof(pp) << endl;
	system("pause");
	return 0;
}
