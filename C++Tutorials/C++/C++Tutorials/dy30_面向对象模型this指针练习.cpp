#include <iostream>

using namespace std;

class TTTTTT
{
public:
	TTTTTT(int a, int b);
	~TTTTTT();

	void printf()
	{
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}

	/*
		1. const写在什么位置没什么关系
		 const 写在什么位置没有关系
		 const void OpVar(int a,int b)
		 void  OpVar(int a,int b) const
		 void const OpVar(int a,int b)

		 2. const修饰的是谁？
			const修饰的是形参a吗？ 不是
			const修饰的属性this->a this->b
			const修饰的是this指针所指向的内存空间

		 3. this指针
			void OpVar(int a,int b) ===>void OpVar(TTTTTT * const this,int a,int b)
			void  OpVar(int a,int b) const ===>void OpVar(const TTTTTT * const this,int a,int b)
		 */


	void OpVar(int a, int b) const
	{
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}

private:
	int a;
	int b;
};

TTTTTT::TTTTTT(int a, int b)
{
	this->a = a;
	this->b = b;
}

TTTTTT::~TTTTTT()
{
}


int maindy030()
{
	TTTTTT t(4, 5);
	t.printf();
	system("pause");
	return 0;
}