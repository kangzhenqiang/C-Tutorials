
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
	常用集合算法
	*/

void printVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}


void myUnion()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	printVector(v3);

}

void myIntersection()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	printVector(v3);
}

void myDifference()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	printVector(v3);
}

int main()
{
	myUnion();
	myIntersection();
	myDifference();

	system("pause");
	return 0;
}
