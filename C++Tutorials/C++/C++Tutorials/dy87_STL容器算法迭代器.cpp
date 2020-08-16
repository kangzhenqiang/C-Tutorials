

/*
	STL(Standard Template Library)��׼ģ����ǻ���ʵ���ҿ�����һϵ�������ͳ�ơ�
	������Ҫ������C++�У����ڱ�����c++֮ǰ�Ѿ����ںܳ���һ��ʱ�䡣
	STL�ӹ㷺�����Ϊ���ࣺalgorithm(�㷨)��container(����)��iterator(������)���㷨������ͨ�����������Խ����޷����ӡ�
	��c++��׼�У�STL����֯Ϊ13��ͷ�ļ���
	<algorithm>��<deque>��<functional>��<vector>��<list>��<map>��<memory>��<numeric>��<queue>��<set>��<stack>��<utility>

	STL��ϸ�����������
		���� Container
		�㷨 Algorithm
		������ Iterator
		α���� Function object
		������ Adaptor
		�ռ������� Allocator
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;


class Teacher
{
public:
	Teacher(int age);
	~Teacher();
	Teacher(Teacher& obj);

	void Print()
	{
		cout << age;
	}

public:
	int age;
};

Teacher::Teacher(int age)
{
	this->age = age;
}

Teacher::~Teacher()
{
}

Teacher::Teacher(Teacher& obj)
{
	this->age = obj.age;
}


int main()
{
	//1. ���� �������ݱ���
	vector<int> v;
	v.push_back(-10);
	v.push_back(10);
	v.push_back(-10);
	v.push_back(10);

	//2. �������������һ��ָ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//3. �㷨���㷨������ͨ�����������Խ����޷�����
	int num = count(v.begin(), v.end(), 10);

	cout << num << endl;

	Teacher t1(32);
	Teacher t2(20);
	Teacher t3(25);
	Teacher t4(40);

	//���� �Զ��� ����
	vector<Teacher> teachers;
	teachers.push_back(t1);
	teachers.push_back(t2);
	teachers.push_back(t3);
	teachers.push_back(t4);

	for (vector<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++)
	{
		cout << it->age << endl;
	}

	//���� ָ��

	Teacher* pt1, * pt2, * pt3;

	pt1 = &t1;
	pt2 = &t2;
	pt3 = &t3;

	vector<Teacher*> pTeachers;

	pTeachers.push_back(pt1);
	pTeachers.push_back(pt2);
	pTeachers.push_back(pt3);

	for (vector<Teacher*>::iterator it = pTeachers.begin(); it != pTeachers.end(); it++)
	{
		cout << (*it)->age << endl;
	}

	//����ש ���������������ʦ�ڵ������=33

	cout << "�������㷨��������" << endl;
	system("pause");
	return 0;
}
