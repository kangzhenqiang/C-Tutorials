#include <iostream>

using namespace std;

/*
	1. new delete c++������ mallco free��c�ĺ���

	2. new �������ͱ��� ����������� ��������� ���䵽����

	3. �����﷨

	4. ����
			mallco ֻ�Ƿ����ڴ� ������ù��캯�� new�����ڴ沢��ʼ������
			free ֻ���ͷ��ڴ� ������������������
	5. ���ۣ�
			
	*/

class TTT
{
public:
	TTT(int a);
	~TTT();

private:
	int m_a;
};

TTT::TTT(int a)
{
	m_a = a;
}

TTT::~TTT()
{
	cout << "����" << endl;
}


int maindy027()
{
	//��������

	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	delete p;

	int* c = new int;//�����������
	*c = 30;
	free(c);

	int* cc = new int(40);
	free(cc);

	//��������

	int* pp = (int*)malloc(sizeof(int) * 10);
	pp[0] = 1;
	delete[] pp;

	int* pArr = new int[10];
	pArr[0] = 10;

	free(pArr);

	//����һ������
	TTT* t = (TTT*)malloc(sizeof(TTT));
	delete t;

	TTT* tt = new TTT(5);
	free(tt);

	system("pause");
	return 0;
}