#include<iostream>

using namespace std;

void myfunc00000(int a)
{
	cout << a << endl;
}

void myfunc00000(char* p)
{
	cout << *p << endl;
}


void myfunc00000(int a, int b)
{
	cout << a << endl;
	cout << b << endl;
}

void myfunc00000(char* p1, char* p2)
{
	cout << *p1 << endl;
	cout << *p2 << endl;
}

/*
	����ָ��
		1. ����һ����������
	*/

typedef void (myTypeFunc)(int a, int b);

/*
		2. myTypeFunc* fuc = NULL;//����һ������ָ�� ָ������ڵ�ַ
	*/


	/*
			3. ����һ������ָ������
		*/
typedef void(*myPTypeFuc)(int a, int b);

/*
		4. myPTypeFunc fp = NULL;//ͨ�� ����ָ�����Ͷ�����һ������ָ��
	*/


	/*
			5. ������һ������ָ�����
		*/

void (*myVarPFunc)(int a, int b);


int maindy014()
{
	myTypeFunc* fuc = NULL;//����һ������ָ�� ָ������ڵ�ַ

	myPTypeFuc pfunc = NULL;

	pfunc = myfunc00000;

	pfunc(1, 4);

	/*pfunc("kang", "zhen");*/

	system("pause");

	return 0;
}