//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* p = "abcd111122abcd3333322qq";//���ַ�����abcd���ֵĴ���

void maindm01801()
{
	int count = 0;
	char* p = "abcd111122abcd3333322qq";//���ַ�����abcd���ֵĴ���
	do
	{
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			count++;
			p = p + strlen("abcd");
		}
		else {
			break;
		}
	} while (*p != '\0');
	printf("cbcd occure %d count!\n", count);
	system("pause");
}

void maindm01802()
{
	int count = 0;
	char* p = "abcd111122abcd3333322qq";//���ַ�����abcd���ֵĴ���

	while (p = strstr(p, "abcd"))
	{
		count++;
		p = p + strlen("abcd");
		if (p == NULL)
		{
			break;
		}
	}

	printf("cbcd occure %d count!\n", count);
	system("pause");
}


int getSubStrCount(char *myStr /*in*/, char *subStr/*in*/, int *count)
{
	int ret = 0;

	if(myStr == NULL|| subStr == NULL||count==NULL)
	{
		ret = -1;
		printf("func getCount() err:%d(myStr==NULL|| subStr==NULL||count=NULL)\n", ret);
	}
	char* p = myStr;//��Ҫ���׸ı��β�ָ�����
	char tempCount = 0;

	while (p = strstr(p, "abcd"))
	{
		tempCount++;
		p = p + strlen("abcd");
		if (p == NULL)
		{
			break;
		}
	}
	*count = tempCount;//��Ӹ�ֵ��ָ����ڵ��������
	return 0;
}
int maindm01803()
{
	int ret = 0;
	//��ʼ��
	int count = 0;
	char* p = "abcd111122abcd3333322qq";//���ַ�����abcd���ֵĴ���
	char sub[] = "abcd";
	getSubStrCount(p, NULL, &count);
	printf("cbcd occure %d count!\n", count);
	system("pause");
}

