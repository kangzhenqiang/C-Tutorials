//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getFileLength(int* p) {
	*p = 50;//p��ֵ��a�ĵ�ַ����޸�a��ֵ���βμ��ȡ�޸�ʵ�ε�ֵ
}

//���ж������ԣ���ʼ���ͺ�������int pû������
int getFile(int p) {
	p = 60;//p��ֵ��a�ĵ�ַ����޸�a��ֵ
}

//һ��ָ�뼼������
void maindm01201()
{
	int a = 0;
	int* p = NULL;

	//ֱ���޸�
	a = 20;

	printf("a:%d\n", a);

	p = &a;
	*p = 30;

	{
		*p = 40;
	}

	getFileLength(&a);

	printf("a:%d\n", a);

	getFile(a);
	printf("a:%d\n", a);

	system("pause");
}

void getMember(int** p)
{
	*p = 300;
}


//һ��ָ�뵽����ָ������
void maindm01202()
{
	char* p1 = NULL;//����1 ��������������
	char** p2 = NULL;

	//ֱ���޸�p1��ֵ

	//����޸�p1��ֵ

	p2 = &p1;//��������

	*p2 = 20;//p2��p1�ĵ�ַ��ͨ��*p���ȡ�޸�ֵ

	printf("p1:%d\n", p1);


	{
		*p2 = 200;
		printf("p1:%d\n", p1);
	}

	getMember(&p1);
	printf("p1:%d\n", p1);

	system("pause");
	return;
}