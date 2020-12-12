#include "SeqList.h"

template <typename T>
SeqList<T>::SeqList(int capacity)
{
	pArr = new T[capacity];
	this->capacity = capacity;
	this->length = 0;
}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] pArr;
	this->length = 0;
	this->capacity = 0;
	this->pArr = nullptr;
}

template <typename T>
int SeqList<T>::getLength()
{
	return this->length;
}

template <typename T>
int SeqList<T>::getCapacity()
{
	return this->capacity;
}

template <typename T>
int SeqList<T>::insert(T& t, int pos)
{
	int i = 0;
	if (/*t==NULL||*/pos<0)
	{
		return -1;
	}

	//元素后移
	for ( i = length; i >pos; i--)
	{
		pArr[i] = pArr[i - 1];
	}

	pArr[i] = t;//stl 元素保存是通过 复制的机制实现的，你的类要可以复制才行

	this->length++;

	return 0;
}

template <typename T>
int SeqList<T>::get(int pos, T& t)
{
	int i = 0;
	if (/*t == nullptr ||*/ pos < 0)
	{
		return -1;
	}
	t = pArr[pos];
	return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T& t)
{
	int i = 0;
	t = pArr[pos];

	for ( i = pos+1; i < length; i++)
	{
		pArr[i - 1] = pArr[i];
	}
	length--;
	return 0;
}
