#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//��ӡ ����
//��װ�ɺ���

void maindy024001()
{
	char myBuf[30];
	char myArr[10][30] = { "aaaaa","bbbbb","ccccc","ddddd" };


	//myArr��������ָ�ӹ��ģ���10�У�ÿ��30�У���ʲô��myArr+1 ��ά����ı���
	{
		int len1 = sizeof(myArr);
		int len2 = sizeof(myArr[0]);
		int size = len1 / len2;
		printf("len1:%d, len2:%d, size:%d\n", len1, len2, size);
	}


	int i = 0, j = 0;
	int num = 4;

	//��ӡ
	printf("����ǰ��\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", myArr[i]);
	}

	//����
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArr[i], myArr[j]) < 0)
			{
				strcpy(myBuf, myArr[i]);//���������ڴ��
				strcpy(myArr[i], myArr[j]);
				strcpy(myArr[j], myBuf);
			}
		}
	}

	//��ӡ
	printf("�����\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", myArr[i]);
	}

	return;
}

//����ı����ǣ�����ָ��������ģ�͡����ڶ����ڴ�ģ�͵�myarr+1 
//�� ����ָ��������ģ�͡�����һ���ڴ�ģ�͵�myarr+1��һ��
//ָ��Ĳ�����һ�� ָ����ָ����ڴ�ռ��������Ͳ�һ��
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


//���������ڴ��
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
				strcpy(myBuf, arr[i]);//���������ڴ��
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

	//��ӡ
	printf("����ǰ��\n");
	printArr21(myArr, num);

	//����
	sortArr22(myArr, num);

	//��ӡ
	printf("�����\n");
	printArr21(myArr, num);

	return;
}