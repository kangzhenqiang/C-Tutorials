#include <iostream>

using namespace std;

class TestTestTest
{
public:
	TestTestTest();
	TestTestTest(int a);
	TestTestTest(int a, int b);
	TestTestTest(const TestTestTest& obg);

	~TestTestTest();

private:
	int m_a;
	int m_b;
};

TestTestTest::TestTestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "�����޲ι��캯��" << endl;
}

TestTestTest::TestTestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "һ������������캯��" << endl;
}

TestTestTest::TestTestTest(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "�����вι��캯��" << endl;
}

TestTestTest::TestTestTest(const TestTestTest& obg)
{
	m_a = 1;
	m_b = 2;
	cout << "���Ǹ�ֵ���캯����copy���캯����" << endl;
}

TestTestTest::~TestTestTest()
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

int maindy019()
{
	//1
	TestTestTest t1;//�����޲������캯��
	//2
	TestTestTest t2(5, 5);//�����вι��캯�� c++�������Զ����ù��캯��
	TestTestTest t3 = (6, 6);//"=" c++��"="������ ���� ��ǿ c++�Զ����ù��캯��
	TestTestTest t4 = 8;
	//3
	TestTestTest t5 = TestTestTest(10, 10);//ֱ�ӵ��ù��캯�� �ֶ��ĵ��ù��캯�� ֱ�ӵ��ù��캯��������һ���������� �ѵ�������������������� ʲôʱ��ȥ����
	//4
	t1 = t4;//����ĳ�ʼ���Ͷ���ĸ�ֵ ��������ͬ�ĸ���
	system("pause");
	return 0;
}