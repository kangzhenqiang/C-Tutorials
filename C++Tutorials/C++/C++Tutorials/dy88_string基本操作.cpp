/*
*
* STL
	数据结构：研究结点和节点关系

	容器分离：
		序列式容器（Sequence Containers）每个元素都有固定位置--取决于插入时机和地点，和元素值无关，vector、deque、list

		关联式容器 （Associated Containers）元素位置取决与特定排序准则，和插入顺序无关，set、multiset、map、multimap

	算法经常使用的头文件 <algorithm>、<numeric>、<functional>

C++标准库

STL String string初始化 遍历 字符指针和string的转换 连续 查找和替换 截断 （区间删除）和插入 string反转和大小写转换
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include "dy88_string基本操作.h"

using namespace std;

int main()
{
	/*
	 string 和 char* 都可以用来表示字符串
	*/
	//string初始化
	StringInitilize();

	string str = "kangzhenqiang";//char * 转换为string

	//string遍历
	TraverseString(str);

	//字符指针和string之间转换
	printf("str:%s", str.c_str());//string 转换为 char * 

	//str的内容拷贝数据
	char buf[128] = { 0 };
	str.copy(buf, 3, 0);
	cout << "buf:" << buf << endl;//注意：只给拷贝三个字符，不会变成c风格的字符串

	//字符串连接
	StringAppend();

	//查找
	FindStr();

	//替换
	StingReplace();

	//区间删除
	StringDelete();

	//插入
	InsertString();

	//算法
	string s = "AAAAAA";
	//1. 函数的入口地址 2 函数对象 3预定义的函数对象
	transform(s.begin(), s.end(), s.begin(), tolower);
	cout << s << endl;

	transform(s.begin(), s.end(), s.begin(), toupper);
	cout << s << endl;

	system("pause");
	return 0;
}

void InsertString()
{
	string s = "kangzhneqiang";
	s.insert(0, "wangjing");
	s.insert(s.length(), "jingjing");
	cout << s << endl;
}

void StringDelete()
{
	string se = "Hello World";

	string::iterator it = find(se.begin(), se.end(), 'l');
	se.erase(it);
	//se.erase(0, 5);
	se.erase(se.begin(), se.end());


	cout << se << endl;
}

void StingReplace()
{
	string strReplace = "kangzhenqiang";

	strReplace.replace(0, 1, "K");

	cout << strReplace << endl;
}

void FindStr()
{
	string name = "wo shi kangzhenqiang";

	size_t index = name.find("kang", 0);

	cout << index << endl;
}

void StringAppend()
{
	//string 字符串连接

	string s1 = "aaaa";
	string s2 = "bbbb";

	s1 = s1 + s2;
	cout << s1 << endl;

	string s3 = "cccc";
	s2.append(s3);
	cout << s2 << endl;
}

void TraverseString(std::string& str)
{
	//1 数组方式
	for (size_t i = 0; i < str.length(); i++)
	{
		cout << str[i] << endl;//出现错误不抛出异常，导致程序中断
	}

	//2 迭代器

	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << endl;
	}

	//3 at和[]区别，可以抛出异常
	try
	{
		for (size_t i = 0; i < str.length() + 3; i++)
		{
			cout << str.at(i) << endl;
		}
	}
	catch (const std::exception&)
	{

	}
}

void StringInitilize()
{
	//string 类初始化
	string str = "kangzhenqiang";
	string strstr("wangjing");
	string strstrstr = str;
	string strstrstrstr(10, 'k');

	cout << str << endl;
	cout << strstr << endl;
	cout << strstrstr << endl;
	cout << strstrstrstr << endl;
}
