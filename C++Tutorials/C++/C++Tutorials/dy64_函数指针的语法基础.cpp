
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
	����ָ��Ļ����﷨
	1 ��ζ���һ����������
	2 ��ζ���һ������ָ������
	3 ��ζ���һ�� ����ָ�� ��ָ��һ����������ڵ�ַ��
	*/

int add(int a, int b)
{
	cout << "fun add .." << endl;
	cout << a + b << endl;
	return a + b;
}


int main()
{
	add(4, 5);//ֱ�ӵ��� ��������Ǻ�������ڵ�ַ

	//����һ����������
	{
		typedef int (MyfuncType)(int a, int b);
		MyfuncType* myPointterFucn = NULL;
		myPointterFucn = &add;//ϸ��
		myPointterFucn(7, 8);

		myPointterFucn = add;//ϸ�� c�������������ģ�������ʱ�汾��ԭ��
		myPointterFucn(7, 8);
	}

	//����һ������ָ������
	{
		typedef int (*MyPointrtFucType)(int a, int b);
		MyPointrtFucType myPointer;
		myPointer = &add;
		myPointer(6, 7);
	}

	//ֱ�Ӷ���һ����������
	{
		int (*MyPoimtFuc)(int a, int b);//����һ������
		MyPoimtFuc = add;
		MyPoimtFuc(1, 2);
	}

	system("pause");
	return 0;
}
