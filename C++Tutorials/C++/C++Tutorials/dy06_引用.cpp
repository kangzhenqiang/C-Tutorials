#include <iostream>

using namespace std;

/*
	����
	1. ���û���
	2. ��������ֵ
	3. ָ�������
	4. ��������
	*/

	/*
		��c++�����������ø���
		���ÿ��Կ���һ���Ѷ�������ı���
		���õ��﷨��Type& name = var��
		*/

void maindy06001()
{
	//1. ���û�������
	//2. ����c++��������c����չ��������c���Ե��﷨˼����
	int a = 10;

	//�����﷨ Type& name = var;
	int& b = a;

	cout << a << endl;
	cout << b << endl;

	system("pause");
}

//�������͵�����

int myswap01(int* a, int* b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
	return 0;
}

void maindy06002()
{
	int x, y;
	x = 10;
	y = 20;

	myswap01(&x, &y);
	cout << x << endl;
	cout << y << endl;
	system("pause");
}

// ������������
int myswap02(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
	return 0;
}

void maindy06003()
{
	int x, y;
	x = 10;
	y = 20;

	myswap02(x, y);
	cout << x << endl;
	cout << y << endl;
	system("pause");
}


//�����������͵�����

struct  Student
{
	char name[64];
	int age;
};

void PrintStudent01(Student* student)
{
	cout << student->age << endl;
}

void PrintStudent02(Student& student)
{
	cout << student.age << endl;
}

void PrintStudent03(Student& student)
{
	cout << student.age << endl;
}

void maindy06004()
{
	Student s;
	s.age = 30;
	PrintStudent01(&s);
	//student��s�ı���
	PrintStudent02(s);
	//student���βΣ�s copyһ�����ݸ�student
	PrintStudent03(s);
	system("pause");
	return;
}


/*
	���õ�����:
	1. ������Ϊ������ı��������ڣ����һЩ���Ͽ�����ȫ���ָ��
	2. ���������ָ����˵���и��õĿɶ��Ժ�ʵ����
*/