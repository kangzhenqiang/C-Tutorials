//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��һ���ַ�����1a2b3c4d��:
//Ҫ��дһ������ʵ�ֹ��ܣ�
//����1����ż��λ�ַ���ѡ���������һ���ַ���1
//����2��������λ�ַ�����ѡ���������һ���ַ���2
//����3�����ַ���1���ַ���2ͨ���������������ݸ�main������ӡ
//����4���������ܲ���ͨ����

int getSubStr(char* souce, char* buf1, char* buf2)
{
	int ret = 0;
	if (souce == NULL || buf1 == NULL || buf2 == NULL)
	{
		ret = -1;
		printf("getSubStr fun error:%d(souce or buf1 or buf2 is null).\n", -1);
	}
	char* temp = souce;
	int index1 = 0;
	int index2 = 0;
	for (size_t i = 0; i < strlen(temp); i++)
	{
		if (i % 2 == 0)//����λ
		{
			buf1[index1] = *(temp+i);
			index1++;
		}
		else//ż��λ
		{
			buf2[index2] = *(temp+i);
			index2++;
		}
	}
	buf1[index1] = '\0';
	buf2[index2] = '\0';
	return ret;
}


void main002()
{
	int ret = 0;

	char* souce = "1a2b3c4d";
	char buf1[128];
	char buf2[128];

	printf("souce is:%s\n", souce);
	ret = getSubStr(souce, buf1, buf2);

	printf("buf1 is:%s\n", buf1);
	printf("buf2 is:%s\n", buf2);

	system("pause");
}