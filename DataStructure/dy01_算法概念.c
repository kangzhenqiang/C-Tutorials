
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//�㷨�����ر���ɾ���ļ����ָ��
//ÿһ��ָ�� �ھ���ļ���� cpu�����е�ʱ���ǹ̶�
//ͨ�������n�Ĳ���Ķ��پͿ����Ƶ����㷨�ĸ��Ӷ�

//�㷨ʱ�临�ӶȵĶ��� ��O
//�㷨�ռ临�ӶȵĶ��� ��O

long sum1(int n)//2n+3 ====>O(n)
{
	long ret = 0;
	int* arr = (int*)malloc(sizeof(int) * n);

	for (long i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (long i = 0; i < n; i++)
	{
		ret += arr[i];
	}
	free(arr);

	return ret;
}

long sum2(int n)//n+2 =====>O(n)
{
	long ret = 0;

	for (long i = 0; i < n; i++)
	{
		ret += (i + 1);
	}

	return ret;
}


long sum3(int n)//O(1)
{
	long ret = 0;

	ret = n * (n + 1) / 2;

	return ret;
}

void main()
{
	long sum = 0;
	sum= sum1(100);
	printf("sum:%d\n", sum);
	sum = sum2(100);
	printf("sum:%d\n", sum);
	sum = sum3(100);
	printf("sum:%d\n", sum);
	system("pause");
}
