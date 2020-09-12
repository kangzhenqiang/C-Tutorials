
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void Adiacent_Find()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(15);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	int index = distance(v.begin(), it);
	cout << index << endl;
}

void Binary_Seach()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//有序 二分法
	bool find = binary_search(v.begin(), v.end(), 3);
	if (find)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

void MyCount()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	int myCount = count(v.begin(), v.end(), 3);

	cout << myCount << endl;
}

bool greaterThree(int i)
{
	if (i>3)
	{
		return true;	 
	}
	else
	{
		return false;
	}
}

void countIf()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	int myCount= count_if(v.begin(), v.end(), greaterThree);
	cout << myCount << endl;
}

void myFind()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator it = find(v.begin(), v.end(), 4);
	cout << *it << endl;

	vector<int>::iterator itif = find_if(v.begin(), v.end(), greaterThree);
	cout << *itif << endl;

}


int main()
{
	//Adiacent_Find();
	//Binary_Seach();
	//MyCount();
	//countIf();
	//myFind();

	system("pause");
	return 0;
}
