
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//算法的最重编译成具体的计算机指令
//每一个指令 在具体的计算机 cpu上运行的时间是固定
//通过具体的n的步骤的多少就可以推导出算法的复杂度

//算法时间复杂度的度量 大O
//算法空间复杂度的度量 大O

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
