//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void maindm016()
{
	char buf1[20] = "aaaa";
	char buf2[] = "bbbb";
	char* p1 = "1111";
	char* p2 = (char)malloc(100);
	strcpy(p2, "3333");
	system("pause");
}