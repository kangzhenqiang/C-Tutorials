
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//让类型参数化，方便程序员编码
template<typename T>
void myswap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	cout << "我是模板函数" << endl;
}

//普通函数
void myswap(int a, char c)
{
	cout << "a:" << a << " " << "c:" << c;
	cout << "我是普通函数" << endl;
}



int main()
{
	int a = 10;
	int b = 20;
	myswap<int>(a, b);//调用函数模板（本质：类型参数化），将进行严格的类型进行匹配，不会进行自动类型转换
	myswap(a, b);

	myswap(a, 'k');//普通函数类型调用：可以进行隐式的类型转换

	system("pause");
	return 0;
}
