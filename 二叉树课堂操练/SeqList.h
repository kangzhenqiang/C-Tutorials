#pragma once

#ifndef SEQLIST_H
#define SEQLIST_H
using namespace std;

template <typename T>
class SeqList
{
public:
	SeqList(int capacity);

	~SeqList();

	int getLength();

	int getCapacity();

	int insert(T& t, int pos);

	int get(int pos, T& t);

	int del(int pos, T& t);

private:
	int length;
	int capacity;
	T* pArr;
};

#endif // !SEQLIST_H




