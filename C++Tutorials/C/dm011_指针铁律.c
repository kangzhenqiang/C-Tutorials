//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void maindm01001()
{
	//ָ������

	//ָ��ָ��NULLʱ�ڴ�ռ䲻���������ݣ���Ϊ���ڴ�������ϵͳ����
	char *p = NULL;
	strcpy(p, "kangzhenqiang");
	system("pause");
}

void maindm01002()
{
	int i;
	int j;
	char buf[128];

	char* p = NULL;

	char* p1 = NULL;

	p = &buf[0];//�����޸�p1��ָ���൱�ڲ��ϵ��޸�ָ���ָ��
	p = &buf[1];
	p = &buf[2];
	p = &buf[3];

	for (int i=0;i<10;i++)
	{
		p = &buf[i];
	}

	p1 = (char*)malloc(128);

	for (int i = 0; i < 10; i++)
	{
		p = p1[i];
	}

	system("pause");
}