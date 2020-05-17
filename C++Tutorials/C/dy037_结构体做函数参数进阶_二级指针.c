
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher {
	char name[64];
	char* alisname;
	char** studentNames;
	int age;
	int id;
} Teacher;


void printTeacher(Teacher* arr, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("\nage:%d\n", arr[i].age);
		for (int j = 0; j < 3; j++)
		{
			printf("\nstudent:%s\n", arr[i].studentNames[j]);
		}
	}
}

void sortTeacher(Teacher* arr, int num)
{
	int i = 0, j = 0;
	Teacher temp;

	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (arr[i].age > arr[j].age)
			{
				temp = arr[i];//=赋值操作
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


Teacher* createTeacher(int num)
{
	Teacher* temp = NULL;
	temp = (Teacher*)malloc(sizeof(Teacher) * num);
	if (temp == NULL)
	{
		return NULL;
	}
	return temp;
}


int createTeacherP(Teacher** pTeacher, int num)
{
	Teacher* temp = NULL;
	temp = (Teacher*)malloc(sizeof(Teacher) * num);
	if (temp == NULL)
	{
		return -1;
	}
	memset(temp, 0, sizeof(Teacher) * num);

	for (int i = 0; i < num; i++)
	{
		temp[i].alisname = (char*)malloc(60);
		char** tp = (char**)malloc(sizeof(char*) * 3);
		for (int j = 0; j < 3; j++)
		{
			tp[j] = (char*)malloc(120);
		}
		temp[i].studentNames = tp;
	}

	*pTeacher = temp;//二级指针 形参 去间接修改 实参 的值
	return 0;
}

void freeTeacher(Teacher* p, int num)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		//释放一级指针
		if ((p + i)->alisname != NULL)
		{
			free((p + i)->alisname);
			(p + i)->alisname = NULL;
		}
		//释放二级指针

		if ((p + i)->studentNames != NULL)
		{
			char** temp = p[i].studentNames;
			for (int j = 0; j < 3; j++)
			{
				if (temp[j]!=NULL)
				{
					free(temp[j]);
				}
			}
			free(temp);
			(p + i)->studentNames = NULL;
		}
	}
	free(p);
}

void maindy037()
{
	int ret = 0;
	int i = 0;
	int num = 1;
	Teacher* pArr;//在临时区，栈上分配内存

	ret = createTeacherP(&pArr, num);

	if (ret != 0)
	{
		printf("function createTeacherP() er:%d\n", ret);
		return;
	}

	for (i = 0; i < num; i++)
	{
		printf("\npleace enter age:");
		scanf("%d", &(pArr[i].age));

		printf("\npleace enter name:");
		scanf("%s", &(pArr[i].name));//向指针所指向的内存空间copy

		printf("\npleace enter alisname:");
		scanf("%s", pArr[i].alisname);

		for (int j = 0; j < 3; j++)
		{
			printf("pleace student name:");
			scanf("%s", pArr[i].studentNames[j]);
		}

	}

	printTeacher(pArr, num);
	sortTeacher(pArr, num);
	printf("排序之后：\n");
	printTeacher(pArr, num);
	printf("\n");
	freeTeacher(pArr, num);
	pArr = NULL;
	system("pause");
}
