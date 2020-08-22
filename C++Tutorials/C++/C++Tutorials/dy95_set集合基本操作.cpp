
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;

/*
	1 ���� Ԫ��Ψһ �Զ����� ���ܰ���[]��ʽ����Ԫ��
	2 �����
	*/

void SetOperate()
{
	set<int> sett;//Ĭ�ϴ�С����
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
	set ���ڻ����������Ϳ����Զ�����
	���ڸ��ӵ���������
	*/

void SetCompara()
{
	set<int> sett;//Ĭ���Ǵ�С����
	set<int, less<int>> settSmall;
	set<int, greater<int>> settLarger;//�Ӵ�С

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

//�º���
struct FuncStudent
{
	/*	C3848	�������͡�const FuncStudent���ı��ʽ�ᶪʧһЩ const-volatile
		�޶����Ե��á�bool FuncStudent::operator ()(const Student &,const Student &)
		*/
	bool operator()(const Student& left, const Student& right) const
	{
		if (left.age < right.age)//�����ߵ�С �ͷ����� ��С�����������������
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
	setStudents.insert(s4);//set �����Ƕ���Ψһ ��������age 32 

	//����
	for (set<Student>::iterator it = setStudents.begin(); it != setStudents.end(); it++)
	{
		cout << "name:" << (*it).name << " " << "age:" << (*it).age << endl;
	}

}

//����ж�insert����ֵ

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
	set<int> sett;//Ĭ�ϴ�С����
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

	set<int>::iterator it1 = sett.lower_bound(3);//С�ڵ���3��Ԫ�� �� ��������λ��
	cout << "it1:" << *it1 << endl;

	set<int>::iterator it2 = sett.upper_bound(3);//����3��Ԫ�� �� ��������λ��
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
