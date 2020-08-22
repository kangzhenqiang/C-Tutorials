
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;


void MutiSet()
{
	multiset<int> sett;
	int temp = 0;

	cout << "请输入multiset集合的值：" << endl;
	cin >> temp;

	while (temp!=0)
	{
		sett.insert(temp);
		cin >> temp;
	}

	for (multiset<int>::iterator it = sett.begin(); it != sett.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	while (!sett.empty())
	{
		cout << *sett.begin() << " ";
		sett.erase(sett.begin());
	}
	cout << endl;
}


int main()
{
	MutiSet();
	system("pause");
	return 0;
}
