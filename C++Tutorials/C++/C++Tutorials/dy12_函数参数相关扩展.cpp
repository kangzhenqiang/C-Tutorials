#include <iostream>

using namespace std;

/*
	1. ������д������ʹ������д�ģ�����дĬ��
	2. ��Ĭ�ϲ����������Ĭ�ϲ������֣���ô�ұߵĶ�������Ĭ�ϲ���

	*/

void myPrint(int x = 3)
{
	cout << x << endl;
}

/*
	����ռλ����
		����ռλ��������ʱ����д������
	*/


void myFun001(int a, int b, int)
{
	cout << a << b << endl;
}

/*
	Ĭ�ϲ�����ռλ����
	*/

void myFun002(int a, int b, int = 0)
{
	cout << a << b << endl;
}

void maindy12001()
{
	myPrint();
	myPrint(5);

	myFun001(1, 2, 6);

	myFun002(1, 2);//ok
	myFun002(1, 2, 3);//ok
	system("pause");
}