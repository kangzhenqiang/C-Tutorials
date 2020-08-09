#pragma once
#include<iostream>
using namespace std;

template<typename T>
class MyVector
{
	friend ostream& operator<< <T>(ostream& out, MyVector<T>& obj);

public:
	MyVector(int size = 0);//���캯��
	MyVector(const MyVector& obj);//�������캯��
	~MyVector();//��������

public:

	T& operator [](int index);
	MyVector& operator = (const MyVector & obj);

	int GetLen()
	{
		return m_len;
	}

private:
	T* m_space;
	int m_len;
};