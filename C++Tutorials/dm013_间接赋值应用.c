//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ָ�������������쳣��Ҫ
//��������ʱ���βδ���ʵ�Σ���ʵ��ȡ��ַ�������βΣ��ڱ����ú���������*p,���ı�ʵ�Σ���������������

void getContentLength(char** myContent1, int* myContentLength1,
	char** myContent2, int* myContentLength2)
{
	char* temp1 = NULL;
	char* temp2 = NULL;

	temp1 = (char*)malloc(sizeof(char) * 128);
	strcpy(temp1, "wangjing");
	*myContentLength1 = strlen(temp1);

	temp2 = (char*)malloc(sizeof(char) * 128);
	strcpy(temp2, "kangzhenqiang");
	*myContentLength2 = strlen(temp2);

	*myContent1 = temp1;
	*myContent2 = temp2;
}


void maindm013()
{
	char* content1 = NULL;
	int length1 = 0;
	char* content2 = NULL;
	int length2 = NULL;

	getContentLength(&content1, &length1, &content2, &length2);

	printf("content1:%s,length:%d\n", content1, length1);
	printf("content1:%s,length:%d\n", content2, length2);

	if (content1!=NULL)
	{
		free(content1);
		content1 = NULL;
	}

	if (content2!=NULL)
	{
		free(content2);
		content2 = NULL;
	}

	system("pause");
}

//��Ӹ�ֵ��������������
//����1��//����1��������ʵ�Σ� //����һ���������βΣ�
//����2��//������������ʵ�εĵ�ַ���ݸ��β�
//����3��//*�β�ȥ��ӵ��޸�ʵ�ε�ֵ

//��Ӹ�ֵӦ�ó���
void maindm01302()
{
	//1 2 3 ��3������ д��һ������	
	//12 д��һ�� 3 ����д����һ���������� =====>��������
	//1  23д��һ�� ==>��ש ====>c++���У���ʱ����ʶ...

	char from[128];
	char to[128];
	char* p1 = from;
	char* p2 = to;

	strcpy(from, "kangzhenqiang");

	while (*p1!='\0')
	{
		*p2 = *p1;
		p1++;
		p2++;
	}

	system("pasue");
}


//��1��ָ���βΣ�ȥ����޸�0��ָ�루ʵ�Σ���ֵ
//��2��ָ���βΣ�ȥ����޸�1��ָ�루ʵ�Σ���ֵ
//��3��ָ���βΣ�ȥ����޸�2��ָ�루ʵ�Σ���ֵ
//��n��ָ���βΣ�ȥ����޸�n-1��ָ�루ʵ�Σ���ֵ
//ָ������������ʱ�о��ص�

//���ָ��������ڴ���������
//1.�������� ��������
//a�����������ɰѶ�����ջ����ȫ�����ڴ��ַ���ݸ������ú���
//b) �����ú���ֻ�ܷ��ض�����ȫ��������
//2.�ڴ���䷽ʽ
//a)ָ�����������������������������Ե�
//�����������з������뵽���ú����н�����
//�ڱ����ú����з�����������������н����