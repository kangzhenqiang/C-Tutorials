#include<iostream>

using namespace std;

/*
	�����������Ƽ�ʹ����������������������Ƭ��
	��������inline void printA()�����ʵ��д��һ���ط�
	c++������ֱ�ӽ����������ĺ���������ں������õط�
	���ܴ����κ���ʽ��ѭ�����
	���ܴ��ڹ���������ж����
	�����岻�ܹ���

	���ۣ�
		1. ���������ڱ���ʱֱ�ӽ���������뺯�����õĵط�
		2. inlineֻ��һ�����󣬱�������һ��������������
		3. ��������ʡȥ����ͨ��������ʱѹջ����ת�ͷ��صĿ���
	*/

inline void printA()
{
	int a = 10;
	cout << a << endl;
}

void maindy11001()
{
	printA();
	system("pause");
}

//�궨��
#define MYFUNC(a,b) ((a)<(b)?(a):(b))

inline int myfun(int a,int b)
{
	return a < b ? a : b;
}

void maindy11002()
{
	int a = 1;
	int b = 3;
	//һ�㲻��++a����--a����������

	int c = MYFUNC(++a, b);//====>���滻��չ�� ((a)<(b)?(a):(b))

	int d = myfun(++a, b);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	system("pause");
}

