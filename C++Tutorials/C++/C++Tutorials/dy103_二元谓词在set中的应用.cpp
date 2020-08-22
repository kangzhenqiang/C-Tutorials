
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"

using namespace std;


//struct CompareNoCase
//{
//public:
//	bool operator()(const string& str1, const string& str2)
//	{
//		string tempStr1;
//		tempStr1.resize(str1.size());
//		transform(str1.begin(), str1.end(), tempStr1.begin(), tolower);//预定义函数对象
//
//		string tempStr2;
//		tempStr2.resize(str2.size());
//		transform(str2.begin(), str2.end(), tempStr2.begin(), tolower);//预定义函数对象
//
//		return (tempStr1 < tempStr2);//从小到大排序
//	}
//};

class CompareNoCase
{
public:
	bool operator()(const string& str1, const string& str2) const
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower); //预定义函数对象 

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower); //预定义函数对象 

		return (str1_ < str2_); // 从小到大进行排序
	}
};

int main()
{
	/*set<string> set1;
	set1.insert("aaaaa");
	set1.insert("bbbbb");
	set1.insert("ccccc");

	set<string>::iterator it = set1.find("bbbbb");
	if (it == set1.end())
	{
		cout << "未查找到" << endl;
	}
	else
	{
		cout << *it << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("aaaaa");
	set2.insert("bbbbb");
	set2.insert("ccccc");
	set<string, CompareNoCase>::iterator it2 = set2.find("aaaaA");

	if (it2 == set2.end())
	{
		cout << "未查找到" << endl;
	}
	else
	{
		cout << *it2 << endl;
	}*/

	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string, CompareNoCase>::iterator it2 = set2.find("aAa");
	if (it2 == set2.end())
	{
		cout << " 没有 查找到 aaa " << endl;
	}
	else
	{
		cout << " 不区分大小的的查找  查找到 aaa " << endl;
	}

	system("pause");
	return 0;
}
