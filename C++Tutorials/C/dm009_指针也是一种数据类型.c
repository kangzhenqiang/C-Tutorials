//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void maindm00901()
{
	int a = 10;
	char* p1 = 100;
	char**** p2 = 200;

	int* p3 = NULL;
	p3 = &a;

	printf("a:%d\n", a);
	*p3 = 20;//��ӵ��޸�a��ֵ
	//*����һ��Կ�ף�ͨ��һ����ַ��&a��,ȥ�޸�a�����ı�ʾ���ڴ�ռ�

	{
		//*p����=����� д�ڴ�
		//*p��=�ŵ��ұ� ���ڴ�
		int c = 0;
		c = *p3;
		printf("c:%d\n", c);
	}
	{
		//���ϵĸ�ָ�븳ֵ�൱�ڲ�ͣ�ĸı�ָ���ָ��
		char* p4 = NULL;
		p4 = (char*)malloc(sizeof(char) * 100);
		p4 = (char*)malloc(sizeof(char) * 100);
	}

	printf("a:%d\n", a);

	printf("a:%d,p1:%d,p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));

	system("pause");
}

char* getStrdm009()
{
	char* p = NULL;
	p = "abcd";
	return p;
}

//ָ������������
//�γ����������� �β��ж༶ָ���ʱ��վ�ڱ������ĽǶȣ�ֻ��Ҫ����4���ֽڵ��ڴ棨32ƽ̨��
//������ʹ���ڴ��ʱ�����ǲŹ���ָ��ָ����ڴ���һά���Ƕ�ά��
//ָ��Ҳ��һ���������ͣ���ָ��ָ���ڴ�ռ��������ȷ��
//ָ�����;�����ָ��Ĳ���

int getABC1(char* P1);
int getABC2(char** P2);
int getABC3(char*** P3);
int getABC4(char(*p4)[30]);
int getABC5(char p5[10][30]);

void maindm009()
{
	char* p = getStrdm009();
	printf("%s\n", p);

	/**(p + 2) = 'r';*///�������ִ��󣬱�ָ֤����ָ����ڴ�ռ���Ա��޸�
	printf("%s\n", p);
	system("pause");
}

int getABC1(char* P1)
{
	return 0;
}

int getABC2(char** P2)
{
	return 0;
}

int getABC3(char*** P3)
{
	return 0;
}

int getABC4(char(*p4)[30])
{
	return 0;
}

int getABC5(char p5[10][30])
{
	return 0;
}
