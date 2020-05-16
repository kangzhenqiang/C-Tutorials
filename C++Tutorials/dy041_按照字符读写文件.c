
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	按文件的逻辑结构：
		记录文件：由具有一定结构的记录组成（定长和不定长）
		流式文件：由一个个字符（字节）数据顺序组成
	按存储介质：
		普通文件：存志介质文件（磁盘、磁带）
		设备文件：非存储介质（键盘、显示器、打印机等）
	按数据的组指形式：
		文本形式：AACII文件，每个字节存放一个字符的ASCII
		二进制文件：数据按其在内存中的存储形式原样存放
*/
void maindy041001()
{
	FILE* fp = NULL;
	//char* filenameTemp = "c:\\1.txt";
	char* filename = "c:/2.txt";//同一用45度
	char a[27] = "wangjing";

	fp = fopen(filename, "r+");

	if (fp == NULL)
	{
		printf("func fopen() err:%d");
		return;
	}

	printf("打开成功\n");

	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);
	system("pause");
}

void maindy041002()
{
	FILE* fp = NULL;
	//char* filenameTemp = "c:\\1.txt";
	char* filename = "c:/2.txt";//同一用45度
	char a[27] = "wangjing";

	fp = fopen(filename, "r+");//以读和写的方式

	if (fp == NULL)
	{
		printf("func fopen() err:%d");
		return;
	}

	printf("打开成功\n");

	while (!feof(fp))
	{
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}

	if (fp!=NULL)
	{
		fclose(fp);
	}
	
	system("pause");
}
