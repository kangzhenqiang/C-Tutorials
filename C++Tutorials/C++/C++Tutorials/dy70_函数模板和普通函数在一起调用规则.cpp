
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
	����ģ�岻�����Զ�����ת��
	��ͨ�����ܹ������Զ�����ת��
	*/

	/*
		1 ����ģ���������ͨ����һ������
		2 c++���������޿�����ͨ����
		3 �������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��
		4 ����ͨ����ģ��ʵ���б���﷨�޶�������ֻͨ��ģ��ƥ��
		*/

int Max(int a, int b)
{
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	cout << "T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b, T c)
{
	cout << "T Max(T a, T b,T c)" << endl;
	return Max(Max(a, b), c);
}

int main()
{
	int a = 10;
	int b = 20;

	cout << Max(a, b) << endl;//��ģ�庯������ͨ���������ϵ���ʱ������ѡ����ͨ����

	cout << Max(a, b) << endl;//����ʾ��ʹ�ú���ģ�壬��ʹ��<>�����б�

	cout << Max(3.5, 5.8)<<endl;//�������ģ��������õ�ƥ�� ʹ�ú���ģ��

	cout << Max(3.5, 5.8, 7.0) << endl;//����

	cout << Max('a', 10) << endl;//������ͨ���� ������ʽ����ת��

	system("pause");
	return 0;
}

/*
	������������Ѻ���ģ��ģ�崦����ܹ�����������ĺ���
	�������Ӻ���ģ��ͨ���������Ͳ�����ͬ�ĺ���
	��������Ժ���ģ��������α���
	�������ĵط���ģ����뱾����б���
	�ڵ��õĵط��Բ����滻��Ĵ�����б���
	*/
