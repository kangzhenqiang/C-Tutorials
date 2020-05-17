//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* p = "abcd111122abcd3333322qq";//求字符串中abcd出现的次数

void maindm01801()
{
	int count = 0;
	char* p = "abcd111122abcd3333322qq";//求字符串中abcd出现的次数
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
	char* p = "abcd111122abcd3333322qq";//求字符串中abcd出现的次数

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
	char* p = myStr;//不要轻易改变形参指针变量
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
	*count = tempCount;//间接赋值是指针错在的最大意义
	return 0;
}
int maindm01803()
{
	int ret = 0;
	//初始化
	int count = 0;
	char* p = "abcd111122abcd3333322qq";//求字符串中abcd出现的次数
	char sub[] = "abcd";
	getSubStrCount(p, NULL, &count);
	printf("cbcd occure %d count!\n", count);
	system("pause");
}

