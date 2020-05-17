//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getContentLengthdm014(char** myContent1 /*out*/, int* myContentLength1/*out*/,
	char** myContent2 /*out*/, int* myContentLength2/*out*/)
{
	char* temp1 = NULL;
	char* temp2 = NULL;

	temp1 = (char*)malloc(sizeof(char) * 128);
	strcpy(temp1, "wangjing");
	*myContentLength1 = strlen(temp1);

	temp2 = (char*)malloc(sizeof(char) * 128);
	strcpy(temp2, "kangzhenqiang");
	*myContentLength2 = strlen(temp2);

	*myContent1 = temp1;
	*myContent2 = temp2;
}

char* getMemberMaclloc(int num)
{
	char* p = NULL;
	p = (char*)malloc(100);
	strcpy(p, "kangzhenqiang");
	return p;
}

void maindm014()
{
	
	char* content1 = NULL;
	int length1 = 0;
	char* content2 = NULL;
	int length2 = 0;

	getContentLengthdm014(&content1, &length1, &content2, &length2);

	printf("content1:%s,length:%d\n", content1, length1);
	printf("content1:%s,length:%d\n", content2, length2);

	if (content1 != NULL)
	{
		free(content1);
		content1 = NULL;
	}

	if (content2 != NULL)
	{
		free(content2);
		content2 = NULL;
	}

	char* p = getMemberMaclloc(100);

	printf("p:%s\n", p);
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}


	system("pause");
}