#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void maindy02201()
{
	//���� ������ÿһ��Ԫ����ָ�� ָ������
	char* myArr[] = { "aaaa","bbbb","cccc","1111" };

	int i = 0, j = 0;
	int num = 0;

	char* temp = NULL;

	printf("����֮ǰ:\n");

	//��ӡ
	num = sizeof(myArr) / sizeof(myArr[0]);
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(myArr + i));
	}

	//����
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArr[i], myArr[j]) > 0)
			{
				temp = myArr[i];//ע�� ������������Ԫ�� ��������ָ���ֵ
				myArr[i] = myArr[j];
				myArr[j] = temp;
			}
		}
	}
	printf("����֮��:\n");

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
	//����
	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = i; j < num; j++)
		{
			if (strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];//ע�� ������������Ԫ�� ��������ָ���ֵ
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void maindy02302()
{
	//���� ������ÿһ��Ԫ����ָ�� ָ������
	char* myArr[] = { "aaaa","bbbb","cccc","1111" };

	int i = 0, j = 0;
	int num = 0;

	char* temp = NULL;

	printf("����֮ǰ:\n");

	//��ӡ
	num = sizeof(myArr) / sizeof(myArr[0]);

	printArr11(myArr, num);

	sortArr12(myArr, num);
	
	printf("����֮��:\n");

	printArr11(myArr, num);

	system("pause");
	return;
}