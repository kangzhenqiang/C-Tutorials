#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "MyString.h"

using namespace std;

int main()
{
	MyString s1;
	MyString s2("kangzhenqiang");
	MyString s3 = s2;
	MyString s4;

	s4 = s2;
	s4 = "wangjing";

	/*s4[0] = 'W';
	
	cout << s4[0] << endl;
	cout << s4 << endl;*/

	if (s4=="wangjing")
	{
		cout << "相等" << endl;
	}

	if (s4!="kang")
	{
		cout << "不相等" << endl;
	}

	if (s3==s2)
	{
		cout << "相等" << endl;
	}
	if (s1!=s4)
	{
		cout << "不相等" << endl;
	}
	MyString a("aaaa");
	MyString b("bbbb");

	int tag = (a < b);

	if (tag>0)
	{
		cout << tag << endl;
	}

	strcpy(a.c_str(), "ccc");//MFC
	cout << a << endl;

	cout << "请输入字符串" << endl;

	cin >> a;
	cout << a<<endl;

	system("pause");
	return 0;
}