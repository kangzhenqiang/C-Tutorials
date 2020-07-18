
#include<iostream>

using namespace std;

/// <summary>
/// [] == != ����������
/// </summary>

class Array
{
public:
	Array(const int count);
	Array(const Array& obj);
	~Array();

	Array& operator=(const Array& obj);
	//��������ֵ����ֵ����Ҫ����һ������
	int& operator[] (const int i);

	bool operator==(const Array& obj);
	bool operator!=(const Array& obj);
private:
	int m_len;
	int* m_arr;
};

Array::Array(const int count)
{
	m_len = count;
	m_arr = new int[m_len];
	for (size_t i = 0; i < m_len; i++)
	{
		m_arr[i] = i;
	}
}

Array::Array(const Array& obj)
{
	this->m_len = obj.m_len;
	this->m_arr = new int[m_len];
	for (size_t i = 0; i < m_len; i++)
	{
		m_arr[i] = obj.m_arr[i];
	}
}

Array::~Array()
{
	if (m_arr != NULL)
	{
		delete[] m_arr;
		m_arr = NULL;
		m_len = 0;
	}
}

int& Array::operator[](const int i)
{
	return this->m_arr[i];
}

bool Array::operator==(const Array& obj)
{
	if (this->m_len!=obj.m_len)
	{
		return false;
	}
	for (size_t i = 0; i < obj.m_len; i++)
	{
		if (this->m_arr[i]!=obj.m_arr[i])
		{
			return false;
		}
	}
	return true;
}

bool Array::operator!=(const Array& obj)
{
	/*if (*this==obj)
	{
		return false;
	}
	else
	{
		return true;
	}*/

	return !(*this == obj);

	/*if (this->m_len != obj.m_len)
	{
		return true;
	}
	for (size_t i = 0; i < obj.m_len; i++)
	{
		if (this->m_arr[i] != obj.m_arr[i])
		{
			return true;
		}
	}
	return false;*/
}

Array& Array::operator=(const Array& obj)
{
	// TODO: �ڴ˴����� return ���
	// �ͷ�ԭ�����ڴ�ռ�
	if (this->m_arr != NULL)
	{
		delete[] this->m_arr;
		this->m_len = 0;
	}
	//�����ڴ�
	this->m_len = obj.m_len;
	this->m_arr = new int[m_len];
	for (size_t i = 0; i < m_len; i++)
	{
		m_arr[i] = obj.m_arr[i];
	}
	return *this;
}


int main()
{
	Array arr(10);
	Array arr1 = arr;
	Array arr2(5);
	arr1 = arr;
	cout << arr[4] << endl;

	/*arr[4] = 8;
	cout << arr[4] << endl;*/

	if (arr == arr1)
	{
		cout << "���" << endl;
	} 
	else
	{
		cout << "�����" << endl;
	}

	if (arr != arr2)
	{
		cout << "�����" << endl;
	}
	else
	{
		cout << "���" << endl;
	}

	system("pause");
	return 0;
}