
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


void PrintDeque(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void DequeOperate()
{
	deque<int> d;
	d.push_back(1);

	d.push_back(3);
	d.push_back(5);

	d.push_front(3);
	d.push_front(5);

	PrintDeque(d);

	cout << "头部元素：" << d.front() << endl;

	cout << "尾部元素：" << d.back() << endl;

	d.pop_back();
	d.pop_front();

	PrintDeque(d);

	//查找1在数组下标的值
	deque<int>::iterator it = find(d.begin(), d.end(), 1);
	if (it!=d.end())
	{
		cout << "1数组下标是：" << distance(d.begin(), it) << endl;
	}
	else
	{
		cout << "没有找到值为1的元素" << endl;
	}

}

int main()
{
	DequeOperate();

	system("pause");
	return 0;
}
