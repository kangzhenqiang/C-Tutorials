#include <iostream>

using namespace std;

//public ���εĳ�Ա���� ���� ������ⲿ����ʹ��
//protected ���γ�Ա���� ���� ��������ڲ�ʹ�ã��ڼ̳е�������ʹ��
//private ���εĳ�Ա�������� ֻ��������ڲ�ʹ�� ����������ⲿʹ��


/*
	c++�еļ̳з�ʽ��Ӱ������Ķ����������
	public�̳У������Ա�������б���ԭ�з��ʼ���
	private�̳У������Ա�������б�Ϊprivate��Ա
	protected�̳У�
				  �����е�public��Ա����protected
				  �����е�protected��Ա��ȻΪprotected
				  ������private��Ա��ȻΪprivate

	��������ʿ��ƵĽ���
		1. protected �ؼ��� ���εĳ�Ա���� �� ��Ա��������Ϊ���ڼ�����ʹ�ã���Ϊ�˼̳�
		2. ��Ŀ����������һ�㶼��public
	*/

class Parent
{
public:
	Parent();
	~Parent();

	int a;
	void Print()
	{
		cout << "a=" << a << endl;
	}

protected:
	int b;

private:
	int c;
};

Parent::Parent()
{
	a = 0;
	b = 0;
	c = 0;
}

Parent::~Parent()
{
}

/*
class Child :public Parent
{
public:
	Child();
	~Child();

private:

};

Child::Child()
{
	a = 1;//ok
	b = 1;//ok
	//c = 1;//error
}

Child::~Child()
{
}
*/

/*
class Child :private Parent
{
public:
	Child();
	~Child();

private:

};

Child::Child()
{
	a = 1;//ok
	b = 1;//ok
	//c = 1;//error
}

Child::~Child()
{
}
*/

//����
class Child :protected Parent
{
public:
	Child();
	~Child();

private:

};

Child::Child()
{
	a = 1;//ok
	b = 1;//ok
	//c = 1;//error
}

Child::~Child()
{
}

int main()
{
	Child c;
	//c.Print();

	system("pause");
	return 0;
}