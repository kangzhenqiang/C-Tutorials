
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	���ļ����߼��ṹ��
		��¼�ļ����ɾ���һ���ṹ�ļ�¼��ɣ������Ͳ�������
		��ʽ�ļ�����һ�����ַ����ֽڣ�����˳�����
	���洢���ʣ�
		��ͨ�ļ�����־�����ļ������̡��Ŵ���
		�豸�ļ����Ǵ洢���ʣ����̡���ʾ������ӡ���ȣ�
	�����ݵ���ָ��ʽ��
		�ı���ʽ��AACII�ļ���ÿ���ֽڴ��һ���ַ���ASCII
		�������ļ������ݰ������ڴ��еĴ洢��ʽԭ�����
*/
void maindy041001()
{
	FILE* fp = NULL;
	//char* filenameTemp = "c:\\1.txt";
	char* filename = "c:/2.txt";//ͬһ��45��
	char a[27] = "wangjing";

	fp = fopen(filename, "r+");

	if (fp == NULL)
	{
		printf("func fopen() err:%d");
		return;
	}

	printf("�򿪳ɹ�\n");

	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);
	system("pause");
}

void maindy041002()
{
	FILE* fp = NULL;
	//char* filenameTemp = "c:\\1.txt";
	char* filename = "c:/2.txt";//ͬһ��45��
	char a[27] = "wangjing";

	fp = fopen(filename, "r+");//�Զ���д�ķ�ʽ

	if (fp == NULL)
	{
		printf("func fopen() err:%d");
		return;
	}

	printf("�򿪳ɹ�\n");

	while (!feof(fp))
	{
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}

	if (fp!=NULL)
	{
		fclose(fp);
	}
	
	system("pause");
}
