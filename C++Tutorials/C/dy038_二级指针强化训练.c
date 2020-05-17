
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int sortsort(char** p/*in*/, int num1, char(*p1)[30], int num2, char*** p3, int* num3)
{
	char** temp = NULL;
	temp = (char**)malloc(sizeof(char*) * (num1 + num2));
	int lenght = 0;

	//根据字符串分配字符
	for (int i = 0; i < num1; i++)
	{
		int tempLen = strlen(p[i]) + 1;
		temp[i] = (char*)malloc(tempLen * sizeof(char));
		strcpy(temp[i], p[i]);
	}

	for (int i = num1; i < num1 + num2; i++)
	{
		int tempLen = strlen(p1[i - num1]) + 1;
		temp[i] = (char*)malloc(tempLen * sizeof(char));
		strcpy(temp[i], p1[i-num1]);
	}
	lenght = num1 + num2;

	char* mytemp = NULL;

	for (int i = 0; i < lenght; i++)
	{
		for (int j = i + 1; j < lenght; j++)
		{
			if (strcmp(temp[i], temp[j]) > 0)
			{
				mytemp = temp[i];
				temp[i] = temp[j];
				temp[j] = mytemp;
			}
		}
	}
	*num3 = lenght;
	*p3 = temp;
	return 0;
}

int sortFree(char** p, int len)//把二级指针指向二维
{
	int ret = 0;
	if (p == NULL)
	{
		ret = -1;
		return ret;
	}

	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
}


int sortFreeFree(char*** p, int len)//把二级指针指向二维
{
	int ret = 0;
	if (p == NULL)
	{
		ret = -1;
		return ret;
	}

	char** temp = *p;//还原成二级指针
	if (temp == NULL)
	{
		ret = -2;
		return ret;
	}

	for (int i = 0; i < len; i++)
	{
		free(temp[i]);
	}
	free(temp);
	*p = NULL;//间接赋值是指针存在的最大价值
}

int maindy038()
{
	int ret = 0;
	char* p1[] = { "aaaaa","bbbbb","ccccc" };
	char buf2[10][30] = { "111111","22222","33333" };
	char** p3 = NULL;

	int len1, len2, len3, i = 0;
	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	ret = sortsort(p1, len1, buf2, len2, &p3, &len3);

	if (ret != 0)
	{
		printf("fun sortsort() error:%d\n", ret);
		return ret;
	}

	for (i = 0; i < len3; i++)
	{
		printf("%s\n", p3[i]);
	}

	sortFreeFree(&p3, len3);

	system("pause");
	return ret;
}
