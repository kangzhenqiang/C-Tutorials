//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//基础写法
void maindm01701()
{
	char a[] = "I am s student";
	char b[64];
	int i = 0;
	for (i = 0; i < *(a + i) != '\0'; i++)
	{
		*(b + i) = *(a + i);
	}
	b[i] = '\0';//重要


	printf("a:%s\n", a);

	printf("b:%s\n", b);

	system("pause");
}


//字符串copy函数技术推演

//字符串copy函数
//form形参 to形参 不停的在变化..
//不断修改了from和to的指向
void str_copy(char* from, char* to)
{
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*(to) = '\0';
}

//*操作和++操作
//++优先级高

void string_Copy(char* from, char* to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;//先*to=*from,from++,to++
	}
	*to = '\0';
}

void strString_Copy(char* from, char* to)
{
	while ((*to = *from) != '\0')
	{
		from++;
		to++;
	}
}

void stringString_Copy(char* from, char* to)
{
	while ((*to++ = *from++) != '\0')
	{

	}
}

void strStringString_Copy(char* from, char* to)
{
	while ((*to++ = *from++))
	{

	}
}

void strStringString_Copy_err(char* from, char* to)
{
	while ((*to++ = *from++))
	{

	}
	printf("buf:%s\n", from);
}

//函数参数优化
//不要轻易改变形参的值，要引入形参辅助变量指针，把形参接过来
int stringStringString_Copy(char* from, char* to)
{
	char* tempFrom = from;
	char* tempTo = to;

	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*tempTo++ = *tempFrom++);//空语句
	printf("buf:%s\n", from);
	return 0;
}

void mainddm01702()
{
	char* from = "abcde";
	char buf[100];

	strStringString_Copy_err(from, buf);

	str_copy(from, buf);
	printf("buf:%s\n", buf);
	string_Copy(from, buf);
	printf("buf:%s\n", buf);
	strString_Copy(from, buf);
	printf("buf:%s\n", buf);
	stringString_Copy(from, buf);
	printf("buf:%s\n", buf);
	strStringString_Copy(from, buf);
	printf("buf:%s\n", buf);

	stringStringString_Copy(from, buf);
	{
		//错误案例
		char* to = NULL;
		int res = stringStringString_Copy(from, to);//要分配内存
		if (res != 0)
		{
			printf("fun stringStringString_Copy error%d", res);
		}
		printf("buf:%s\n", to);
	}

	system("pause");
}