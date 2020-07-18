#include <iostream>

using namespace std;

class TestTestTestTestTest
{
public:
	TestTestTestTestTest();
	TestTestTestTestTest(int a);
	TestTestTestTestTest(const TestTestTestTestTest& obj);
	~TestTestTestTestTest();

	void printf();

private:
	int m_a;
	int m_b;
};

TestTestTestTestTest::TestTestTestTestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "无参构造函数" << endl;
}

TestTestTestTestTest::TestTestTestTestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "我是有参构造函数" << endl;
}

TestTestTestTestTest::TestTestTestTestTest(const TestTestTestTestTest& obj)
{
	m_a = obj.m_a;
	m_b = obj.m_b;
	cout << "我是拷贝构造函数" << endl;
}

TestTestTestTestTest::~TestTestTestTestTest()
{
	cout << "我是析构函数 对生命周期结束时，会被c++编译器自动调用" << endl;
}

void TestTestTestTestTest::printf()
{
	cout << m_a << "" << m_b << endl;
}

//第一种和第二种
void objmain()
{
	TestTestTestTestTest t1;
	t1.printf();
	TestTestTestTestTest t2(6);
	t2.printf();
	TestTestTestTestTest t3 = t2;//会调用拷贝构造函数
	TestTestTestTestTest t4(t3);//会调用拷贝构造函数
}

//第三种
void print(TestTestTestTestTest t)
{

}

//第四种
TestTestTestTestTest printCopy()
{
	TestTestTestTestTest t(5);
	return t;
}

/*
	二个特殊默认构造函数：
		1. 默认无参构造函数
			当类中没有定义构造函数时，编译器默认提供一个无参构造函数，并且将其函数为空;
		2. 默认拷贝构造函数
			当类中没有定义拷贝构造函数时，编译器默认提供一个默认拷贝构造函数，简单的进行成员变量的值复制。
	*/

int maindy022()
{
	objmain();
	TestTestTestTestTest t = printCopy();
	TestTestTestTestTest t2;
	t2 = printCopy();
	system("pause");
	return 0;
}

