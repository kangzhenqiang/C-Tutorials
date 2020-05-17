//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//3.��ֵ�ԣ�"key=value"���ַ������ڿ����о���ʹ��
//Ҫ��1���Լ�����һ���ӿڣ�ʵ��key��ȡvalue
//Ҫ��2����д��������
//Ҫ��3����ֵ���м������n���ո���ȥ���ո�

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

int trimSpaceCorrectInKeyValue(char* inbuf/*in*/, char* outbuf/*out*/)
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
	while (isspace(tempIn[i]) && tempIn[i] != '\0')
	{
		i++;
	}
	while (isspace(tempIn[j]) && tempIn[j] != '\0')
	{
		j--;
	}
	nCount = j - i;
	strncpy(outbuf, tempIn + i, nCount);
	outbuf[nCount] = '\0';
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

	//����key�ǲ�����ĸ����
	char* temp = strstr(keyvaluebuf, keybuf);

	if (temp == NULL)
	{
		ret = -2;
		printf("the key is not in string.\n");
		return ret;
	}
	//������û��"="��
	char* value = strstr(keyvaluebuf, "=") + 1;
	if (value == NULL)
	{
		ret = -3;
		printf("the string is not contain '='.\n");
		return ret;
	}

	//ȥ���ո�
	ret = trimSpaceCorrect(value, valuebug);
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
	printf("source is��%s\n", source);

	ret = getKeyByVaule(source, key, buf, &valuebufLen);

	printf("key %s value is:%s,the value len is:%d\n.", key, buf, valuebufLen);
	system("pause");
	return ret;
}