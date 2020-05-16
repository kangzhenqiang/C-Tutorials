//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//
//
//typedef struct Teacher {
//	char name[64];
//	int age;
//	int id;
//} Teacher;
//
//
//void printTeacher(Teacher* arr, int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("\nage:%d", arr[i].age);
//	}
//}
//
//void sortTeacher(Teacher* arr, int num)
//{
//	int i = 0, j = 0;
//	Teacher temp;
//
//	for (i = 0; i < num; i++)
//	{
//		for (j = i + 1; j < num; j++)
//		{
//			if (arr[i].age>arr[j].age)
//			{
//				temp = arr[i];//=赋值操作
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//}
//
//
//Teacher* createTeacher(int num)
//{
//	Teacher* temp = NULL;
//	temp = (Teacher*)malloc(sizeof(Teacher) * num);
//	if (temp==NULL)
//	{
//		return NULL;
//	}
//	return temp;
//}
//
//void freeTeacher(Teacher *p)
//{
//	if (p!=NULL)
//	{
//		free(p);
//	}
//}
//
//void maindy035001()
//{
//	int i = 0;
//	int num = 3;
//	Teacher arr[3];//在临时区，栈上分配内存
//
//	for (i = 0; i < num; i++)
//	{
//		printf("\npleace enter age:");
//		scanf("%d", &(arr[i].age));
//	}
//	printTeacher(arr, num);
//	sortTeacher(arr, num);
//	printf("排序之后：\n");
//	printTeacher(arr, num);
//	printf("\n");
//	system("pause");
//}
//
//void maindy035002()
//{
//	int i = 0;
//	int num = 3;
//	Teacher *pArr;//在临时区，栈上分配内存
//	pArr = createTeacher(num);
//	if (pArr==NULL)
//	{
//		return;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		printf("\npleace enter age:");
//		scanf("%d", &(pArr[i].age));
//	}
//	printTeacher(pArr, num);
//	sortTeacher(pArr, num);
//	printf("排序之后：\n");
//	printTeacher(pArr, num);
//	printf("\n");
//	freeTeacher(pArr);
//	pArr = NULL;
//	system("pause");
//}
