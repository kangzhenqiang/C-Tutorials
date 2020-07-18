#include <iostream>

using namespace std;

class Test
{
public:
	Test(int a, int b);
	~Test();

	Test TestAdd(Test& test);
	Test& TestAddAdd(Test& test);

	void Printf();
	int a;
	int b;
private:

};

Test::Test(int a, int b)
{
	this->a = a;
	this->b = b;
}

Test::~Test()
{
}

Test Test::TestAdd(Test& test)
{
	Test temp(this->a + test.a, this->b + test.b);
	return temp;
}

//返回一个引用 相当于返回自身
//返回t1元素
Test& Test::TestAddAdd(Test& test)
{
	// TODO: 在此处插入 return 语句
	this->a = this->a + test.a;
	this->b = this->b + test.b;
	return *this;//把*(&t1)又回到了t1
}

void Test::Printf()
{
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}

/*
	全局函数转成成员函数少了一个参数
	成员函数转成全局函数多了一个参数
	*/

void Printf(Test* pt)
{
	cout << "a:" << pt->a << endl;
	cout << "b:" << pt->b << endl;
}



//全局函数转换为成员函数
Test TestAdd(Test& t1, Test& t2)
{
	Test temp(t1.a + t2.a, t1.b + t2.b);
	return temp;
}


int maindy031001()
{
	Test t1(1, 1);
	Test t2(2, 3);

	//t1 + t2

	Test t3 = TestAdd(t1, t2);
	t3.Printf();

	//先把测试案例写出来
	{
		Test t4 = t1.TestAdd(t2);
		t4.Printf();

		Test t5(0, 0);
		t5 = t1.TestAdd(t2);
		t5.Printf();
	}

	return 0;
}


int maindy031002()
{
	Test t1(1, 1);
	Test t2(2, 3);

	t1.TestAddAdd(t2);
	t1.Printf();

	return 0;
}