#include<iostream>

using namespace std;

//先 调用父类构造函数 在调用子类构造函数
//先 调用子类析构函数 在调用父类析构函数

class Parent
{
public:
	Parent();
	~Parent();
	Parent(int a, int b);

private:
	int m_a;
	int m_b;
};

Parent::Parent()
{
	m_a = 0;
	m_b = 0;
}

Parent::~Parent()
{
	cout << "父类析构函数" << endl;
}

Parent::Parent(int a, int b)
{
	m_a = a;
	m_b = b;
}


class Child :public Parent
{
public:
	Child();
	~Child();
	Child(int a, int b, int c) :Parent(a, b) {
		m_c = c;
	}


private:
	int m_c;
};

Child::Child()
{
	m_c = 0;
}

Child::~Child()
{
	cout << "子类析构函数" << endl;
}


void printParent()
{
	Child c(1, 2, 5);
}

int main()
{
	
	printParent();

	system("pause");
	return 0;
}