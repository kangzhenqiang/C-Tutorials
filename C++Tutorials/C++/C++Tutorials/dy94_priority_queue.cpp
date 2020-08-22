
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


void PriorityQueue()
{
	priority_queue<int> q1;//Ĭ������� �� ���ֵ���ȼ�����
	priority_queue<int, vector<int>, less<int>>q2;//��ǰ�����Ԥ���庯�� ν�� ���ֵ
	priority_queue<int, vector<int>, greater<int>>q3;//��ǰ�����Ԥ���庯�� ν�� ��Сֵ

	q1.push(52);
	q1.push(78);
	q1.push(50);

	cout << "q1����ͷԪ�أ�" << q1.top() << endl;
	cout << "q1����Ԫ�أ�" << q1.size()<< endl;

	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}

	cout << endl;


	q3.push(52);
	q3.push(78);
	q3.push(50);
	cout << "q3����ͷԪ�أ�" << q3.top() << endl;
	cout << "q3����Ԫ�أ�" << q3.size() << endl;

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
