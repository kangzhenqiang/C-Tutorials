
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

/*
	理论提高：
		所有容器提供的都时值（value）语意，而非引用（reference）语意。
		容器执行插入元素的操作时，内部实施拷贝动作。所以STL容器内存存储的元素必须能够被拷贝（必须提供拷贝构造函数）。
*/

class Teacher
{
	friend ostream& operator<<(ostream& out, const Teacher& obj);
public:
	Teacher(const char* name, int age);

	//拷贝构造函数
	Teacher(const Teacher& obg);

	Teacher& operator=(const Teacher& obj);

	void printf();

	~Teacher();
private:
	char* m_pName;
	int m_age;
};

Teacher::Teacher(const char* name, int age)
{
	m_pName = new char[strlen(name) + 1];
	strcpy(m_pName, name);
	m_age = age;
}

Teacher::Teacher(const Teacher& obj)
{
	m_pName = new char[strlen(obj.m_pName + 1)];
	strcpy(m_pName, obj.m_pName);
	m_age = obj.m_age;
}


Teacher& Teacher:: operator=(const Teacher& obj)
{
	//先把旧内存释放掉
	if (m_pName != NULL)
	{
		delete[] m_pName;
		m_pName = NULL;
		m_age = 0;
	}
	//根据新对象大小分配内存
	m_pName = new char[strlen(obj.m_pName + 1)];
	strcpy(m_pName, obj.m_pName);
	m_age = obj.m_age;
	return *this;
}

void Teacher::printf()
{
	cout << m_pName << "\t" << m_age << endl;
}

ostream& operator<<(ostream& out, const Teacher& obj) {
	out << obj.m_pName << "\t" << obj.m_age << endl;
	return out;
}

Teacher::~Teacher()
{
	if (m_pName != NULL)
	{
		delete[] m_pName;
		m_pName = NULL;
		m_age = 0;
	}
}


int main()
{
	Teacher t("kangzhenqiang", 32);
	t.printf();
	vector<Teacher> v;
	v.push_back(t);

	system("pause");
	return 0;
}
