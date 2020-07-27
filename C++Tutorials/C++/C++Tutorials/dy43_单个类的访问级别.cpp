#include <iostream>

using namespace std;

//public 修饰的成员变量 方法 在类的外部都能使用
//protected 修饰成员变量 方法 ，在类的内部使用，在继承的子类中使用
//private 修饰的成员变量方法 只能在类的内部使用 不能在类的外部使用


/*
	c++中的继承方式会影响子类的对外访问属性
	public继承：父类成员在子类中保持原有访问级别
	private继承：父类成员在子类中变为private成员
	protected继承：
				  父类中的public成员会变成protected
				  父类中的protected成员依然为protected
				  父类中private成员依然为private

	派生类访问控制的结论
		1. protected 关键字 修饰的成员变量 和 成员函数，是为了在家族中使用，是为了继承
		2. 项目开发过程中一般都是public
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

//保护
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