#include <iostream>

using namespace std;

class TestTestTestTestTest
{
public:
	TestTestTestTestTest();
	TestTestTestTestTest(int a);
	TestTestTestTestTest(const TestTestTestTestTest& obj);
	~TestTestTestTestTest();

	void printf();

private:
	int m_a;
	int m_b;
};

TestTestTestTestTest::TestTestTestTestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "�޲ι��캯��" << endl;
}

TestTestTestTestTest::TestTestTestTestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "�����вι��캯��" << endl;
}

TestTestTestTestTest::TestTestTestTestTest(const TestTestTestTestTest& obj)
{
	m_a = obj.m_a;
	m_b = obj.m_b;
	cout << "���ǿ������캯��" << endl;
}

TestTestTestTestTest::~TestTestTestTestTest()
{
	cout << "������������ ���������ڽ���ʱ���ᱻc++�������Զ�����" << endl;
}

void TestTestTestTestTest::printf()
{
	cout << m_a << "" << m_b << endl;
}

//��һ�ֺ͵ڶ���
void objmain()
{
	TestTestTestTestTest t1;
	t1.printf();
	TestTestTestTestTest t2(6);
	t2.printf();
	TestTestTestTestTest t3 = t2;//����ÿ������캯��
	TestTestTestTestTest t4(t3);//����ÿ������캯��
}

//������
void print(TestTestTestTestTest t)
{

}

//������
TestTestTestTestTest printCopy()
{
	TestTestTestTestTest t(5);
	return t;
}

/*
	��������Ĭ�Ϲ��캯����
		1. Ĭ���޲ι��캯��
			������û�ж��幹�캯��ʱ��������Ĭ���ṩһ���޲ι��캯�������ҽ��亯��Ϊ��;
		2. Ĭ�Ͽ������캯��
			������û�ж��忽�����캯��ʱ��������Ĭ���ṩһ��Ĭ�Ͽ������캯�����򵥵Ľ��г�Ա������ֵ���ơ�
	*/

int maindy022()
{
	objmain();
	TestTestTestTestTest t = printCopy();
	TestTestTestTestTest t2;
	t2 = printCopy();
	system("pause");
	return 0;
}

