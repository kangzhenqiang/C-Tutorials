
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


void PriorityQueue()
{
	priority_queue<int> q1;//默认情况下 是 最大值优先级队列
	priority_queue<int, vector<int>, less<int>>q2;//提前定义好预定义函数 谓词 最大值
	priority_queue<int, vector<int>, greater<int>>q3;//提前定义好预定义函数 谓词 最小值

	q1.push(52);
	q1.push(78);
	q1.push(50);

	cout << "q1队列头元素：" << q1.top() << endl;
	cout << "q1队列元素：" << q1.size()<< endl;

	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}

	cout << endl;


	q3.push(52);
	q3.push(78);
	q3.push(50);
	cout << "q3队列头元素：" << q3.top() << endl;
	cout << "q3队列元素：" << q3.size() << endl;

	while (!q3.empty())
	{
		cout << q3.top() << " ";
		q3.pop();
	}
	cout << endl;
}


int main()
{
	PriorityQueue();

	system("pause");
	return 0;
}
