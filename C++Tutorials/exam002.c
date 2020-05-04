//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//有一个字符串“1a2b3c4d”:
//要求写一个函数实现功能，
//功能1：把偶数位字符挑选出来，组成一个字符串1
//功能2：把奇数位字符串挑选出来，组成一个字符串2
//功能3：把字符串1和字符串2通过函数参数，传递给main，并打印
//功能4：主函数能测试通过。

int getSubStr(char* souce, char* buf1, char* buf2)
{
	int ret = 0;
	if (souce == NULL || buf1 == NULL || buf2 == NULL)
	{
		ret = -1;
		printf("getSubStr fun error:%d(souce or buf1 or buf2 is null).\n", -1);
	}
	char* temp = souce;
	int index1 = 0;
	int index2 = 0;
	for (size_t i = 0; i < strlen(temp); i++)
	{
		if (i % 2 == 0)//奇数位
		{
			buf1[index1] = *(temp+i);
			index1++;
		}
		else//偶数位
		{
			buf2[index2] = *(temp+i);
			index2++;
		}
	}
	buf1[index1] = '\0';
	buf2[index2] = '\0';
	return ret;
}


void main002()
{
	int ret = 0;

	char* souce = "1a2b3c4d";
	char buf1[128];
	char buf2[128];

	printf("souce is:%s\n", souce);
	ret = getSubStr(souce, buf1, buf2);

	printf("buf1 is:%s\n", buf1);
	printf("buf2 is:%s\n", buf2);

	system("pause");
}