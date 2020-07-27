#include <iostream>

using namespace std;

//构造函数默认是私有的
class A
{
public:
	A();
	~A();
	static int i;
private:

};

A::A()
{
}

A::~A()
{
}
//1 static关键字 遵守 派生类的访问机制
//2 这句话不是简单的变量赋值 更重要的是告诉c++编译器 分配内存 ，在继承类中用到了a， 不然会报错的
//3 A类中添加构造函数 默认是私有的 单例需要把构造函数变成私有的
int A::i = 200;


class B :private A
{
public:
	B();
	~B();

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
	A a;
	B b;
	system("pause");
	return 0;
}