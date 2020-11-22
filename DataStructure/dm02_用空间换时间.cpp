
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
	问题：
		在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或多次
		设计一个算法，找出出现次数最多的数字
		int arr[2000]={1,50,45,36,14,36,60,45,60};

		用时间换空间
	*/


using namespace std;

void search(int arr[], int len)
{
	int sp[1000] = { 0 };
	int max = 0;
	for (size_t i = 0; i < len; i++)//遍历数组，求出每一个数字出现的次数,然后记录下来
	{
		int index = arr[i] - 1;
		sp[index]++;
	}

	for (size_t i = 0; i < 1000; i++)//扫描数组，求出最大数
	{
		if (max< sp[i])
		{
			max = sp[i];
		}
	}
	for (size_t i = 0; i < 1000; i++)//打印数字最多的
	{
		if (max==sp[i])
		{
			cout << "arr max value:" << i + 1 << endl;
		}
	}
}


int main()
{
	int arr[] = { 1,50,45,36,14,36,60,45,60 };
	search(arr, sizeof(arr) / sizeof(*arr));
	system("pause");
	return 0;
}
