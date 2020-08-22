
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;

/*
	1 集合 元素唯一 自动排序 不能按照[]方式插入元素
	2 红黑树
	*/

void SetOperate()
{
	set<int> sett;//默认从小到大
	for (size_t i = 0; i < 5; i++)
	{
		int temp = rand();
		sett.insert(temp);
	}
	sett.insert(100);
	sett.insert(100);
	sett.insert(100);

	for (set<int>::iterator it = sett.begin(); it != sett.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	while (!sett.empty())
	{
		cout << *sett.begin() << " ";
		sett.erase(sett.begin());
	}
	cout << endl;

}

/*
	set 对于基本数据类型可以自动排序
	对于复杂的数据类型
	*/

void SetCompara()
{
	set<int> sett;//默认是从小到大
	set<int, less<int>> settSmall;
	set<int, greater<int>> settLarger;//从大到小

	for (size_t i = 0; i < 5; i++)
	{
		int temp = rand();
		settLarger.insert(temp);
	}
	settLarger.insert(100);
	settLarger.insert(100);
	settLarger.insert(100);

	for (set<int>::iterator it = settLarger.begin(); it != settLarger.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


class Student
{
public:
	Student(const char* name, int age);
	~Student();

public:
	char name[64];
	int age;
};

Student::Student(const char* name, int age)
{
	strcpy(this->name, name);
	this->age = age;
}

Student::~Student()
{
}

//仿函数
struct FuncStudent
{
	/*	C3848	具有类型“const FuncStudent”的表达式会丢失一些 const-volatile
		限定符以调用“bool FuncStudent::operator ()(const Student &,const Student &)
		*/
	bool operator()(const Student& left, const Student& right) const
	{
		if (left.age < right.age)//如果左边的小 就返回真 从小到大按照年龄进行排序
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


void CompareDefineObj()
{
	set<Student, FuncStudent> setStudents;
	Student s1("kangzhenqiang", 32);
	Student s2("wang", 33);
	Student s3("jingjing", 36);
	Student s4("kangkang", 39);

	setStudents.insert(s1);
	setStudents.insert(s2);
	setStudents.insert(s3);
	setStudents.insert(s4);//set 集合是对象唯一 插入两个age 32 

	//遍历
	for (set<Student>::iterator it = setStudents.begin(); it != setStudents.end(); it++)
	{
		cout << "name:" << (*it).name << " " << "age:" << (*it).age << endl;
	}

}

//如何判断insert返回值

void insertVaule()
{
	set<Student, FuncStudent> setStudents;
	Student s1("kangzhenqiang", 32);
	Student s2("wang", 32);
	pair<set<Student>::iterator, bool> p1 = setStudents.insert(s1);
	cout << p1.second << endl;
	pair<set<Student>::iterator, bool> p2 = setStudents.insert(s2);
	cout << p2.second << endl;
}

void findElem()
{
	set<int> sett;//默认从小到大
	for (size_t i = 0; i < 5; i++)
	{
		//int temp = rand();
		sett.insert(i + 1);
	}
	sett.insert(100);
	sett.insert(100);
	sett.insert(100);

	for (set<int>::iterator it = sett.begin(); it != sett.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it = sett.find(3);
	cout << "it:" << *it << endl;

	int num = sett.count(3);
	cout << "num:" << num << endl;

	set<int>::iterator it1 = sett.lower_bound(3);//小于等于3的元素 的 迭代器的位置
	cout << "it1:" << *it1 << endl;

	set<int>::iterator it2 = sett.upper_bound(3);//大于3的元素 的 迭代器的位置
	cout << "it2:" << *it2 << endl;

	pair<set<int>::iterator, set<int>::iterator> itit = sett.equal_range(3);
	itit.first;
	itit.second;

	sett.erase(3);
	for (set<int>::iterator it = sett.begin(); it != sett.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


int main()
{
	SetOperate();
	SetCompara();
	CompareDefineObj();
	insertVaule();
	findElem();

	system("pause");
	return 0;
}
