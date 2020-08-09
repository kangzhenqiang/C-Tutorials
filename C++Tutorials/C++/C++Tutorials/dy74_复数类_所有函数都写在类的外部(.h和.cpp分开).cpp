#include <iostream>

#include"dy74_complex.hpp" //.hpp 使用模板
using namespace std;


/*
	尽量使用第一种和第三种，把模板方法写在一个.h文件中，要包含.cpp
	*/

int main()
{
	Complex<int> c1(10, 20);
	Complex<int> c2(20, 30);

	Complex<int> c3 = c1 + c2;

	cout << c3 << endl;

	system("pause");
	return 0;
}