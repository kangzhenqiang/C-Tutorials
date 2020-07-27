#include <iostream>

using namespace std;

class Parent
{
public:
	Parent();
	~Parent();

	void Print()
	{
		cout << a << endl;
		cout << b << endl;
	}

protected:


private:
	int a;
	int b;
};

Parent::Parent()
{
	a = 0;
	b = 0;
}

Parent::~Parent()
{
}

//class Child : protected Parent
//class Child :private Parent
//项目中一般使用public关键字
class Child :public Parent
{
public:
	Child();
	~Child();

private:

};

Child::Child()
{
}

Child::~Child()
{
}

int main()
{
	Child c;
	c.Print();

	system("pause");
	return 0;
}