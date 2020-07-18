#pragma once

#include<iostream>

using namespace std;

//c中没有字符串 字符串类（c风格的字符串）
//空串 ""
class MyString
{
	friend ostream& operator<<(ostream& out, MyString& obj);
	friend istream& operator>>(istream& in, MyString& obj);

public:
	//构造函数
	MyString(int len=0);
	MyString(const char* p);
	MyString(const MyString& obj);

	//析构函数
	~MyString();

	MyString& operator=(const char* p);
	MyString& operator=(const MyString& obj);
	char& operator[](size_t index);

	bool operator==(const char* p) const;
	bool operator==(const MyString& obj) const;
	bool operator!=(const char* p) const;
	bool operator!=(const MyString& obj) const;

	int operator>(const char* p) const;
	int operator<(const char* p) const;
	int operator>(const MyString& obj) const;
	int operator<(const MyString& obj) const;

	//把类的指针属性给露出来

	char* c_str()
	{
		return m_p;
	}

	const char* c_str_onlyRead()
	{
		return m_p;
	}

	int getLen()
	{
		return m_len;
	}

private:
	size_t m_len;
	char* m_p;
};
