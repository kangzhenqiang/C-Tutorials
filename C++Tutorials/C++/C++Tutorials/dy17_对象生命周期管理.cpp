/*
	��Ĺ��������
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class  Test
{
public:
	Test();//���캯��
	~Test();//��������  ������� �ڶ�������ʱ�Զ�����

private:

	int a;
	char* p = NULL;

};

Test::Test()//������ɶ����Եĳ�ʼ������
{
	a = 10;
	p = (char*)malloc(100);
	strcpy(p, "kangzhenqiang");
	cout << "���ǹ��캯��" << endl;
}

Test::~Test()//�ͷ���Դ
{
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
	cout << "������������" << endl;
}


//��������̨���о��������Ϊ

int objPlay()
{
	Test t1, t2;//�������ȴ����Ķ�����ͷ�

	return 0;
}

int maindy017()
{
	objPlay();
	system("pause");
	return 0;
}