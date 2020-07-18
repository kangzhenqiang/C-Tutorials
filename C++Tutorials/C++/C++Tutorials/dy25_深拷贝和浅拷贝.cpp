#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Name
{
public:
	Name(const char* name);
	Name(const Name& obj);
	~Name();

private:
	char* m_p = NULL;
	int m_len = 0;
};

Name::Name(const char* name)
{
	m_len = strlen(name);
	m_p = (char*)malloc(m_len + 1);
	strcpy(m_p, name);
}

//�ֹ���д�������캯���������
Name::Name(const Name& obj)
{
	m_len = obj.m_len;
	m_p = (char*)malloc(m_len + 1);
	strcpy(m_p, obj.m_p);
}

Name::~Name()
{
	if (m_p!=NULL)
	{
		free(m_p);
		m_p = NULL;
		m_len = 0;
	}
}


void objMain000()
{
	Name obj1("kangzhenqiang");

	Name obj2=obj1;//����ǳ���� Ĭ�Ͽ������캯�� c++�������ṩ��

	Name obj3("kang");

	obj3 = obj1;//�ȺŲ��� �� ��ʼ���ǲ�һ���� Ĭ�ϵ���ǳ���� ������� ��ʾ����=������
}

int maindy025()
{
	objMain000();

	system("pause");
	return 0;
}