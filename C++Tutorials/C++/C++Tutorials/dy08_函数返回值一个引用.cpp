#include <iostream>
using namespace std;

/// <summary>
/// ����ֵ
/// </summary>
/// <returns></returns>
int getA1()
{
	int a;
	a = 10;
	return a;
}

/// <summary>
/// �������� ����a��һ������10
/// </summary>
/// <returns></returns>
int& getA2()
{
	int a;
	a = 20;
	return a;
}

/// <summary>
/// ����ָ��
/// </summary>
/// <returns></returns>
int* getA3()
{
	int a = 5;
	a = 30;
	return &a;
}

/*
	c++��ʹ�������ѵ㣺
		����������ֵΪ����ʱ
			������ջ���������ܳ�Ϊ�������õĳ�ʼֵ��������Ϊ��ֵʹ�ã�
			�����ؾ�̬������ȫ�ֱ�����������Ϊ��ֵʹ�ã�Ҳ������Ϊ��ֵʹ�ã�
*/

int j1()
{
	static int a = 1;
	a++;
	return a;
}

int& j2()
{
	static int a = 1;
	a++;
	return a;
}

void maindy08001()
{
	int a1 = getA1();

	int a2 = getA2();

	int* a3 = getA3();

	int& a4 = getA2();//������ջ���������ܳ�Ϊ�������õĳ�ʼֵ��������Ϊ��ֵʹ�ã�

	cout << a1 << endl;
	cout << a2 << endl;
	cout << *a3 << endl;


	//���ر���ʱstatic������ȫ�ֱ���

	int a5 = j1();
	int a6 = j1();
	int& a7 = j2();

	cout << a5 << endl;
	cout << a6 << endl;
	cout << a7 << endl;

	system("pause");
}

//��������ֵ

//���ر�����ֵ
int g1()
{
	static int a = 1;
	a++;
	return a;
}

//���ر�������
int& g2()
{
	static int a = 1;
	a++;
	cout << a << endl;
	return a;
}

void maindy08()
{
	//g1() = 10;
	g2() = 20;
	g2();
	system("pause");
}