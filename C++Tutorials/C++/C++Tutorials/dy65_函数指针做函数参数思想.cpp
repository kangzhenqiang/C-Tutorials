
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


//�����ʵ����
int add(int a, int b)
{
	cout << "add" << endl;
	int sum = a + b;
	return sum;
}

//�����ʵ����
int sub(int a, int b)
{
	cout << "add" << endl;
	int sub = a - b;
	return sub;
}

typedef int (*MyPointerFuncAdd)(int a, int b);//��Ӧc#�е�ί��

//���������
int mainOp(MyPointerFuncAdd func)
{
	int sum = func(1, 5);
	return sum;
}

//����ָ�������𵽵������ǰѺ����Ĳ�������������ֵ��ǰԼ��
int mainOpOp(int(*MyPointerFuncAdd)(int a, int b))
{
	int sum = MyPointerFuncAdd(1, 5);
	return sum;
}


//����ĵ��ú������ʵ�ַֿ�
int main()
{
	//c������ʲô����������ڿ�ͷ

	//ֱ�ӵ���
	add(1, 3);

	//��ӵ���
	MyPointerFuncAdd myFunc = add;
	myFunc(4, 5);

	mainOp(add);

	mainOp(sub);

	mainOpOp(add);

	system("pause");
	return 0;
}
