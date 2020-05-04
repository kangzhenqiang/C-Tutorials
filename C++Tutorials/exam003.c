//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//3.键值对（"key=value"）字符串，在开发中经常使用
//要求1：自己定义一个接口，实现key获取value
//要求2：编写测试用例
//要求3：键值对中间可能有n个空格，请去除空格

int trimSpaceInKeyValue(char* inbuf/*in*/, char* outbuf/*out*/)
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
	while (!isspace(*tempIn) && *tempIn != '\0' && *tempIn != "")
	{
		outbuf[i] = *tempIn;
		i++;
		tempIn++;
	}

	outbuf[i] = '\0';
	return 0;
}


int getKeyByVaule(char* keyvaluebuf, char* keybuf, char* valuebug, int* valuebuflen)
{
	int ret = 0;
	if (keyvaluebuf == NULL || keybuf == NULL || valuebug == NULL || valuebuflen == NULL)
	{
		ret = -1;
		printf("getKeyBuValue fun error:%d\n", ret);
		return ret;
	}
	char* temp = strstr(keyvaluebuf, keybuf);

	if (temp == NULL)
	{
		ret = -2;
		printf("the key is not in string");
		return ret;
	}

	char* value = strstr(keyvaluebuf, "=") + 1;
	ret = trimSpaceInKeyValue(value, valuebug);
	*valuebuflen = strlen(valuebug);
	return ret;
}


int main003()
{
	int ret = 0;
	char* source = "key1=    value1   ";
	char* key = "key1";
	char buf[128];
	int valuebufLen = 0;
	printf("source is：%s\n", source);

	ret = getKeyByVaule(source, key, buf, &valuebufLen);

	printf("key %s value is:%s,the value len is:%d\n.", key, buf, valuebufLen);
	system("pause");
	return ret;
}