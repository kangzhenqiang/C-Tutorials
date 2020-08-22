
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

	//要点：分清楚stl算法返回值是迭代器还是谓词（函数对象）是stl算法入门重要点
	if (it == v.end())
	{
		cout << "容器中没有元素是4倍数的元素" << endl;
	}
	else
	{
		cout << "容器中第一个被4整除的元素：" << *it << endl;
	}


	system("pause");
	return 0;
}
