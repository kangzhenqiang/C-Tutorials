#include<iostream>

using namespace std;


/*
	const��#define��֮ͬ��
	c++��const���������ں궨��

	const int a=5; Լ���� #define c 5;
	const �������ɱ���������ģ��ṩ���ͼ�����������
	const ���������������
	*/

//const��#define��֮ͬ��
//#define���ڱ���֮ǰ�����

void maindy05001()
{
	const int a = 10;
	int b = 20;

	//int array[a];

	//int array[a + b];
	//linux�ں�������֧�ֵģ�ԭ�� ����linux�ں˵�gcc������֧��
	//c��c++��������֧�������﷨����

	//����������ж��

#define c 10 //�����


#undef c //ж�غ�
	
}
