#include<iostream>
using namespace std;

void maindy07001()
{
	const int c = 10;

	int a = 10;
	int& b = a;//b很像一个常量

	//a和b就是同一块内存空间的门牌号
	cout << a << endl;
	cout << b << endl;

	system("pause");
}

// 普通引用有自己的空间
struct Person
{
	char name[64];
	int age;

	int& a;//很像指针
	int& b;
};

void modifyA1(int* a)
{
	*a = 200;
}

void modifyA2(int& a)
{
	a = 300;
}


void maindy07002()
{
	//引用在c++中的内部实现是一个常量指针
	//Type& name <-->Type* const name

	cout << "sizeof(Person):" << sizeof(Person) << endl;
	int a = 10;

	//指向这个函数调用的时候，我们程序员不需要取a得地址
	modifyA1(&a);
	cout << a << endl;

	a = 10;
	//如果是指针 需要我们程序员手工的取实参的地址
	modifyA2(a);
	cout << a << endl;

	system("pause");
}

//间接赋值

void maindy07003()
{
	//1. 定义两个变量
	int a = 10;
	int* p = NULL;

	//2. 建立关联
	p = &a;

	//3. 间接修改
	*p = 20;
}

//引用在实现上，只不过是把：间接赋值成立的三个条件的后两步合二为一
//当我们使用引用语法是，我们不去关心编译器引用时怎么做的
//当我们分析奇怪的语法现象时，我们才去考虑c++编译器是怎么做的