
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void maindy042()
{
	int i = 0;
	FILE* fp = NULL;
	char* flname = "c:/1.txt";
	char a[27] = "kangzhenqiang";
	char buf[1024];
	//fp = fopen(flname, 'r+');//��д�ķ�ʽ�򿪲����ھͻᱨ��
	fp = fopen(flname, "r+");//��д�ķ�ʽ�򿪲����ڴ������ļ�
	if (fp == NULL)
	{
		printf("func fopen() err:%d\n");
		return;
	}
	printf("�򿪳ɹ���\n");

	while (!feof(fp))
	{
		//c�������һ��һ�е�copy���ݵ�buf��ָ����ڴ�ռ��� ���ұ��c�����ַ���
		//��\nҲcopy�����ǵ�buf��
		//�ڴ������Ѻ����׵�ַ+�ڴ�ĳ��ȣ�
		char* p = fgets(buf, 1024, fp);
		if (p==NULL)
		{
			goto End;
		}
		/*char tempc = fgetc(fp);
		printf("%c", tempc);*/
		printf("%s", buf);
	}
End:
	{
		if (fp!=NULL)
		{
			fclose(fp);
		}
		return;
	}
	/*
	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	*/
	//fputs(a, fp);
	fclose(fp);
	system("pause");
}
