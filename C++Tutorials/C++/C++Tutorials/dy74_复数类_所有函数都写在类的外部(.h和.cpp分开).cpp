#include <iostream>

#include"dy74_complex.hpp" //.hpp ʹ��ģ��
using namespace std;


/*
	����ʹ�õ�һ�ֺ͵����֣���ģ�巽��д��һ��.h�ļ��У�Ҫ����.cpp
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