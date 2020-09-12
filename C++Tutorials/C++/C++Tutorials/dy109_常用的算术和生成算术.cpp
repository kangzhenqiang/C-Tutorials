
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;


void myAccumulate()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	int sum = accumulate(v.begin(),v.end(),100);

	cout << sum << endl;
}

void myFill()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	fill(v.begin(), v.end(), 8);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	myAccumulate();
	myFill();

	system("pause");
	return 0;
}
