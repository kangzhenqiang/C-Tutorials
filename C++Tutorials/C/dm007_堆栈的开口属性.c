//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//һ�������Ϊ��ջ�����������£�����release��debug
//һ����Ϊ��ջ�������� ����ջ�����
//����ջ�������ϻ�������,buf���ڴ��ַ��buf+1��Զ�����ϵ�
//ջ�����������buf���ڴ�����������������ͬ����

void maindm007()
{
	int a;
	int b;
	//ջȥ��������
	printf("&a:%d, &b:%d\n", &a, &b);

	char buf[128];//��̬�����ʱ��buf��������ڴ�ռ��ž��Ѿ�����������

	system("pause");
}