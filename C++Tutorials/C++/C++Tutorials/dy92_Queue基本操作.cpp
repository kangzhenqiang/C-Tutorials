
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void QueueOpe()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << "队列的元素：" << q.front() << endl;
	cout << "队列的大小：" << q.size() << endl;

	while (!q.empty())
	{
		cout << q.front() << " " << endl;
		q.pop();
	}
}


int main()
{
	QueueOpe();

	system("pause");
	return 0;
}
