#include <iostream>

using namespace std;

class TestTest
{
public:
	TestTest();
	TestTest(int a);
	TestTest(int a, int b);
	TestTest(const TestTest& obg);

	~TestTest();

private:
	int m_a;
	int m_b;
};

TestTest::TestTest()
{
	m_a = 0;
	m_b = 0;
	cout << "�����޲ι��캯��" << endl;
}

TestTest::TestTest(int a)
{
	m_a = a;
	m_b = 0;
	cout << "һ������������캯��" << endl;
}

TestTest::TestTest(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "�����вι��캯��" << endl;
}

TestTest::TestTest(const TestTest& obg)
{
	m_a = 1;
	m_b = 2;
	cout << "���Ǹ�ֵ���캯����copy���캯����" << endl;
}

TestTest::~TestTest()
{
}

/*
	1�����캯���ĵ��÷��� �Զ����ã����չ�����ã�
	2��������ʾ�ĳ�ʼ��������Ի�������Դ
	*/

/*
	Ϊʲô��Ҫ���캯��������������


	*/

int maindy018()
{
	//1
	TestTest t1;//�����޲������캯��
	//2
	TestTest t2(5, 5);//�����вι��캯�� c++�������Զ����ù��캯��
	TestTest t3 = (6, 6);//"=" c++��"="������ ���� ��ǿ c++�Զ����ù��캯��
	TestTest t4 = 8;
	//3
	TestTest t5 = TestTest(10, 10);//ֱ�ӵ��ù��캯�� �ֶ��ĵ��ù��캯�� ֱ�ӵ��ù��캯��������һ���������� �ѵ�������������������� ʲôʱ��ȥ����
	//4
	t1 = t4;//����ĳ�ʼ���Ͷ���ĸ�ֵ ��������ͬ�ĸ���
	system("pause");
	return 0;
}