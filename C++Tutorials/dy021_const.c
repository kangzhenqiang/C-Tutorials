#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void getConstModel(const char* p)
{
	p = 1;
}


void maindy021()
{
	/*
	//���α������ܱ��޸�
	const int a;
	//���α������ܱ��޸�
	int const b;
	//��������д��һ��������һ����������

	//c��һ��ָ����������ָ�루��ָ����ڴ����ݲ��ܱ��޸ģ���������Ա��޸ģ�
	const char* c;

	//d�ǳ�ָ�루ָ��������ܱ��޸ģ���������ָ����ڴ�ռ���Ա��޸ģ�
	char* const d;//char buf[100];

	//e��һ��ָ�����εĳ�ָ�루ָ�������ָ����ڴ�ռ䣬�����ܱ��޸ģ�
	const char* const e;

	//ָ�����������ָ����ڴ�ռ��������������ͬ�ĸ���
	//��const�Ƿ���*����߻����ұ� ��const������ָ�����������������ָ����ڴ�ռ����
	*/
	char* p = NULL;
	const char* p2 = NULL;
	p2 = 1;

	//����C�����е�const���εı������Ǽٵģ�c������const��һ��ð�ƻ�
	const int a = 100;
	//a = 200;

	{
		int* p = &a;
		*p = 200;
		printf("a:%d\n", a);
	}

	system("pause");
}