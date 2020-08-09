
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	类模板的定义
	类模板的使用
	类模板做函数参数
*/


template<typename T>
class A
{
public:
	A(T a) {
		this->a = a;
	}
	~A() {

	}

	void printfA()
	{
		cout << a << endl;
	}

private:
	T a;
};


//从模板类派生时，需要具体化模板类，c++编译器需要知道父类的数据类型具体是什么样子的，要知道父类所占内存的大小是多少，只有数据类型固定下来，才知道如何分配内存
//从模板类派生普通类
class B:public A<int>
{
public:
	B(int a=10,int b=20):A<int>(a)
	{
		this->b = b;
	}
	~B() {

	}

	void printfB()
	{
		cout << b << endl;
	}

private:
	int b;
};


template<typename T>
class C:public A<T>
{
public:
	C(T c,T a) :A<T>(a)
	{
		this->c = c;
	}
	~C() {

	}

	void printfC();

private:
	T c;
};

template<typename T>
void C<T>::printfC()
{
	cout << c << endl;
}


//类模板做函数参数
void UseA(A<int>& a)
{
	a.printfA();
}

int main()
{
	A<int> a(100);//模板类时抽象的 =====>需要进行 类具体
	a.printfA();

	UseA(a);

	B b(200, 300);
	b.printfA();
	b.printfA();

	C<int> c(100, 200);
	c.printfA();
	c.printfC();//模板函数一般要加上调用参数类型

	system("pause");
	return 0;
}

