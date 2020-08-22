
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
class SumAdd
{
public:
	T operator()(T t1, T t2)//二元对象
	{
		return t1 + t2;
	}
};

template<typename T>
void ShowElem(T t)
{
	cout << t << " ";
}

bool myCompare(const int& a, const int& b)
{
	return a < b;
}

int main()
{
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(3);

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	vector<int> v(10);
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 100;
		v[i] = temp;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "算法遍历：" << endl;
	for_each(v.begin(), v.end(), ShowElem<int>);

	cout << endl;

	sort(v.begin(), v.end(), myCompare);

	for_each(v.begin(), v.end(), ShowElem<int>);
	cout << endl;
	system("pause");
	return 0;
}
