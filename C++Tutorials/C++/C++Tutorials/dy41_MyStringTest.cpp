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
		cout << "���" << endl;
	}

	if (s4!="kang")
	{
		cout << "�����" << endl;
	}

	if (s3==s2)
	{
		cout << "���" << endl;
	}
	if (s1!=s4)
	{
		cout << "�����" << endl;
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

	cout << "�������ַ���" << endl;

	cin >> a;
	cout << a<<endl;

	system("pause");
	return 0;
}