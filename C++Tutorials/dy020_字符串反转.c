#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char g_buf[1024];

//�ַ�����ת
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

//ͨ���ݹ�ķ�ʽ�������ӡ
//�ݹ��ȫ�ֱ�����������Ľ������ȫ�ֱ�����
//�ݹ�ͷ�ȫ�ֱ������ݹ�ָ��������������
//���ݹ�2���㣺1.������ջģ�� 2.��������ģ�� 3.����Ƕ�׵��÷�������
int inverse02(char* p)
{
	int ret = 0;
	if (p == NULL)//�ݹ�������쳣����
	{
		return -1;
	}
	if (*p == '\0')//�ݹ��������
	{
		return 0;
	}
	inverse02(p + 1);//ע�� ��ʱû��ִ�д�ӡ������ִ�������ַ�����ÿһ����ַ��ջ
	printf("%c", *p);
	return ret;
}

//ʹ��ȫ�ֱ����͵ݹ�
void inverse03(char* p)
{
	int ret = 0;
	if (p == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0')//�ݹ��������
	{
		return;
	}
	inverse03(p + 1);//ע�� ��ʱû��ִ�д�ӡ������ִ�������ַ�����ÿһ����ַ��ջ
	//strncpy(g_buf, p,1);//��ͬһ��λ�ÿ���
	strncat(g_buf, p, 1);//����
}

void inverse04(char* p, char* out)
{
	int ret = 0;
	if (p == NULL|| out==NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0')//�ݹ��������
	{
		return;
	}
	inverse04(p + 1, out);//ע�� ��ʱû��ִ�д�ӡ������ִ�������ַ�����ÿһ����ַ��ջ
	//strncpy(g_buf, p,1);//����
	strncat(out, p, 1);//����
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
