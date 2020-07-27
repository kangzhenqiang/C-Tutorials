#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a);
	~Parent();
	virtual  void print()
	{
		cout << "���ࣺ" << m_a << endl;
	}

private:
	int m_a;
};

Parent::Parent(int a)
{
	m_a = a;
}

Parent::~Parent()
{
}

class  Child :public Parent
{
public:
	Child(int b);
	~Child();
	virtual void print()//virtual����д�ˣ������д �ɲ�д
	{
		cout << "���ࣺ" << m_b << endl;
	}
private:
	int m_b;
};

Child::Child(int b) :Parent(10)
{
	m_b = b;
}

Child::~Child()
{
}

int main()
{

	Parent* base = NULL;
	Parent parent(5);
	Child child(1);
	base = &parent;
	base->print();
	base = &child;
	base->print();

	{
		Parent& base1=parent;
		base1.print();

		Parent& base2 = child;
		base2.print();
	}

	system("pause");
	return 0;
}