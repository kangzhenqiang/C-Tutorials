#include <iostream>

using namespace std;

class TTTTTT
{
public:
	TTTTTT(int a, int b);
	~TTTTTT();

	void printf()
	{
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}

	/*
		1. constд��ʲôλ��ûʲô��ϵ
		 const д��ʲôλ��û�й�ϵ
		 const void OpVar(int a,int b)
		 void  OpVar(int a,int b) const
		 void const OpVar(int a,int b)

		 2. const���ε���˭��
			const���ε����β�a�� ����
			const���ε�����this->a this->b
			const���ε���thisָ����ָ����ڴ�ռ�

		 3. thisָ��
			void OpVar(int a,int b) ===>void OpVar(TTTTTT * const this,int a,int b)
			void  OpVar(int a,int b) const ===>void OpVar(const TTTTTT * const this,int a,int b)
		 */


	void OpVar(int a, int b) const
	{
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}

private:
	int a;
	int b;
};

TTTTTT::TTTTTT(int a, int b)
{
	this->a = a;
	this->b = b;
}

TTTTTT::~TTTTTT()
{
}


int maindy030()
{
	TTTTTT t(4, 5);
	t.printf();
	system("pause");
	return 0;
}