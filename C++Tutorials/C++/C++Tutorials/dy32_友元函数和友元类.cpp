#include <iostream>

using namespace std;

class AA
{
public:
	AA(int a,int b);
	~AA();
	/*
		1. ������λ�ú�public privateû�й�ϵ
		2. ����modifyA �� ��ĺ�����
	*/
	friend void modifyAA(AA* p);

	int GetA()
	{
		return this->a;
	}
private:
	int a;
	int b;
};

AA::AA(int a,int b)
{
	this->a = a;
	this->b = b;
}

AA::~AA()
{
}

//ͨ����Ա�����޸����˽������
void modifyAA(AA* p)
{
	p->a = 100;
}


int maindy032()
{
	AA a(5, 5);
	modifyAA(&a);
	cout<<a.GetA()<<endl;
	system("pause");
	return 0;
}

