#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void getMem3(char*** p, int num)
{
	if (p == NULL)
	{
		return;
	}

	int i = 0;
	char** temp = NULL;

	temp = (char**)malloc(sizeof(char*) * num);

	if (temp==NULL)
	{
		return;
	}

	for (size_t i = 0; i < num; i++)
	{
		temp[i] = (char*)malloc(sizeof(char) * 100);
		sprintf(temp[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	*p = temp;
}


void freeMem3(char*** p, int num)
{
	char** temp = NULL;
	if (p==NULL)
	{
		return;
	}
	temp = *p;

	int i = 0;
	//释放内存
	for (i = 0; i < num; i++)
	{
		if (temp[i] != NULL)
		{
			free(temp[i]);
			temp[i] = NULL;
		}
	}

	free(temp);
	*p = NULL;//把实参赋值为NULL
}

void printArr3(char** arr, int num)
{
	for (rsize_t i = 0; i < num; i++)
	{
		//printf("%s \n", myArr[i]);
		printf("%s \n", *(arr + i));
	}
}


void maindy027()
{
	char** p = NULL;
	int num = 5;

	getMem3(&p, 5);

	printArr3(p, num);

	freeMem3(&p, num);

	system("pause");
}