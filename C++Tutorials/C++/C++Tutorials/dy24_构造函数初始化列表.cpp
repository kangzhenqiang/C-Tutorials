#include <iostream>

using namespace std;
//���캯���е��ù��캯����Σ����Ϊ
class AA
{
public:
	AA(int a);
	~AA();

private:

};

AA::AA(int a)
{
}

AA::~AA()
{
}

class BB
{
public:
	BB(int a, int b);
	BB(int a, int b, int m, int n);
	~BB();

private:
	int m_a;
	int m_b;
	AA m_a1;
	AA m_a2;
	const int c;
};

//1 ���캯���ĳ�ʼ���б� �������B���� �����һ��A�����A������˹��캯����
//���ݹ��캯���ĵ��ù��� ���A�Ĺ��캯��������Ҫ�ã�û�л����ʼ��AA

BB::BB(int a, int b) :m_a1(10), m_a2(5), c(0)
{
	m_a = 0;
	m_b = 0;
}

BB::BB(int a, int b, int m, int n) :m_a1(m), m_a2(n), c(0)
{
	m_a = 0;
	m_b = 0;
}


BB::~BB()
{
}


//2 ��ִ�� ����϶���Ĺ��캯��
//�����϶����ж�������ն���˳�򣬶����ǰ��ճ�ʼ���б��˳��
//���������͹��캯���ĵ���˳���෴ 
//3 ����϶���Ĺ���˳�� �� �����˳���й�ϵ�����ʼ���б��˳��û�й�ϵ

//4 ��ʼ���б�������const���Ը�ֵ
int maindy024()
{
	BB b(1, 2);
	BB b1(1, 2, 3, 5);
	return 0;
}