//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//һ��ָ������÷�
//���� int a[10]
//�ַ���
//1 C���Ե��ַ��� �����β���ַ���
//2 ��C������û���ַ������� ͨ���ַ����� ��ģ���ַ���
//3 �ַ������ڴ���� ���� ջ�� ȫ����������Ҫ��

//�ַ����� ��ʼ��
void maindm015()
{
	//1 ָ������
	char buf1[100] = { 'a','b','c','d' };
	char buf2[3] = { 'a','b' ,'\0' };
	//�����ʼ���ĸ��������ڴ�ĸ��� �������
	//δ��ʼ����bufΪ0

	//2 ��ָ������ C���������Զ������Ա��Ԫ�ظ���
	char buf3[] = { 'a','b','c','d','\0' };//buf3����һ������ ����һ����0��β���ַ���

	printf("buf1:%s\n", buf1);
	printf("buf2:%s\n", buf2);
	printf("buf3:%s\n", buf3);

	//���ַ�������ʼ���ַ�����
	char buf4[] = "abcd";//buf4��Ϊ�ַ�����Ӧ����5���ֽ� //��Ϊ�ַ��� Ӧ��4���ֽ�
	int len = sizeof(buf4);
	printf("buf4:%s��len:%d\n", buf4, len);
	//������һ���������� �̶���С�ڴ�����

	char buf5[128] = "abcd";
	len = sizeof(buf5);
	printf("buf5:%s��len:%d\n", buf4, len);

	system("pause");
}


void maindm01502()
{
	int i = 0;
	char buf5[128] = "abcde";
	char* p = NULL;

	for (size_t i = 0; i < strlen(buf5); i++)
	{
		printf("%c\n", buf5[i]);
	}

	p = buf5;//buf ������Ԫ�ص�ַ
	for (size_t i = 0; i < strlen(buf5); i++)
	{
		printf("%c\n", *(p + i));
	}

	system("pause");
}

//[] *���Ƶ����
//buf[i] ====>buf[0+i] ====>*(buf+i)
//buf ��һ������ָ�룬ֻ���ĳ��� buf��һ������ָ��

//p��ָͨ����ڴ��׵�ַ����