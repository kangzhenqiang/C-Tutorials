
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*
	时间换空间
		问题：
			在一个由自然数1-1000中某个数字所组成的数组中，每个数字可能出现零次或这多次
			设计一个算法，找出出现次数最多的数字
			int array[2000]={1,3,3,4,5,6,43,99,3,99,3,3,3}
	*/

void search(int a[], int len)
{
	int sp[1000] = { 0 };
	int i = 0;
	int max = 0;
	for (i = 0; i < 1000; i++)
	{
		int index = a[i] - 1;
		sp[index]++;
	}

	for (i = 0; i < 1000; i++)
	{
		if (max < sp[i])
		{
			max = sp[i];
		}
	}

	for (i = 0; i < 1000; i++)
	{
		if (max == sp[i])
		{
			printf("%d\n", i + 1);
		}
	}
}



void main()
{
	int array[2000] = { 1,3,3,4,5,6,43,99,3,99,3,3,3 };
	int len = sizeof(array) / sizeof(*array);
	search(array, len);
	system("pause");
}
