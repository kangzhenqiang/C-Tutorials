#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



//����
		//1��Ԫ�����ͽǶȣ���������ͬ���͵ı��������򼯺� ����ָ�����ռ���ڴ�ռ��С
		//2���ڴ�Ƕȣ�������һ��Ƭ���ڴ�ռ�
//�����ʼ����
		//1������Ԫ�صĸ���������ʾ����ʽָ��
		//2�����������ʼ��{0}��memset�Ƚ�

//����ļ���ä��
//

void miandy030001()
{
	int a[] = { 1,2 };
	int b[100] = { 1,2 };

	int c[200] = { 0 };//����ʱ���Ѿ�ȷ�� ���е�ֵΪ��

	//����һά����涨��
	//c����Ԫ�صĵ�ַ c+1 ������4���ֽ�
	//&c����������ĵ�ַ &c+1 ������800���ֽ�
	memset(c, 0, sizeof(c));//��ʾ�� �����ڴ��

	system("pause");
}

//��ô���int a[10]�����������ͣ� int[]
//���ͱ��ʣ��̶��ڴ���С�ı���

//��������
//1.�������ͷ�Ϊ�������ǻ�����˼���Ƕ�Ӧ�����仯
//2.C�����е��������Լ����ض�����
	//�������������Ԫ�����ͺ������С��ͬ����

//������������
void maindy030002()
{
	typedef int(MyArray)[5];//������һ���������� ������������
	int i = 0;
	MyArray myArray;//int myArray[5]

	for (int i = 0; i < 5; i++)
	{
		myArray[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", myArray[i]);
	}

	printf("myArray����������Ԫ�ص�ַ:%d myArray+1:%d\n", myArray, myArray + 1);
	printf("&myArray�������������ַ:%d &myArray+1:%d\n", &myArray, &myArray + 1);

	system("pause");
	return;
}

//��������ָ������ķ���
void maindy030003()
{
	char* myArray[] = { "11111","22222","33333" };//ָ������

	//����ָ�� ��һ��ָ�� ��ָ��һ������

	typedef int(MyArrayType)[5];//������һ���������� ������������
	MyArrayType myArr;//int myArr[5];//�����Ͷ������

	int i = 0;
	MyArrayType* pArr;//����һ��ָ����� ���ָ����� ָ��һ������

	{
		int a;
		int* p = NULL;
		p = &a;
	}

	{

		int myArray2[5];//�൱��һ��ָ��
		for ( i = 0; i < 5; i++)
		{
			myArray2[i] = i + 1;
		}

		pArr = &myArray2;

		for ( i = 0; i < 5; i++)
		{
			printf("%d\n", (*pArr)[i]);
		}
	}

	system("pause");
}

//��������ָ������ĵڶ��ַ���
void maindy030004()
{
	//��������һ������ָ������
	typedef int(*PArrayType)[5];
	PArrayType pArr;//���߱����� ���ҷ���һ��ָ�����

	int c[5];

	pArr = &c;

	for (int i = 0; i < 5; i++)
	{
		(*pArr)[i] = i + 2;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*pArr)[i]);
	}
	system("pause");
}


//��������ָ������ĵ����ַ���
//ǰ���ַ��� ͨ�����Ͷ������ �Ƚ��鷳
void maindy030005()
{
	int(*pMyArr)[5];//ֱ�Ӷ���һ��ָ������ı���
	int c[5];

	pMyArr = &c;

	for (int i = 0; i < 5; i++)
	{
		(*pMyArr)[i] = i + 2;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*pMyArr)[i]);
	}
	system("pause");
}



