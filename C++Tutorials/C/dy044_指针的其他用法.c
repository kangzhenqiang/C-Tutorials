
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int getContentLen01(const char* fileName, char** buf, int* len)
{
	int ret = 0;
	char* temp = NULL;
	if (fileName == NULL || len == NULL)
	{
		ret = -1;
		return ret;
	}
	temp = (char*)malloc(sizeof(char) * 100);
	if (temp = NULL)
	{
		ret = -2;
		return ret;
	}
	strcpy(temp, "kangzhenqiangwangjingjign");
	*buf = temp;
	*len = strlen(temp);
	return ret;
}

int getContentLen02(const char* fileName, char* buf, int* len)
{
	int ret = 0;
	char* temp = NULL;
	if (buf == NULL)
	{
		*len = 10;
	}
	else
	{
		strcpy(temp, "kang", 10);
		*buf = temp;
		*len = strlen(temp);
	}
	return ret;
}


//һ�����ϲ�Ӧ�ò�������malloc,��Ҫ����ʹ��malloc
void maindy044()
{
	int ret = 0;
	char* flieName = "";
	int len = 0;
	char* p = NULL;
	ret = getContentLen01(flieName, p, &len);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	//��һ�ε��û�ȡ����
	getContentLen02(flieName, NULL, &len);
	p = (char*)malloc(sizeof(char) * len);
	if (p==NULL)
	{
		return;
	}
	//�ڶ��ε���������
	getContentLen02(flieName, p, &len);

	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
}
