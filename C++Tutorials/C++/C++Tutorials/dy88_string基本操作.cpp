/*
*
* STL
	���ݽṹ���о����ͽڵ��ϵ

	�������룺
		����ʽ������Sequence Containers��ÿ��Ԫ�ض��й̶�λ��--ȡ���ڲ���ʱ���͵ص㣬��Ԫ��ֵ�޹أ�vector��deque��list

		����ʽ���� ��Associated Containers��Ԫ��λ��ȡ�����ض�����׼�򣬺Ͳ���˳���޹أ�set��multiset��map��multimap

	�㷨����ʹ�õ�ͷ�ļ� <algorithm>��<numeric>��<functional>

C++��׼��

STL String string��ʼ�� ���� �ַ�ָ���string��ת�� ���� ���Һ��滻 �ض� ������ɾ�����Ͳ��� string��ת�ʹ�Сдת��
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include "dy88_string��������.h"

using namespace std;

int main()
{
	/*
	 string �� char* ������������ʾ�ַ���
	*/
	//string��ʼ��
	StringInitilize();

	string str = "kangzhenqiang";//char * ת��Ϊstring

	//string����
	TraverseString(str);

	//�ַ�ָ���string֮��ת��
	printf("str:%s", str.c_str());//string ת��Ϊ char * 

	//str�����ݿ�������
	char buf[128] = { 0 };
	str.copy(buf, 3, 0);
	cout << "buf:" << buf << endl;//ע�⣺ֻ�����������ַ���������c�����ַ���

	//�ַ�������
	StringAppend();

	//����
	FindStr();

	//�滻
	StingReplace();

	//����ɾ��
	StringDelete();

	//����
	InsertString();

	//�㷨
	string s = "AAAAAA";
	//1. ��������ڵ�ַ 2 �������� 3Ԥ����ĺ�������
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
	//string �ַ�������

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
	//1 ���鷽ʽ
	for (size_t i = 0; i < str.length(); i++)
	{
		cout << str[i] << endl;//���ִ����׳��쳣�����³����ж�
	}

	//2 ������

	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << endl;
	}

	//3 at��[]���𣬿����׳��쳣
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
	//string ���ʼ��
	string str = "kangzhenqiang";
	string strstr("wangjing");
	string strstrstr = str;
	string strstrstrstr(10, 'k');

	cout << str << endl;
	cout << strstr << endl;
	cout << strstrstr << endl;
	cout << strstrstrstr << endl;
}
