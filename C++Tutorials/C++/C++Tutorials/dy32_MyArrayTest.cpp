#include <iostream>

#include "MyArray.h"

int maindy032()
{
	Array arr(10);
	for (size_t i = 0; i < arr.length(); i++)
	{
		arr.setData(i, i);
	}

	for (size_t i = 0; i < arr.length(); i++)
	{
		cout << arr.getData(i) << endl;
	}

	Array a = arr;
	cout << "¸³Öµ..." << endl;

	for (size_t i = 0; i < arr.length(); i++)
	{
		cout << a.getData(i) << endl;
	}

	system("pause");
	return 0;
}