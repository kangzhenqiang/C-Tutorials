#include <iostream>

using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

//ָ����ָ����ڴ�ռ䲻�ܱ��޸�
int operatorTeacher(const Teacher* pTeacher)
{
	//pTeacher->age = 10;
	pTeacher = NULL;
	return 0;
}

//ָ�����������ڴ�ռ䲻�ܱ��޸�
int operatorTeacherConst(Teacher* const pTeacher)
{
	pTeacher->age = 10;
	//pTeacher = NULL;
	return 0;
}

//ָ�����������ڴ�ռ��ָ����ڴ�ռ䶼���ܱ��޸�
int operatorTeacherConstConst(const Teacher* const pTeacher)
{
	//pTeacher->age = 10;
	//pTeacher = NULL;
	return 0;
}


void maindy04001()
{
	//һ��
	const int a = 5;
	int const b = 10;

	//const int* c;//const���ε�ָ��ָ����ڴ�ռ䣬���ܱ��޸�
	//const int* const d;

	//c�����е�const�Ǹ�ð�ƻ�

	/*
	//a������һ������
	const int a = 10;
	*/
	int* p = NULL;
	p = (int*)&a;
	*p = 20;

	/*
		const��c++����һ�������ĳ���
		c++�з��ű� key:a value:10
		p = ��int*��&a;�ٴη����ڴ�ռ�
		
		C������const����
			c������const������ֻ�����������Լ��Ĵ洢�ռ�
		c++�е�const����
			���ܷ���洢�ռ䣬Ҳ���ܲ�����洢�ռ�
			��const����Ϊȫ�֣�������Ҫ�������ļ���ʹ��
			��ʹ��&������ȡcosnt������ַ
	*/

	printf("a:%d\n", a);

	system("pause");
	return;
}