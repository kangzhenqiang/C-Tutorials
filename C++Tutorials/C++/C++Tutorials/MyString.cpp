#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"

MyString::MyString(int len)
{
	if (len==0)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = len;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);
	}
}

MyString::MyString(const char* p)
{
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
}

MyString::MyString(const MyString& obj)
{
	m_len = obj.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, obj.m_p);
}

MyString::~MyString()
{
	if (m_p != NULL)
	{
		m_len = 0;
		delete[] m_p;
		m_p = NULL;
	}
}

MyString& MyString::operator=(const char* p)
{
	// TODO: �ڴ˴����� return ���
	//���ڴ��ͷŵ�
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//�������ڴ�
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
	return *this;
}

MyString& MyString::operator=(const MyString& obj)
{
	// TODO: �ڴ˴����� return ���
	// �ɵ��ڴ��ͷŵ�
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	// ����s�������ڴ�
	m_len = obj.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, obj.m_p);
	return *this;
}

char& MyString::operator[](size_t index)
{
	// TODO: �ڴ˴����� return ���

	return m_p[index];
}

// const this ָ��ָ����ڴ�ռ䲻�����޸�

bool MyString::operator==(const char* p) const
{
	if (p == NULL)
	{
		if (m_len == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (strlen(p) != m_len)
		{
			return false;
		}
		else
		{
			int value = strcmp(m_p, p);
			return !value;
		}
	}
}

bool MyString::operator!=(const char* p) const
{
	return !(*this == p);
}

bool MyString::operator==(const MyString& obj) const
{
	if (m_len != obj.m_len)
	{
		return false;
	}
	return !strcmp(m_p, obj.m_p);
}

bool MyString::operator!=(const MyString& obj) const
{
	return !(*this == obj);
}

int MyString::operator>(const char* p) const
{
	return strcmp(p,this->m_p);
}

int MyString::operator<(const char* p) const
{
	return strcmp(this->m_p, p);
}

int MyString::operator>(const MyString& obj) const
{
	return strcmp(obj.m_p, this->m_p);
}

int MyString::operator<(const MyString& obj) const
{
	return strcmp(this->m_p,obj.m_p);
}

ostream& operator<<(ostream& out, MyString& obj)
{
	// TODO: �ڴ˴����� return ���
	cout << obj.m_p;
	return out;
}

istream& operator>>(istream& in, MyString& obj)
{
	// TODO: �ڴ˴����� return ���
	cin >> obj.m_p;
	return in;
}
