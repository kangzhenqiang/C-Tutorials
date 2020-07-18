#include <iostream>

using namespace std;

class AA
{
public:
	AA(int a,int b);
	~AA();
	/*
		1. 声明的位置和public private没有关系
		2. 函数modifyA 是 类的好朋友
	*/
	friend void modifyAA(AA* p);

	int GetA()
	{
		return this->a;
	}
private:
	int a;
	int b;
};

AA::AA(int a,int b)
{
	this->a = a;
	this->b = b;
}

AA::~AA()
{
}

//通过友员函数修改类的私有属性
void modifyAA(AA* p)
{
	p->a = 100;
}


int maindy032()
{
	AA a(5, 5);
	modifyAA(&a);
	cout<<a.GetA()<<endl;
	system("pause");
	return 0;
}

