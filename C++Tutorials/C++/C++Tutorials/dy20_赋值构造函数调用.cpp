#include <iostream>

using namespace std;

class TestTestTestTest
{
public:
	TestTestTestTest();
	TestTestTestTest(int a);
	TestTestTestTest(int a, int b);
	TestTestTestTest(const TestTestTestTest& obg);

	~TestTestTestTest();

private:
	int m_a;
	int m_b;
};

TestTestTestTest::TestTestTestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "我是无参构造函数" << endl;
}

TestTestTestTest::TestTestTestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "一个构造参数构造函数" << endl;
}

TestTestTestTest::TestTestTestTest(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "我是有参构造函数" << endl;
}

//C++提供一个拷贝构造机制
TestTestTestTest::TestTestTestTest(const TestTestTestTest& obg)
{
	m_a = obg.m_a;
	m_b = obg.m_b;
	cout << "我是赋值构造函数（copy构造函数）" << endl;
}

TestTestTestTest::~TestTestTestTest()
{
}

/*
	1、构造函数的调用方法 自动调用（按照规则调用）
	2、可以显示的初始化类的属性或其它资源
	*/

	/*
		为什么需要构造函数和析构函数？

		没有提供构造函数，c++编译器会自动给你提供一个默认的构造函数
		类没有提供构造函数 copy构造函数，c++编译器会自动给程序员提供一个 默认copy构造函数

		*/

int maindy020()
{
	//1
	TestTestTestTest t1;//调用无参数构造函数
	//2
	TestTestTestTest t2(5, 5);//调用有参构造函数 c++编译器自动调用构造函数
	TestTestTestTest t3 = (6, 6);//"=" c++对"="操作符 功能 增强 c++自动抵用构造函数
	TestTestTestTest t4 = 8;
	//3
	TestTestTestTest t5 = TestTestTestTest(10, 10);//直接调用构造函数 手动的调用构造函数 直接调用构造函数将创建一个匿名对象 难点是匿名对象的生命周期 什么时候去和留
	//4
	t1 = t4;//对象的初始化和对象的赋值 是两个不同的概念 等号操作不会调用赋值构造函数

	TestTestTestTest t6 = t2;//用t2来初始化t6

	TestTestTestTest t7(t2);//用t2来初始化t7

	//赋值操作和初始化操作是两个不同概念

	system("pause");
	return 0;
}