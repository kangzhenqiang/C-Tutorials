
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void printVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}


void myCopy()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);

	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());
	printVector(v2);
}

void myReplace()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);

	replace(v1.begin(), v1.end(), 11, 25);
	printVector(v1);

}

bool greaterThanFive(int & i)
{
	if (i>5)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void myReplaceIf()
{
	vector<int> v1;
	v1.push_back(5);
	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);

	replace_if(v1.begin(), v1.end(), greaterThanFive, 6);
	printVector(v1);

}


void mySwap()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	v2.push_back(8);
	v2.push_back(10);

	swap(v1, v2);

	printVector(v1);
	printVector(v2);
}

int main()
{
	myCopy();

	myReplace();

	myReplaceIf();

	mySwap();

	system("pause");
	return 0;
}
