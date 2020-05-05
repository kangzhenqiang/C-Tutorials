#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//打印 排序
//封装成函数

void maindy024001()
{
	char myBuf[30];
	char myArr[10][30] = { "aaaaa","bbbbb","ccccc","ddddd" };


	//myArr：编译器指挥关心：有10行，每行30列，干什么？myArr+1 多维数组的本质
	{
		int len1 = sizeof(myArr);
		int len2 = sizeof(myArr[0]);
		int size = len1 / len2;
		printf("len1:%d, len2:%d, size:%d\n", len1, len2, size);
	}


	int i = 0, j = 0;
	int num = 4;

	//打印
	printf("排序前：\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", myArr[i]);
	}

	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArr[i], myArr[j]) < 0)
			{
				strcpy(myBuf, myArr[i]);//交互的是内存块
				strcpy(myArr[i], myArr[j]);
				strcpy(myArr[j], myBuf);
			}
		}
	}

	//打印
	printf("排序后：\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", myArr[i]);
	}

	return;
}

//问题的本质是：二级指针做输入模型——第二种内存模型的myarr+1 
//和 二级指针做输入模型——第一种内存模型的myarr+1不一样
//指针的步长不一样 指针所指向的内存空间数据类型不一样
void printArr21_err(char** arr, int num)
{
	for (rsize_t i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(arr + i));
	}
}

void printArr21(char arr[10][30], int num)
{
	for (rsize_t i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(arr + i));
	}
}


//交互的是内存块
void sortArr22(char arr[10][30], int num)
{
	char myBuf[30];
	int i = 0, j = 0;
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(arr[i], arr[j]) < 0)
			{
				strcpy(myBuf, arr[i]);//交互的是内存块
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], myBuf);
			}
		}
	}
}


void maindy024002()
{
	char myBuf[30];
	char myArr[10][30] = { "aaaaa","bbbbb","ccccc","ddddd" };

	int i = 0, j = 0;
	int num = 4;

	//打印
	printf("排序前：\n");
	printArr21(myArr, num);

	//排序
	sortArr22(myArr, num);

	//打印
	printf("排序后：\n");
	printArr21(myArr, num);

	return;
}