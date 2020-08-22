
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

/*
	������ߣ�
		���������ṩ�Ķ�ʱֵ��value�����⣬�������ã�reference�����⡣
		����ִ�в���Ԫ�صĲ���ʱ���ڲ�ʵʩ��������������STL�����ڴ�洢��Ԫ�ر����ܹ��������������ṩ�������캯������
*/

class Teacher
{
	friend ostream& operator<<(ostream& out, const Teacher& obj);
public:
	Teacher(const char* name, int age);

	//�������캯��
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
	//�ȰѾ��ڴ��ͷŵ�
	if (m_pName != NULL)
	{
		delete[] m_pName;
		m_pName = NULL;
		m_age = 0;
	}
	//�����¶����С�����ڴ�
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
