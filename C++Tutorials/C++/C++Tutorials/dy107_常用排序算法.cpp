
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;


void vector_merge()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

class Student
{
public:
	Student(string name, int age) {
		m_name = name;
		m_age = age;
	}

	void Print()
	{
		cout << "my name is " << m_name << "," << "my age is " << m_age << endl;
	}

public:
	string m_name;
	int m_age;
};

bool CompareStudent(Student s1, Student s2)
{
	return s1.m_age < s2.m_age;
}

void mySort()
{
	Student s1("kang", 32);
	Student s2("zhen", 33);
	Student s3("qiang", 34);
	Student s4("wang", 33);

	vector<Student> s;
	s.push_back(s1);
	s.push_back(s2);
	s.push_back(s3);
	s.push_back(s4);
	
	for (vector<Student>::iterator it = s.begin(); it != s.end(); it++)
	{
		it->Print();
	}

	//sort根据自定义函数对象进行自定义数据类型的排序
	//替换 算法的统一性（实现的算法和数据类的分离）===>奇数手段函数对象
	sort(s.begin(), s.end(), CompareStudent);

	cout << "sort:" << endl;
	for (vector<Student>::iterator it = s.begin(); it != s.end(); it++)
	{
		it->Print();
	}
}

void myRundom()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	random_shuffle(v1.begin(), v1.end());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	string str = "zaefnforeif";
	random_shuffle(str.begin(), str.end());

	cout << str << endl;
}


void myReversze()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	reverse(v1.begin(), v1.end());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector_merge();

	mySort();

	myRundom();

	myReversze();

	system("pause");
	return 0;
}
