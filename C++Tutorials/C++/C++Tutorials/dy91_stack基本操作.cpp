
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void StackOperate()
{
	stack<int> s;
	//»Î’ª

	for (size_t i = 0; i < 10; i++)
	{
		s.push(i + 1);
	}
	//≥ˆ’ª
	while (!s.empty())
	{
		int temp = s.top();
		cout << temp << " " << endl;
		s.pop();
	}
	cout << endl;
}

int main()
{
	StackOperate();

	system("pause");
	return 0;
}


