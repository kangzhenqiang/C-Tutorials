#include <iostream>

using namespace std;

class TestTestTestTest
{
public:
	TestTestTestTest();
	TestTestTestTest(int a);
	TestTestTestTest(int a, int b);
	TestTestTestTest(const TestTestTestTest& obg);

	~TestTestTestTest();

private:
	int m_a;
	int m_b;
};

TestTestTestTest::TestTestTestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "�����޲ι��캯��" << endl;
}

TestTestTestTest::TestTestTestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "һ������������캯��" << endl;
}

TestTestTestTest::TestTestTestTest(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "�����вι��캯��" << endl;
}

//C++�ṩһ�������������
TestTestTestTest::TestTestTestTest(const TestTestTestTest& obg)
{
	m_a = obg.m_a;
	m_b = obg.m_b;
	cout << "���Ǹ�ֵ���캯����copy���캯����" << endl;
}

TestTestTestTest::~TestTestTestTest()
{
}

/*
	1�����캯���ĵ��÷��� �Զ����ã����չ�����ã�
	2��������ʾ�ĳ�ʼ��������Ի�������Դ
	*/

	/*
		Ϊʲô��Ҫ���캯��������������

		û���ṩ���캯����c++���������Զ������ṩһ��Ĭ�ϵĹ��캯��
		��û���ṩ���캯�� copy���캯����c++���������Զ�������Ա�ṩһ�� Ĭ��copy���캯��

		*/

int maindy020()
{
	//1
	TestTestTestTest t1;//�����޲������캯��
	//2
	TestTestTestTest t2(5, 5);//�����вι��캯�� c++�������Զ����ù��캯��
	TestTestTestTest t3 = (6, 6);//"=" c++��"="������ ���� ��ǿ c++�Զ����ù��캯��
	TestTestTestTest t4 = 8;
	//3
	TestTestTestTest t5 = TestTestTestTest(10, 10);//ֱ�ӵ��ù��캯�� �ֶ��ĵ��ù��캯�� ֱ�ӵ��ù��캯��������һ���������� �ѵ�������������������� ʲôʱ��ȥ����
	//4
	t1 = t4;//����ĳ�ʼ���Ͷ���ĸ�ֵ ��������ͬ�ĸ��� �ȺŲ���������ø�ֵ���캯��

	TestTestTestTest t6 = t2;//��t2����ʼ��t6

	TestTestTestTest t7(t2);//��t2����ʼ��t7

	//��ֵ�����ͳ�ʼ��������������ͬ����

	system("pause");
	return 0;
}