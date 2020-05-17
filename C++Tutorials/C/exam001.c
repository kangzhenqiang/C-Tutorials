//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//1.有一个字符串开头或结尾包含n个空格（"    ancesdlfefe    "）,欲去掉前后空格，返回一个新字符串。
//要求：1.请自己定义一个接口（函数）并实现
//		2.编写测试用例
//两头堵模型 strncpy(newstr,str+i,ncount)
//目前这种写法会去除中间的空格

//去除空格
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