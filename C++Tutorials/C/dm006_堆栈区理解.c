//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//���ָ��Ĺؼ����ڴ棬û���ڴ�������ָ��
//

//��
char *getMem(int num)
{
	char* p = NULL;
	p = (char *)malloc(sizeof(char) * num);
	if (p==NULL)
	{
		return NULL;
	}
	return p;
}

//ջ
//ע�⣺return���ǰ��ڴ��64���ֽڸ�return���������ǰ��ڴ����׵�ַ���ظ�temp
char* getStr()
{
	char buf[64];
	strcpy(buf, "kan");
	printf("buf:%s\n", buf);
	return buf;
}

void maindm006()
{
	char *temp = NULL;
	temp = getMem(20);
	if (temp==NULL)
	{
		return;
	}
	//��tempָ����ڴ�ռ��п�������	
	strcpy(temp, "1111");
	printf("temp:%s\n", temp);
	temp = getStr();
	printf("temp:%s\n", temp);
	system("pause");
}