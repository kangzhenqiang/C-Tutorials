//��������������

#include <stdio.h>
#include <string.h>

//����

void maindm002m01()
{
	int a[] = { 33,34,65,12,25 };

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d\n", *(a + i));
	}

	int temp = 0;

	//���� ð�� ��С����
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		for (size_t j = i; j < sizeof(a) / sizeof(int); j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("Sort Arr\n");

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d\n", *(a + i));
	}

	system("pause");
}


//�������������������˻�Ϊһ��ָ��
//���ۣ�
//		1����������ڴ��׵�ַ���������Ч���ȴ��ݸ���������
//		2��ʵ��arr���β�arr���������ͱ��ʲ�һ�����β��е����飬���������������ָ�봦�� ����C���Ե���ɫ
//		3���β�д�ں����Ϻ�д�ں�������һ���ģ�ֻ�����Ǿ��ж�������

//��ӡ
//void printArr(int arr[], int count)//����д��
void printArr(int* arr, int count)//ָ��д��
{
	for (size_t i = 0; i < count; i++)
	{
		printf("%d\n", *(arr + i));
	}
}

//����
//void sortArr(int arr[], int count)
void sortArr(int* arr, int count)
{
	//ʵ��arr���β�arr���������ͱ��ʲ�һ��
	//�β��е����飬���������������ָ�봦�� ����C���Ե���ɫ

	int temp = 0;
	//���� ð�� ��С����
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i; j < count; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void maindm002m02()
{
	int a[] = { 33,34,65,12,25 };
	printArr(a, 5);
	sortArr(a, 5);
	printf("Sort Arr");
	printArr(a, 5);
	system("pause");
}