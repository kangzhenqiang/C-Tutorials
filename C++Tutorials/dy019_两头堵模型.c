//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��ͷ��ģ�ͣ����Կ������µ��ڴ�ռ䣬
//���Կ������Լ��ڴ�ռ䣬str��ָ����ڴ�ռ���Ա��޸Ĳ���

//���ַ��������䵽�ַ�������ʱ�������޸�
int trimSpaceError(char* strIn/*in*/)
{
	int ret = 0;
	if (strIn == NULL)
	{
		ret = -1;
		printf("function errpr code:{%d} strIn is NUll.", ret);
		return ret;
	}

	int i = 0;
	int j = strlen(strIn)-1;
	while (isspace(strIn[i]) && strIn[i] != '\0')
	{
		i++;
	}

	while (isspace(strIn[j]) && strIn[j] != '\0')
	{
		j--;
	}
	int ncount = j - i;

	strncpy(strIn, strIn + i, ncount);
	strIn[ncount] = '\0';//�ڴ�ռ䲻�����޸�
	return ret;
}


void maindy019()
{
	//�ڴ泣�����������޸�
	char* strIn = "    aaaaaferferfger   ";
	//��ʾ�����ڴ�
	char buf[1024]= "    aaaaaferferfger   ";
	int ret = trimSpaceError(buf);

	printf("strIn is:%s.\n", buf);

	system("pause");
}