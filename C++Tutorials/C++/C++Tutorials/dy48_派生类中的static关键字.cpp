#include <iostream>

using namespace std;

//���캯��Ĭ����˽�е�
class A
{
public:
	A();
	~A();
	static int i;
private:

};

A::A()
{
}

A::~A()
{
}
//1 static�ؼ��� ���� ������ķ��ʻ���
//2 ��仰���Ǽ򵥵ı�����ֵ ����Ҫ���Ǹ���c++������ �����ڴ� ���ڼ̳������õ���a�� ��Ȼ�ᱨ���
//3 A������ӹ��캯�� Ĭ����˽�е� ������Ҫ�ѹ��캯�����˽�е�
int A::i = 200;


class B :private A
{
public:
	B();
	~B();

private:
};

B::B()
{
}

B::~B()
{
}

int main()
{
	A a;
	B b;
	system("pause");
	return 0;
}