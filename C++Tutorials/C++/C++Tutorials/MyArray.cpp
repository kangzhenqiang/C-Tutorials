#include "MyArray.h"

Array::Array(int n)
{
	if (n < 0)
	{
		m_length = 0;
	}
	else
	{
		m_length = n;
	}
	m_space = new int[m_length];
}

Array::Array(const Array& obj)
{
	this->m_length = obj.m_length;
	this->m_space = new int[this->m_length];//分配内存空间
	for (size_t i = 0; i < m_length; i++)//数组元素复制
	{
		this->m_space[i] = obj.m_space[i];
	}
}

Array::~Array()
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
	}
}

void Array::setData(int index, int value) {
	m_space[index] = value;
}
int Array::getData(int index) {

	return m_space[index];
}
int Array::length() {
	return m_length;
}
