//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//两头堵模型，可以拷贝到新的内存空间，
//可以拷贝到自己内存空间，str所指向的内存空间可以被修改才行

//当字符串被分配到字符常量区时不允许修改
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
	strIn[ncount] = '\0';//内存空间不允许被修改
	return ret;
}


void maindy019()
{
	//内存常量区不允许修改
	char* strIn = "    aaaaaferferfger   ";
	//显示分配内存
	char buf[1024]= "    aaaaaferferfger   ";
	int ret = trimSpaceError(buf);

	printf("strIn is:%s.\n", buf);

	system("pause");
}