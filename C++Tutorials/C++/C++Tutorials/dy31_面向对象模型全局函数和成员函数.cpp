#include <iostream>

using namespace std;

class Test
{
public:
	Test(int a, int b);
	~Test();

	Test TestAdd(Test& test);
	Test& TestAddAdd(Test& test);

	void Printf();
	int a;
	int b;
private:

};

Test::Test(int a, int b)
{
	this->a = a;
	this->b = b;
}

Test::~Test()
{
}

Test Test::TestAdd(Test& test)
{
	Test temp(this->a + test.a, this->b + test.b);
	return temp;
}

//����һ������ �൱�ڷ�������
//����t1Ԫ��
Test& Test::TestAddAdd(Test& test)
{
	// TODO: �ڴ˴����� return ���
	this->a = this->a + test.a;
	this->b = this->b + test.b;
	return *this;//��*(&t1)�ֻص���t1
}

void Test::Printf()
{
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}

/*
	ȫ�ֺ���ת�ɳ�Ա��������һ������
	��Ա����ת��ȫ�ֺ�������һ������
	*/

void Printf(Test* pt)
{
	cout << "a:" << pt->a << endl;
	cout << "b:" << pt->b << endl;
}



//ȫ�ֺ���ת��Ϊ��Ա����
Test TestAdd(Test& t1, Test& t2)
{
	Test temp(t1.a + t2.a, t1.b + t2.b);
	return temp;
}


int maindy031001()
{
	Test t1(1, 1);
	Test t2(2, 3);

	//t1 + t2

	Test t3 = TestAdd(t1, t2);
	t3.Printf();

	//�ȰѲ��԰���д����
	{
		Test t4 = t1.TestAdd(t2);
		t4.Printf();

		Test t5(0, 0);
		t5 = t1.TestAdd(t2);
		t5.Printf();
	}

	return 0;
}


int maindy031002()
{
	Test t1(1, 1);
	Test t2(2, 3);

	t1.TestAddAdd(t2);
	t1.Printf();

	return 0;
}