#include <iostream>

using namespace std;

/*
	1. new delete ������ c++���﷨ mallco free��c���﷨

	2. new �������ͱ��� ����������� ��������� ���䵽����

	3. �����﷨
	
	*/

class TT
{
public:
	TT(int a);
	~TT();

private:
	int m_a;
};

TT::TT(int a)
{
	m_a = a;
}

TT::~TT()
{
}


int maindy026()
{
	//��������

	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	free(p);

	int* c = new int;//�����������
	*c = 30;
	delete c;

	int* cc = new int(40);
	delete cc;

	//��������

	int* pp = (int*)malloc(sizeof(int) * 10);
	pp[0] = 1;
	free(pp);

	int* pArr = new int[10];
	pArr[0] = 10;

	delete[] pArr;

	//����һ������
	TT* t = (TT*)malloc(sizeof(TT));
	free(t);

	TT* tt = new TT(5);
	delete tt;

	return 0;
}