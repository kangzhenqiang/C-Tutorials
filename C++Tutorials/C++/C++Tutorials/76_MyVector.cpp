
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
MyVector<T>::MyVector(int size)//���캯��
{
	m_space = new T[size];
	m_len = size;
}

template<typename T>
MyVector<T>::MyVector(const MyVector& obj)//�������캯��
{
	m_len = obj.m_len;
	m_space = new T[m_len];
	for (size_t i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template<typename T>
MyVector<T>::~MyVector()//��������
{
	delete[] m_space;
	m_len = 0;
}

template<typename T>
T& MyVector<T>::operator[](int index)//[] ����������
{
	return m_space[index];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& obj)//=����������
{
	//�ȰѾɵ��ڴ��ͷŵ�
	if (m_space!=NULL)
	{
		delete[] m_space;
		m_space = NULL;//����Ұָ��
		m_len = 0;
	}

	//����obj�������ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];

	//��������
	for (size_t i = 0; i < m_len; i++)
	{
		m_space[i] = obj[i];
	}
	return *this;
}


