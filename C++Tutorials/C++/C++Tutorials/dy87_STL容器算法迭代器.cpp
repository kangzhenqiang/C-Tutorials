

/*
	STL(Standard Template Library)标准模板库是惠普实验室开发的一系列软件的统称。
	现在主要出现再C++中，但在被引入c++之前已经存在很长的一段时间。
	STL从广泛定义分为三类：algorithm(算法)、container(容器)和iterator(迭代器)，算法和容器通过迭代器可以进行无缝连接。
	在c++标准中，STL被组织为13个头文件：
	<algorithm>、<deque>、<functional>、<vector>、<list>、<map>、<memory>、<numeric>、<queue>、<set>、<stack>、<utility>

	STL详细的六大组件：
		容器 Container
		算法 Algorithm
		迭代器 Iterator
		伪函数 Function object
		适配器 Adaptor
		空间配置器 Allocator
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
	//1. 容器 基础数据变量
	vector<int> v;
	v.push_back(-10);
	v.push_back(10);
	v.push_back(-10);
	v.push_back(10);

	//2. 迭代器：相等与一个指针
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//3. 算法：算法和容器通过迭代器可以进行无缝连接
	int num = count(v.begin(), v.end(), 10);

	cout << num << endl;

	Teacher t1(32);
	Teacher t2(20);
	Teacher t3(25);
	Teacher t4(40);

	//容器 自定义 对象
	vector<Teacher> teachers;
	teachers.push_back(t1);
	teachers.push_back(t2);
	teachers.push_back(t3);
	teachers.push_back(t4);

	for (vector<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++)
	{
		cout << it->age << endl;
	}

	//容器 指针

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

	//先抛砖 如何求复杂容器中老师节点的年龄=33

	cout << "容器、算法、迭代器" << endl;
	system("pause");
	return 0;
}
