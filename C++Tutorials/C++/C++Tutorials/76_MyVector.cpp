
#include<iostream>
#include"76_MyVector.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, MyVector<T>& obj)
{
	for (size_t i = 0; i < obj.GetLen(); i++)
	{
		cout << obj.m_space[i] << " ";
	}
	cout << endl;
	return out;
}



template<typename T>
MyVector<T>::MyVector(int size)//构造函数
{
	m_space = new T[size];
	m_len = size;
}

template<typename T>
MyVector<T>::MyVector(const MyVector& obj)//拷贝构造函数
{
	m_len = obj.m_len;
	m_space = new T[m_len];
	for (size_t i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template<typename T>
MyVector<T>::~MyVector()//析构函数
{
	delete[] m_space;
	m_len = 0;
}

template<typename T>
T& MyVector<T>::operator[](int index)//[] 操作符重载
{
	return m_space[index];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& obj)//=操作符重载
{
	//先把旧的内存释放掉
	if (m_space!=NULL)
	{
		delete[] m_space;
		m_space = NULL;//避免野指针
		m_len = 0;
	}

	//根据obj分配新内存
	m_len = obj.m_len;
	m_space = new T[m_len];

	//拷贝数据
	for (size_t i = 0; i < m_len; i++)
	{
		m_space[i] = obj[i];
	}
	return *this;
}


