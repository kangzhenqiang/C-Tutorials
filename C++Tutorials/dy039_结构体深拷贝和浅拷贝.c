
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Person
{
	char name[64];
	int age;
	char* alias;

} Person;

//ǳ����
//��������=������ָ�Ӱ�ָ�������ֵ��from copy��to,
//�������ָ�������ָ���ڴ�ռ��������ȥ
//�ṹ������һ��1��ָ���2��ָ��
//�����ִ�������cpoy��������ʾ�����ڴ�
void copyPerson(Person* to, Person* from)
{
	*to = *from;
	//memcpy(to, from, sizeof(Person));
	//���
	to->alias = (char*)malloc(100);
	strcpy(to->alias, from->alias);
}

//���������ǳ����
void maindy039()
{
	Person p1;
	Person p2;
	strcpy(p1.name, "kangzhenqiang");
	p1.alias = (char*)malloc(100);
	strcpy(p1.alias, "wangjing");

	copyPerson(&p2, &p1);

	if (p1.alias != NULL)
	{
		free(p1.alias);
		p1.alias = NULL;
	}

	if (p2.alias != NULL)
	{
		free(p2.alias);
		p2.alias = NULL;
	}

	system("pause");
}
