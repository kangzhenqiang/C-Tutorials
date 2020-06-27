#include<iostream>
using namespace std;


struct Dog
{
	char name[64];
	int age;
};

//�ڱ����ú�����ȡһ���ڴ��
void getDog(Dog** p)
{
	Dog* tempDog = NULL;
	if (p == NULL)
	{
		return;
	}
	tempDog = (Dog*)malloc(sizeof(Dog));
	if (tempDog == NULL)
	{
		return;
	}
	strcpy_s(tempDog->name, "HiHi");
	tempDog->age = 5;
	//p��ʵ�εĵ�ַ�� *ʵ�εĵ�ַȥ��ӵ��޸�ʵ�ε�ֵ
	*p = tempDog;
}

//�ͷ��ڴ�ռ�
void freeDog(Dog** p)
{
	if (p != NULL)
	{
		free(p);
		*p = NULL;
	}
}

//ָ������
int getDogDog(Dog*& p)
{
	p = (Dog*)malloc(sizeof(Dog));
	strcpy_s(p->name, "HeiHei");
	p->age = 6;
	return 0;
}

void maindy09001()
{
	Dog* p = NULL;
	//1. c�����еĶ���ָ��
	getDog(&p);
	cout << p->name << endl;
	cout << p->age << endl;
	freeDog(&p);

	//2. c++�е����ã�ָ������ã�
	//���õı��� ��Ӹ�ֵ��2��������c++�����������ǳ���Ҫ����
	getDogDog(p);
	cout << p->name << endl;
	cout << p->age << endl;
	freeDog(&p);

	system("pause");
}