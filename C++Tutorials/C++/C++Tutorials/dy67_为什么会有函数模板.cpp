
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	函数业务逻辑一样
	函数的参数类型不一样

	*/

void myswapInt(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswapChar(char& a, char& b)
{
	char c = 0;
	c = a;
	a = b;
	b = c;
}

/*
	让类型参数化，方便程序要进行编码 ===>泛型编程
	*/

//template告诉编译器 我要开始泛型编程了，不要随便报错
template<typename T>
void myswap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

/*
	函数模板调用
	显示类型调用
	自动类型调用
	*/
int main()
{
	//显示调用
	int a = 10;
	int b = 5;
	myswap<int>(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	//自动类型推到
	char x = 'x';
	char y = 'y';
	myswap(x, y);
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;

	system("pause");
	return 0;
}


int maindy067_001()
{
	{
		int a = 10;
		int b = 20;
		myswapInt(a, b);
		printf("a:%d,b:%d\n", a, b);
	}

	{
		char a = 'k';
		char b = 'n';
		myswapChar(a, b);
		printf("a:%c,b:%c\n", a, b);
	}

	system("pause");
	return 0;
}
