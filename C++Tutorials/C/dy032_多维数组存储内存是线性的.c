
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void printArrrrrrr(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



void maindy032()
{
	int a[3][5];
	int i, j, tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	//�Ѷ�ά���鵱��һά��������ӡ ֤�����Դ洢

	printArrrrrrr((int*)a, 15);

	system("pause");
}
