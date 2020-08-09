
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

template<typename T>
class AA
{
public:
	AA();
	~AA();

	static T m_a;

private:

};
template<typename T>
AA<T>::AA()
{
}

template<typename T>
AA<T>::~AA()
{
}

template<typename T>
T AA<T>::m_a = 0;

int main()
{
	AA<int> a1, a2, a3;
	a1.m_a = 10;
	a1.m_a++;
	a2.m_a++;

	cout << a1.m_a << endl;

	AA<double> b1, b2, b3;
	b1.m_a = 50.0;
	b2.m_a++;
	b3.m_a++;

	cout << b1.m_a << endl;

	/*
		m_a 应该是 每一种类型的类 使用自己
		*/

	system("pause");
	return 0;
}
