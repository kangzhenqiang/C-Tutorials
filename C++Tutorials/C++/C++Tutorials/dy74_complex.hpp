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
	������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬ ����	LNK2019
	�޷��������ⲿ���� "class std::basic_ostream<char,struct std::char_traits<char> > & __cdecl operator<<
	(class std::basic_ostream<char,struct std::char_traits<char> > &,class Complex<int> &)"
	(??6@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AEAV01@AEAV?$Complex@H@@@Z)��
	���� main �������˸÷���	C++Tutorials	E:\04 ѧϰ\C++\C++Tutorials\C++Tutorials\C++\C++Tutorials\dt73_������_���к�����д������ⲿ.obj	1

*/
//������ ģ�������α������ɵ� ��һ�����ɵĺ���ͷ�͵ڶ������ɵĺ���ͷ��һ��
template<typename T>
ostream& operator<<(ostream& out, Complex<T>& c)
{
	out << c.a << endl;
	out << c.b << endl;
	return out;
}
