#include <iostream>

using namespace std;

/*
	引用
	1. 引用基础
	2. 引用作左值
	3. 指针的引用
	4. 常量引用
	*/

	/*
		在c++中新增了引用概念
		引用可以看作一个已定义变量的别名
		引用的语法：Type& name = var；
		*/

void maindy06001()
{
	//1. 引用基本概念
	//2. 属于c++编译器对c的扩展，不能用c语言的语法思考它
	int a = 10;

	//引用语法 Type& name = var;
	int& b = a;

	cout << a << endl;
	cout << b << endl;

	system("pause");
}

//基础类型的引用

int myswap01(int* a, int* b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
	return 0;
}

void maindy06002()
{
	int x, y;
	x = 10;
	y = 20;

	myswap01(&x, &y);
	cout << x << endl;
	cout << y << endl;
	system("pause");
}

// 函数参数引用
int myswap02(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
	return 0;
}

void maindy06003()
{
	int x, y;
	x = 10;
	y = 20;

	myswap02(x, y);
	cout << x << endl;
	cout << y << endl;
	system("pause");
}


//复杂数据类型的引用

struct  Student
{
	char name[64];
	int age;
};

void PrintStudent01(Student* student)
{
	cout << student->age << endl;
}

void PrintStudent02(Student& student)
{
	cout << student.age << endl;
}

void PrintStudent03(Student& student)
{
	cout << student.age << endl;
}

void maindy06004()
{
	Student s;
	s.age = 30;
	PrintStudent01(&s);
	//student是s的别名
	PrintStudent02(s);
	//student是形参，s copy一份数据给student
	PrintStudent03(s);
	system("pause");
	return;
}


/*
	引用的意义:
	1. 引用作为其变量的别名而存在，因此一些场合可以完全替代指针
	2. 引用相对于指针来说具有更好的可读性和实用性
*/