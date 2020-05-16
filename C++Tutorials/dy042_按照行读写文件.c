
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void maindy042()
{
	int i = 0;
	FILE* fp = NULL;
	char* flname = "c:/1.txt";
	char a[27] = "kangzhenqiang";
	char buf[1024];
	//fp = fopen(flname, 'r+');//读写的方式打开不存在就会报错
	fp = fopen(flname, "r+");//读写的方式打开不存在创建新文件
	if (fp == NULL)
	{
		printf("func fopen() err:%d\n");
		return;
	}
	printf("打开成功！\n");

	while (!feof(fp))
	{
		//c函数库会一行一行的copy数据到buf所指向的内存空间中 并且变成c风格的字符串
		//把\n也copy到我们的buf中
		//内存打包（把函数首地址+内存的长度）
		char* p = fgets(buf, 1024, fp);
		if (p==NULL)
		{
			goto End;
		}
		/*char tempc = fgetc(fp);
		printf("%c", tempc);*/
		printf("%s", buf);
	}
End:
	{
		if (fp!=NULL)
		{
			fclose(fp);
		}
		return;
	}
	/*
	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	*/
	//fputs(a, fp);
	fclose(fp);
	system("pause");
}
