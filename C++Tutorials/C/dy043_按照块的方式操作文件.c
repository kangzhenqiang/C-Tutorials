
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// void socketclient_send(void* handle, unsigned char* buf, int len);
// void socketclient_send(void* handle, char* buf, int len);//��0��β���ַ���
typedef struct TeacherTeacher {
	char name[64];
	int age;
} TeacherTeacher;

void main_fwrite()
{
	FILE* fp = NULL;
	char* wangjing = "c:/3.data";

	TeacherTeacher tArr[3];

	for (int i = 0; i < 3; i++)
	{
		sprintf(tArr[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		tArr[i].age = i + 31;
	}

	fp = fopen(filename, "wb");

	if (fp == NULL)
	{
		printf("�����ļ�ʧ��\n");
	}
	int myN = 0;
	for (int i = 0; i < 3; i++)
	{
		//_str�����ڴ��Ŀ�ʼ
		//_size:�ڴ�������
		//_count:д�Ĵ���
		//_file:д�뵽�ļ�ָ����ָ����ļ���

		//��������ֵ
		myN = fwrite(&tArr[i], sizeof(TeacherTeacher), 1, fp);
		//�жϴ�����û��д��

	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void main_fread()
{
	FILE* fp = NULL;
	char* filename = "c:/3.data";

	TeacherTeacher tArr[3];

	fp = fopen(filename, "r+b");

	if (fp == NULL)
	{
		printf("�����ļ�ʧ��\n");
	}
	int myN = 0;
	for (int i = 0; i < 3; i++)
	{
		myN = fread(&tArr[i], sizeof(TeacherTeacher), 1, fp);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("teacher.name:%s,teacher.age%d\n", tArr[i].name, tArr[i].age);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void main()
{
	main_fwrite();
	main_fread();
	system("pause");
}
