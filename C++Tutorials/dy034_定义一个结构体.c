
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//����һ���ṹ������
//������һ���������� �̶���С�ڴ��ı��� ��û�з����ڴ�

//���Ͷ���
typedef struct  Teacher
{
	char name[64];
	int age;
	int id;
} Teacher;


#pragma region  ������������ַ���
Teacher t;

//�������͵�ͬ�¶������
struct  Student
{
	char name[64];
	int age;
	int id;
} s1, s2;

struct
{
	char name[64];
	int age;
	int id;
} s3, s4;
#pragma endregion

#pragma region ��ʼ����������

Teacher teacher = { "kangzhenqiang",31,01 };

struct  Man
{
	char name[64];
	int age;
	int id;
} s5 = { "kang",32,02 };

struct
{
	char name[64];
	int age;
	int id;
} s6 = { "wang",32,003 };

#pragma endregion

void maindy034001()
{
	//�����Ͷ������
	Teacher t1;//���߱����������ڴ�
	Teacher t2 = { "kangzhenqiang",32,001 };

	t1.age = 31;//t1. �������Ǹ�ʲô ��û�в����ڴ�
				//��Ѱַ���� ����age�����t1�������ƫ���� ===> ����cpu�н���
				//û�в����ڴ�
	strcpy(t1.name, "kangzhenqiang");
	printf("t1.name:%s\n", t1.name);

	//ͨ��ָ��ķ�ʽ�����ڴ�ռ�
	{
		Teacher* p = NULL;
		p = &t2;
		printf("p->age:%d\n", p->age);
		printf("p->name:%s\n", p->name);
	}

	system("pause");
}

void copyTeacher(Teacher to, Teacher from)
{
	to = from;
}

void copyTeacher02(Teacher* to, Teacher* from)
{
	//��*to�� = ��*from);
	*to = *from;
}

//�ڴ�����ģ��

void maindy034002()
{
	Teacher t1 = { "kangzhenqiang",32,02 };
	Teacher t2;
	Teacher t3;

	t2 = t1;//=�Ų����� ����������Ϊ

	//�������������ṩ�� = �� ��ֵ���� ����Ҫ˳��

	printf("t2.name:%s\n", t2.name);
	printf("t2.age:%d\n", t2.age);

	copyTeacher02(&t3, &t1);

	printf("t3.name:%s\n", t3.name);
	printf("t3.age:%d\n", t3.age);


	system("pause");
}
