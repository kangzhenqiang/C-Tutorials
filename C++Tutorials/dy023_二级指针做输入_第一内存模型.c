#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void maindy02201()
{
	//数组 数组中每一个元素是指针 指针数组
	char* myArr[] = { "aaaa","bbbb","cccc","1111" };

	int i = 0, j = 0;
	int num = 0;

	char* temp = NULL;

	printf("排序之前:\n");

	//打印
	num = sizeof(myArr) / sizeof(myArr[0]);
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(myArr + i));
	}

	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArr[i], myArr[j]) > 0)
			{
				temp = myArr[i];//注意 交换的是数组元素 交换的是指针的值
				myArr[i] = myArr[j];
				myArr[j] = temp;
			}
		}
	}
	printf("排序之后:\n");

	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(myArr + i));
	}

	system("pause");
	return;
}


void printArr11(char** arr, int num)
{
	for (rsize_t i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(arr + i));
	}
}

void sortArr12(char** arr, int num)
{
	char* temp = NULL;
	//排序
	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = i; j < num; j++)
		{
			if (strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];//注意 交换的是数组元素 交换的是指针的值
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void maindy02302()
{
	//数组 数组中每一个元素是指针 指针数组
	char* myArr[] = { "aaaa","bbbb","cccc","1111" };

	int i = 0, j = 0;
	int num = 0;

	char* temp = NULL;

	printf("排序之前:\n");

	//打印
	num = sizeof(myArr) / sizeof(myArr[0]);

	printArr11(myArr, num);

	sortArr12(myArr, num);
	
	printf("排序之后:\n");

	printArr11(myArr, num);

	system("pause");
	return;
}