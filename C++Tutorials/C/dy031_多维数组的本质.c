
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void printArray(int arr[3][5])//4k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void printArray01(int arr[][5])//5k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void printArray02(int (*arr)[5])//6k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void printArray03(int(*arr)[5])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


//多维数组作函数参数 退化过程 事实存在
//

void maindy031()
{
	int a[3][5], i = 0, j = 0;

	int temp = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = temp++;
		}
	}


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	//a 多维数组名 代表？
	printf("a %d, a+1 %d\n", a, a + 1);//a+1的步长 是20=5*4

	printf("&a %d, &a+1 %d\n", &a, &a + 1);


	//定义一个指向数组的指针变量

	int(*pArr)[5];//告诉编译器给我分配4个字节的内存 32平台下

	pArr = a;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", pArr[i][j]);
		}
		printf("\n");
	}
	//多维组名的本质就是一个 数组指针，步长：一维的长度
	//(a+i)代表是底i行的地址 二级指针
	//*（a+i）代表1级指针 第i行首元素的地址
	//*（a+i）+j===》&a[i][j]

	//*（*（a+i）+j）===》a[i][j]

	printArray(a);

	//a[i][j]====>*(*(a+i)+j)
	//a[i]====>a[0+i]===>*(a+i)
	//a[i][j]===>a[0+1][j]===>*(a+i)[j]===>*(*(a+i)+j)

	system("pause");
}
