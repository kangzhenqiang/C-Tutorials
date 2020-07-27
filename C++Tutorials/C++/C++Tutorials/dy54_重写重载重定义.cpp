
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*函数重载
	重载必须在同一个类中
	子类无法重载父类的函数，父类同名函数将被名称覆盖
	重载是在编译期间根据参数类型和个数决定函数调用
	*/

/*函数重写
	必须发生于父类与子类之间
	并且父类与子类中的函数必须有完全相同的原型
	使用virtual声明只够能够产生多态（如果不适用virtual，那叫重定义）
	多态是在运行期间根据具体对象的类型决定函数调用
*/

/*
	重写分为2类
	1、虚函数重写 将发生多态
	2、非虚函数重写 （重定义）
*/


class Parent
{
public:
	Parent();
	~Parent();

	virtual void func()
	{
		cout << "func" << endl;
	}

	virtual void func(int i)
	{
		cout << "func(int i)" << endl;
	}

	virtual void func(string s)
	{
		cout << "func(string s)" << endl;
	}

private:

};

Parent::Parent()
{
}

Parent::~Parent()
{
}

class B :public Parent
{
public:
	B();
	~B();

	virtual void func()
	{
		cout << "B::func" << endl;
	}

private:

};

B::B()
{
}

B::~B()
{
}


int main()
{
	B B;
	B.func();//子类无法重载父类的函数，父类同名函数将被名称覆盖
	B.Parent::func(1);

	//1 c++编译器 看到func名字，因为类中func名字已经存在了（名称覆盖），所以c++编译器不会去找父类的4个参数func函数
	//2 c++编译器 只会在子类中，查找func函数，找到了两个func，一个是2个参数的，一个是3个参数的
	//3 c++编译器 开始报错.... error c2661："B::func" 没有重载函数接收4个参数 

	system("pause");
	return 0;
}
