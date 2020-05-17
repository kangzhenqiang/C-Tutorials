
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


//��ά�������������� �˻����� ��ʵ����
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

	//a ��ά������ ����
	printf("a %d, a+1 %d\n", a, a + 1);//a+1�Ĳ��� ��20=5*4

	printf("&a %d, &a+1 %d\n", &a, &a + 1);


	//����һ��ָ�������ָ�����

	int(*pArr)[5];//���߱��������ҷ���4���ֽڵ��ڴ� 32ƽ̨��

	pArr = a;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", pArr[i][j]);
		}
		printf("\n");
	}
	//��ά�����ı��ʾ���һ�� ����ָ�룬������һά�ĳ���
	//(a+i)�����ǵ�i�еĵ�ַ ����ָ��
	//*��a+i������1��ָ�� ��i����Ԫ�صĵ�ַ
	//*��a+i��+j===��&a[i][j]

	//*��*��a+i��+j��===��a[i][j]

	printArray(a);

	//a[i][j]====>*(*(a+i)+j)
	//a[i]====>a[0+i]===>*(a+i)
	//a[i][j]===>a[0+1][j]===>*(a+i)[j]===>*(*(a+i)+j)

	system("pause");
}
