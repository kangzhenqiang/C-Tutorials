//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//1.��һ���ַ�����ͷ���β����n���ո�"    ancesdlfefe    "��,��ȥ��ǰ��ո񣬷���һ�����ַ�����
//Ҫ��1.���Լ�����һ���ӿڣ���������ʵ��
//		2.��д��������
//��ͷ��ģ�� strncpy(newstr,str+i,ncount)
//Ŀǰ����д����ȥ���м�Ŀո�

//ȥ���ո�
int trimSpace(char* inbuf/*in*/, char* outbuf/*out*/)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		printf("trimSpace fun error:%d(inbuf or outbuf is Null).\n", -1);
		return -1;
	}
	char* tempIn = inbuf;
	while (isspace(*tempIn))
	{
		tempIn++;
	}
	int i = 0;
	while (!isspace(*tempIn))
	{
		outbuf[i] = *tempIn;
		i++;
		tempIn++;
	}

	outbuf[i] = '\0';
	return 0;
}

int trimSpaceCorrect(char* inbuf/*in*/, char* outbuf/*out*/)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		printf("trimSpace fun error:%d(inbuf or outbuf is Null).\n", -1);
		return -1;
	}
	char* tempIn = inbuf;
	int i = 0;
	int j = strlen(tempIn) - 1;
	int nCount = 0;
	while (isspace(tempIn[i])&&tempIn[i]!='\0')
	{
		i++;
	}
	while (isspace(tempIn[j]) && tempIn[j] != '\0')
	{
		j--;
	}
	nCount = j - i;
	strncpy(outbuf, tempIn+i, nCount);
	outbuf[nCount] = '\0';
	return 0;
}

int main001()
{
	int ret = 0;
	char* p = "   abcdsdefef   ";
	char buf[128];

	printf("string is:%s.\n", p);

	ret = trimSpaceCorrect(p, buf);

	printf("trim space string is:%s.\n", buf);

	system("pause");

	return ret;
}