#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void maindy025001()
{
	int i = 0;
	int j = 0;
	char** p2 = NULL;
	char buf[100];
	int num = 5;
	p2 = (char**)malloc(sizeof(char*) * num);
	char* temp = NULL;

	for (i = 0; i < num; i++)
	{
		p2[i] = (char*)malloc(sizeof(char) * 100);//char buf[100];
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);//写入数据
	}

	printf("排序前：\n");

	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}


	//排序 指针交换
	/*
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				temp = p2[i];
				p2[i] = p2[j];
				p2[j] = temp;
			}
		}
	}
	*/

	//排序 交换内存
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				strcpy(buf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], buf);
			}
		}
	}


	printf("排序后：\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}


	//释放内存
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}

	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	system("pause");
}


char** getMem2(int num)
{
	int i = 0;
	char** p2 = (char**)malloc(sizeof(char*) * num);
	char* temp = NULL;

	for (i = 0; i < num; i++)
	{
		p2[i] = (char*)malloc(sizeof(char) * 100);//char buf[100];
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);//写入数据
	}
	return p2;
}


void printArr31(char** arr, int num)
{
	for (rsize_t i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(arr + i));
	}
}

void sortArr31(char** arr, int num)
{
	char* temp = NULL;
	//排序
	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = i; j < num; j++)
		{
			if (strcmp(arr[i], arr[j]) < 0)
			{
				temp = arr[i];//注意 交换的是数组元素 交换的是指针的值
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void freeMem2(char** p2, int num)
{
	int i = 0;
	//释放内存
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}

	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
}


void maindy025002()
{
	int i = 0;
	int j = 0;
	char** p2 = NULL;
	char buf[100];
	int num = 5;

	p2 = getMem2(num);

	printf("排序前：\n");

	printArr31(p2, num);

	sortArr31(p2, num);

	printf("排序后：\n");

	printArr31(p2, num);

	//释放内存
	freeMem2(p2, num);
	system("pause");
}