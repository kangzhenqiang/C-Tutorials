
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	����ҵ���߼�һ��
	�����Ĳ������Ͳ�һ��

	*/

void myswapInt(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswapChar(char& a, char& b)
{
	char c = 0;
	c = a;
	a = b;
	b = c;
}

/*
	�����Ͳ��������������Ҫ���б��� ===>���ͱ��
	*/

//template���߱����� ��Ҫ��ʼ���ͱ���ˣ���Ҫ��㱨��
template<typename T>
void myswap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

/*
	����ģ�����
	��ʾ���͵���
	�Զ����͵���
	*/
int main()
{
	//��ʾ����
	int a = 10;
	int b = 5;
	myswap<int>(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	//�Զ������Ƶ�
	char x = 'x';
	char y = 'y';
	myswap(x, y);
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;

	system("pause");
	return 0;
}


int maindy067_001()
{
	{
		int a = 10;
		int b = 20;
		myswapInt(a, b);
		printf("a:%d,b:%d\n", a, b);
	}

	{
		char a = 'k';
		char b = 'n';
		myswapChar(a, b);
		printf("a:%c,b:%c\n", a, b);
	}

	system("pause");
	return 0;
}
