
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct AdvTeacher {
	char name[64];
	int age;
	int p;
	char* pName;
} AdvTeacher;

void maindy040001()
{
	AdvTeacher t1;
	//ָ�����һ������
	AdvTeacher* teacher = NULL;
	//strcpy(0,"aaaa");��������

	teacher - 1;//����ͨ�� ����ͨ�� ��仰����cpu�м���

	{
		int offsize = (int)&(teacher->age);
		printf("offsize:%d\n", offsize);
	}

	system("pause");
}

void maindy040002()
{
	AdvTeacher t1;
	//ָ�����һ������
	AdvTeacher* teacher = NULL;
	//strcpy(0,"aaaa");��������

	teacher - 1;//����ͨ�� ����ͨ�� ��仰����cpu�м���

	{
		int offsize = (int)&(((AdvTeacher*)0)->age);
		//int offsize = (int)&(teacher->age);
		printf("offsize:%d\n", offsize);
	}

	system("pause");
}
