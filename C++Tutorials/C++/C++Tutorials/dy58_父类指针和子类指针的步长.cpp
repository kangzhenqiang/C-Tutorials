
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Parent
{
public:
	Parent();
	~Parent();

	void print()
	{
		cout << "Parent" << endl;
	}
	int m_a;
private:
	
};

Parent::Parent()
{
	m_a = 0;
}

Parent::~Parent()
{
}

//�ɹ� һ��żȻ�ĳɹ����ȱ�Ȼ��ʧ�ܸ�����
class  Child:public Parent
{
public:
	 Child();
	~ Child();

	void print()
	{
		cout << "Child" << endl;
	}

private:
	int m_b;
	int m_c;
};

 Child:: Child()
{
	 m_b = 0;
	 m_c = 0;
}

 Child::~ Child()
{
}

 /*
	����͸����ָ�벽����һ��������
	��̬ʱ�ø���ָ��ָ��������� �� ���ಽ��++����������ͬ����
 */


int main()
{
	Child *c=NULL;
	Parent* p=NULL;

	Child arr[] = { Child(),Child(),Child() };

	c = arr;
	p = arr;

	c->print();
	p->print();

	c++;
	c->print();
	p++;
	p->print();

	c++;
	c->print();
	p++;
	p->print();

	system("pause");
	return 0;
}
