#include<iostream>

#include"dy74_complex.h"

using namespace std;

template<typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
Complex<T>::~Complex()
{

}

template<typename T>
Complex<T> Complex<T>::operator+(Complex& complex)
{
	Complex<T> c(this->a + complex.a, this->b + complex.b);
	return c;
}

template<typename T>
void Complex<T>::PrintCom()
{
	cout << "a:" << a << "," << "b:" << b << endl;
}


/*
	严重性	代码	说明	项目	文件	行	禁止显示状态 错误	LNK2019
	无法解析的外部符号 "class std::basic_ostream<char,struct std::char_traits<char> > & __cdecl operator<<
	(class std::basic_ostream<char,struct std::char_traits<char> > &,class Complex<int> &)"
	(??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAV?$Complex@H@@@Z)，
	函数 main 中引用了该符号	C++Tutorials	E:\04 学习\C++\C++Tutorials\C++Tutorials\C++\C++Tutorials\dt73_符数类_所有函数都写在类的外部.obj	1

*/
//本质是 模板是两次编译生成的 第一次生成的函数头和第二次生成的函数头不一样
template<typename T>
ostream& operator<<(ostream& out, Complex<T>& c)
{
	out << c.a << endl;
	out << c.b << endl;
	return out;
}
