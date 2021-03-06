#include <iostream>

using namespace std;

class TestTest
{
public:
	TestTest();
	TestTest(int a);
	TestTest(int a, int b);
	TestTest(const TestTest& obg);

	~TestTest();

private:
	int m_a;
	int m_b;
};

TestTest::TestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "我是无参构造函数" << endl;
}

TestTest::TestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "一个构造参数构造函数" << endl;
}

TestTest::TestTest(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "我是有参构造函数" << endl;
}

TestTest::TestTest(const TestTest& obg)
{
	m_a = 1;
	m_b = 2;
	cout << "我是赋值构造函数（copy构造函数）" << endl;
}

TestTest::~TestTest()
{
}

/*
	1、构造函数的调用方法 自动调用（按照规则调用）
	2、可以显示的初始化类的属性或其它资源
	*/

/*
	为什么需要构造函数和析构函数？


	*/

int maindy018()
{
	//1
	TestTest t1;//调用无参数构造函数
	//2
	TestTest t2(5, 5);//调用有参构造函数 c++编译器自动调用构造函数
	TestTest t3 = (6, 6);//"=" c++对"="操作符 功能 增强 c++自动抵用构造函数
	TestTest t4 = 8;
	//3
	TestTest t5 = TestTest(10, 10);//直接调用构造函数 手动的调用构造函数 直接调用构造函数将创建一个匿名对象 难点是匿名对象的生命周期 什么时候去和留
	//4
	t1 = t4;//对象的初始化和对象的赋值 是两个不同的概念
	system("pause");
	return 0;
}