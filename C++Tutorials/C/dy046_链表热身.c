
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
struct Teacher
{
	char name[64];
	int id;
	char* p;
	char** p2;
};


typedef struct Teacher Teacher;
*/

typedef struct Student
{
	char name[64];
	int id;
} Student;

typedef struct Teacher
{
	char name[64];
	int id;
	char* p;
	char** p2; 
	Student s;
	Student* ps;
} Teacher;




//1 �ṹ����Ƕ��һ���ṹ��
//2 �ṹ���ָ��
//3 �ṹ����һ�� �Լ����͵ýṹ��Ԫ���ǲ��е�
//�������͵ñ��ʣ��̶���С�ڴ��ñ���
//4 �ṹ������һ��ָ���Լ����͵�ָ��

//���Լ����ʹ�С��û��ȷ��������� �����Լ����͵�Ԫ�� �ǲ���ȷ��
//�ṹ�岻����Ƕ�׶��壨ȷ�������������͵ķ��䲻���ڴ棩

typedef struct AdcTeacger {
	char name[64];
	int id;
	struct AdcTeacger* adcTeacher;
} AdcTeacger;


//������Ƕ�׵��� �� �ṹ��������Ƕ�׶��岻��һ����

void maindy046()
{
	char* p = NULL;
	system("pause");
}
