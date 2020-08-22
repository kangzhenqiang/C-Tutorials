
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
class IsDiv
{
public:
	IsDiv(const T& divisor)
	{
		this->divisor = divisor;
	}

	bool operator()(T& t)
	{
		return (t % divisor == 0);
	}

private:
	T divisor;
};



int main()
{
	vector<int> v;
	for (size_t i = 1; i < 40; i++)
	{
		v.push_back(i);

	}
	int a = 4;
	IsDiv<int> myDiv(a);

	vector<int>::iterator it;
	it = find_if(v.begin(), v.end(), IsDiv<int>(4));

	//Ҫ�㣺�����stl�㷨����ֵ�ǵ���������ν�ʣ�����������stl�㷨������Ҫ��
	if (it == v.end())
	{
		cout << "������û��Ԫ����4������Ԫ��" << endl;
	}
	else
	{
		cout << "�����е�һ����4������Ԫ�أ�" << *it << endl;
	}


	system("pause");
	return 0;
}
