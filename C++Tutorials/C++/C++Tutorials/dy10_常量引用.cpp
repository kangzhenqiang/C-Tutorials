#include<iostream>
using namespace std;

//�����õļ����ܹ�
void miandy10001()
{
	//��ͨ����
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;

	//������
	int x = 10;
	const int& y = x;//������ ���ñ�������ֻ������ ����ͨ��yȥ�޸�x
	
	//������ ��ʼ�� ��Ϊ2�����
	//1. �ñ��� ��ʼ�� ��Ӧ��
	{
		int n = 20;
		const int& m = n;
	}
	//2. �������� ��ʼ�� ��������
	{
		const int h = 10;//c++��������a���ڷ��ű���
		//int& l = 40;//��ͨ���� ����һ�������� ������������û���ڴ��ַ �� ������û���ڴ�
		//���þ��Ǹ��ڴ�ȡ������ƺţ����������
		const int& j = 43;//c++ ������ ������ڴ�ռ�
	}

	system("pause");
}


struct  TeacherT
{
	char name[64];
	int age;
};

int printTeacherT(const TeacherT&t)
{
	//����������ʵ�α���ӵ��ֻ������
	cout << t.age << endl;
	//t.age = 45;//����
	return 0;
}

void maindy10002()
{
	TeacherT t;
	t.age = 36;
	printTeacherT(t);
	system("pause");
}