#include<iostream>

using namespace std;

template<typename T>
class Complex;//类前置申明

template<typename T>
Complex<T> MySub(Complex<T>& c1, Complex<T>& c2);//函数前置申明

/*
	运算符重载的正规写法
	重载 << >> 只能用友元函数，其它运算符重载都要写成成员函数，不要滥用友元函数
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


/********************************滥用友元函数*************************************/

/*
	 严重性	代码	说明	项目	文件	行	禁止显示状态
	 错误	LNK2019	无法解析的外部符号
	 "class Complex<int> __cdecl MySub(class Complex<int> &,class Complex<int> &)"
	 (?MySub@@YA?AV?$Complex@H@@AEAV1@0@Z)，函数 main 中引用了该符号	C++Tutorials
	 E:\04 学习\C++\C++Tutorials\C++Tutorials\C++\C++Tutorials\dt73_符数类_所有函数都写在类的外部.obj	1
	*/

template<typename T>
Complex<T> MySub(Complex<T>& c1, Complex<T>& c2)
{
	Complex<T> temp(c1.a - c2.a, c1.b - c2.b);
	return temp;
}
/********************************滥用友元函数*************************************/

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

	//滥用友元函数
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
