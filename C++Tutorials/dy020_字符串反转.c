#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char g_buf[1024];

//字符串反转
int inverse(char* str)
{
	if (str == NULL)
	{
		printf("fun str is NULL.");
		return -1;
	}

	int length = strlen(str);

	char* p1 = str;
	char* p2 = str + length - 1;

	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	return 0;
}

//通过递归的方式，逆向打印
//递归和全局变量（把逆序的结果存入全局变量）
//递归和非全局变量（递归指针做函数参数）
//理解递归2个点：1.参数入栈模型 2.函数调用模型 3.函数嵌套调用返回流程
int inverse02(char* p)
{
	int ret = 0;
	if (p == NULL)//递归结束的异常条件
	{
		return -1;
	}
	if (*p == '\0')//递归结束条件
	{
		return 0;
	}
	inverse02(p + 1);//注意 此时没有执行打印，而是执行了让字符串的每一个地址入栈
	printf("%c", *p);
	return ret;
}

//使用全局变量和递归
void inverse03(char* p)
{
	int ret = 0;
	if (p == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*p == '\0')//递归结束条件
	{
		return;
	}
	inverse03(p + 1);//注意 此时没有执行打印，而是执行了让字符串的每一个地址入栈
	//strncpy(g_buf, p,1);//往同一个位置拷贝
	strncat(g_buf, p, 1);//连接
}

void inverse04(char* p, char* out)
{
	int ret = 0;
	if (p == NULL|| out==NULL)//递归结束的异常条件
	{
		return;
	}
	if (*p == '\0')//递归结束条件
	{
		return;
	}
	inverse04(p + 1, out);//注意 此时没有执行打印，而是执行了让字符串的每一个地址入栈
	//strncpy(g_buf, p,1);//拷贝
	strncat(out, p, 1);//连接
}

void maindy020()
{
	char buf[] = "abcdef";
	//inverse(buf);
	//inverse02(buf);
	//memset(g_buf, 0, sizeof(g_buf));
	//inverse03(buf);


	char mybuf[1024] = { 0 };
	inverse04(buf, mybuf);


	printf("buf:%s.\n", mybuf);
	//printf("buf:%s.\n", g_buf);
	system("pause");
}
