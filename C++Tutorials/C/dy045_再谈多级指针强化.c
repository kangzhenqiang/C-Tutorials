
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void getLen(int *p)
{
	*p = 40;//*˭�ĵ�ַ �ͼ���޸�˭��ֵ
}


void maindy045001()
{
	int a = 10;
	int* p = NULL;
	printf("a:%d\n", a);
	a = 11;
	printf("a:%d\n", a);
	p = &a;
	printf("a:%d\n", a);
	*p = 30;
	printf("a:%d\n", a);
	{
		*p = 40;
		printf("a:%d\n", a);
	}
	system("pause");
}

int getMem045(char** p/*20*/)
{
	*p = 30;//��Ӹ�ֵ��p2��p�ĵ�ַ

	*p = (char**)malloc(1000);

}


void maindy045002()
{
	char* p = NULL;
	char** p2 = NULL;

	p = 1;//ֱ���޸�
	printf("a:%d\n", p);
	p2 = &p;

	*p2 = 30;
	printf("a:%d\n", p);
	{
		*p2 = 40;//����޸�ֵ
		printf("a:%d\n", p);
	}
	system("pause");
}