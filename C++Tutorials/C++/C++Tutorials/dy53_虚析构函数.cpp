
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class A
{
public:
	A();
	/*virtual*/ ~A();

private:
	char* p;
};

A::A()
{
	p = new char[20];
	strcpy(p, "kang");
	cout << "����A" << endl;
}

A::~A()
{
	cout << "����A" << endl;
	delete[] p;
}


class B :public A
{
public:
	B();
	~B();

private:
	char* p;
};

B::B()
{
	p = new char[20];
	strcpy(p, "wang");
	cout << "����B" << endl;
}

B::~B()
{
	cout << "����B" << endl;
	delete[] p;
}


class C :public B
{
public:
	C();
	~C();

private:
	char* p;
};

C::C()
{
	p = new char[20];
	strcpy(p, "hao");
	cout << "����C" << endl;
}

C::~C()
{
	cout << "����C" << endl;
	delete[] p;
}

//ִֻ���� �������������
//��ͨ������ָ�� �����е�����������������������һ��
//��ͨ������ָ�� �ͷ����е�������Դ
//ֱ��ͨ������ָ���ͷ���Դ����Ҫдvitural
void howtodelete(A* base)
{
	delete base;
}

int main()
{
	C* myC = new C;// new deleteƥ��
	//howtodelete(myC);
	delete myC;
	system("pause");
	return 0;
}
