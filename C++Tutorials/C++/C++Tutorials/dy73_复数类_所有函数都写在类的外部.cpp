#include<iostream>

using namespace std;

template<typename T>
class Complex;//��ǰ������

template<typename T>
Complex<T> MySub(Complex<T>& c1, Complex<T>& c2);//����ǰ������

/*
	��������ص�����д��
	���� << >> ֻ������Ԫ������������������ض�Ҫд�ɳ�Ա��������Ҫ������Ԫ����
	*/

template<typename T>
class Complex
{
	friend ostream& operator<< <T> (ostream& out, Complex<T>& c);

	friend Complex<T> MySub <T>(Complex<T>& c1, Complex<T>& c2);

public:
	Complex(T a, T b);
	~Complex();

	Complex operator+(Complex& complex);

	void PrintCom();


private:
	T a;
	T b;
};

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


/********************************������Ԫ����*************************************/

/*
	 ������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
	 ����	LNK2019	�޷��������ⲿ����
	 "class Complex<int> __cdecl MySub(class Complex<int> &,class Complex<int> &)"
	 (?MySub@@YA?AV?$Complex@H@@AEAV1@0@Z)������ main �������˸÷���	C++Tutorials
	 E:\04 ѧϰ\C++\C++Tutorials\C++Tutorials\C++\C++Tutorials\dt73_������_���к�����д������ⲿ.obj	1
	*/

template<typename T>
Complex<T> MySub(Complex<T>& c1, Complex<T>& c2)
{
	Complex<T> temp(c1.a - c2.a, c1.b - c2.b);
	return temp;
}
/********************************������Ԫ����*************************************/

int main()
{
	/*Complex c1(10, 20);
	Complex c2(10, 20);

	Complex c3 = c1 + c2;

	cout << c3 << endl;*/

	Complex<int> c1(10, 20);
	Complex<int> c2(20, 30);

	Complex<int> c3 = c1 + c2;

	cout << c3 << endl;

	//������Ԫ����
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	system("pause");
	return 0;
}
