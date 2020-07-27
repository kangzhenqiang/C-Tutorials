
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Parent
{
public:
	Parent();
	~Parent();

	void print()
	{
		cout << "Parent" << endl;
	}
	int m_a;
private:
	
};

Parent::Parent()
{
	m_a = 0;
}

Parent::~Parent()
{
}

//成功 一次偶然的成功，比必然的失败更可怕
class  Child:public Parent
{
public:
	 Child();
	~ Child();

	void print()
	{
		cout << "Child" << endl;
	}

private:
	int m_b;
	int m_c;
};

 Child:: Child()
{
	 m_b = 0;
	 m_c = 0;
}

 Child::~ Child()
{
}

 /*
	子类和父类的指针步长不一样的问题
	多态时用父类指针指向子类对象 和 父类步长++，是两个不同概念
 */


int main()
{
	Child *c=NULL;
	Parent* p=NULL;

	Child arr[] = { Child(),Child(),Child() };

	c = arr;
	p = arr;

	c->print();
	p->print();

	c++;
	c->print();
	p++;
	p->print();

	c++;
	c->print();
	p++;
	p->print();

	system("pause");
	return 0;
}
