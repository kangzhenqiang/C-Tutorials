
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
	���⣺
		��һ������Ȼ��1-1000��ĳЩ��������ɵ������У�ÿ�����ֿ��ܳ�����λ���
		���һ���㷨���ҳ����ִ�����������
		int arr[2000]={1,50,45,36,14,36,60,45,60};

		��ʱ�任�ռ�
	*/


using namespace std;

void search(int arr[], int len)
{
	int sp[1000] = { 0 };
	int max = 0;
	for (size_t i = 0; i < len; i++)//�������飬���ÿһ�����ֳ��ֵĴ���,Ȼ���¼����
	{
		int index = arr[i] - 1;
		sp[index]++;
	}

	for (size_t i = 0; i < 1000; i++)//ɨ�����飬��������
	{
		if (max< sp[i])
		{
			max = sp[i];
		}
	}
	for (size_t i = 0; i < 1000; i++)//��ӡ��������
	{
		if (max==sp[i])
		{
			cout << "arr max value:" << i + 1 << endl;
		}
	}
}


int main()
{
	int arr[] = { 1,50,45,36,14,36,60,45,60 };
	search(arr, sizeof(arr) / sizeof(*arr));
	system("pause");
	return 0;
}
