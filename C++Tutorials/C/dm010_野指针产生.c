//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Ұָ�������ԭ��
//ָ�����������ָ����ڴ�ռ������������ͬ����
//�ͷ���ָ�����µ��ڴ�ռ� ��ָ���������û������ΪNULL
//����ͷŵ�ʱ�� ͨ��if��p!=null��
//���ⷽ����1������ָ���ʱ�� ��ʼ��ΪNULL  2���ͷ�ָ����ָ����ڴ�ռ��Ժ��ָ������ΪNULL

void maindm010()
{
	char* p1 = NULL;
	p1 = (char*)malloc(100);
	if (p1==NULL)
	{
		return;
	}
	strcpy(p1, "1111222");
	if (p1!=NULL)
	{
		//ָ������ͷ�ָ���ڴ��ʱ����ָ�������ΪNULL
		free(p1);
		p1 = NULL;
	}
	if (p1!=NULL)
	{
		free(p1);
	}

	system("pause");
}