#include<iostream>
using namespace std;

void maindy07001()
{
	const int c = 10;

	int a = 10;
	int& b = a;//b����һ������

	//a��b����ͬһ���ڴ�ռ�����ƺ�
	cout << a << endl;
	cout << b << endl;

	system("pause");
}

// ��ͨ�������Լ��Ŀռ�
struct Person
{
	char name[64];
	int age;

	int& a;//����ָ��
	int& b;
};

void modifyA1(int* a)
{
	*a = 200;
}

void modifyA2(int& a)
{
	a = 300;
}


void maindy07002()
{
	//������c++�е��ڲ�ʵ����һ������ָ��
	//Type& name <-->Type* const name

	cout << "sizeof(Person):" << sizeof(Person) << endl;
	int a = 10;

	//ָ������������õ�ʱ�����ǳ���Ա����Ҫȡa�õ�ַ
	modifyA1(&a);
	cout << a << endl;

	a = 10;
	//�����ָ�� ��Ҫ���ǳ���Ա�ֹ���ȡʵ�εĵ�ַ
	modifyA2(a);
	cout << a << endl;

	system("pause");
}

//��Ӹ�ֵ

void maindy07003()
{
	//1. ������������
	int a = 10;
	int* p = NULL;

	//2. ��������
	p = &a;

	//3. ����޸�
	*p = 20;
}

//������ʵ���ϣ�ֻ�����ǰѣ���Ӹ�ֵ���������������ĺ������϶�Ϊһ
//������ʹ�������﷨�ǣ����ǲ�ȥ���ı���������ʱ��ô����
//�����Ƿ�����ֵ��﷨����ʱ�����ǲ�ȥ����c++����������ô����