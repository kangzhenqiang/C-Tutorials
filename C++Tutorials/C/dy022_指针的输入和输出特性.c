#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//ָ��������������ú��������ڴ� ---ok
//ָ�������룺�������� �����ڴ�

//���ļ������λ��ĳ���
int getMemberM(char** myp1, char* mylen1, char** myp2, char* mylen2)
{
	char* temp1 = NULL;
	temp1 = (char*)malloc(100);
	if (temp1 == NULL)
	{
		return -1;
	}
	strcpy(temp1, "kangzhenqiang");
	*mylen1 = strlen(temp1);
	*myp1 = temp1;//����޸�ʵ��p1��ֵ

	char* temp2 = NULL;
	temp2 = (char*)malloc(100);
	if (temp2 == NULL)
	{
		return -2;
	}
	strcpy(temp2, "wangjing");
	*mylen2 = strlen(temp2);
	*myp2 = temp2;//����޸�ʵ��p2��ֵ

	return 0;
}


int freeMem(char** myp)
{
	char* temp = NULL;
	if (myp == NULL)
	{
		return;
	}
	temp = *myp;
	free(*myp);
	*myp = NULL;
}

//һ��ָ�룬�ͷ���
int freeMem1(char* myp)
{
	char* temp = NULL;
	if (myp == NULL)
	{
		return;
	}
	temp = myp;
	free(myp);
}


void maindy022()
{
	char* p1 = NULL;
	int len1 = 0;

	char* p2 = NULL;
	int len2 = 0;

	int ret = 0;
	ret = getMemberM(&p1, &len1, &p2, &len2);

	printf("p1 is:%s, len is:%d.\n", p1, len1);
	printf("p2 is:%s, len is:%d.\n", p2, len2);

	freeMem(&p1);
	freeMem(&p2);

	//freeMem1(p1);//�ڱ��������� ��p1��ָ����ڴ���ͷŵ�������ʵ��p1���ܱ��޸ĳ�NULL��Ұָ������

	system("pause");
}