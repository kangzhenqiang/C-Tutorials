
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*��������
	���ر�����ͬһ������
	�����޷����ظ���ĺ���������ͬ�������������Ƹ���
	�������ڱ����ڼ���ݲ������ͺ͸���������������
	*/

/*������д
	���뷢���ڸ���������֮��
	���Ҹ����������еĺ�����������ȫ��ͬ��ԭ��
	ʹ��virtual����ֻ���ܹ�������̬�����������virtual���ǽ��ض��壩
	��̬���������ڼ���ݾ����������;�����������
*/

/*
	��д��Ϊ2��
	1���麯����д ��������̬
	2�����麯����д ���ض��壩
*/


class Parent
{
public:
	Parent();
	~Parent();

	virtual void func()
	{
		cout << "func" << endl;
	}

	virtual void func(int i)
	{
		cout << "func(int i)" << endl;
	}

	virtual void func(string s)
	{
		cout << "func(string s)" << endl;
	}

private:

};

Parent::Parent()
{
}

Parent::~Parent()
{
}

class B :public Parent
{
public:
	B();
	~B();

	virtual void func()
	{
		cout << "B::func" << endl;
	}

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
	B B;
	B.func();//�����޷����ظ���ĺ���������ͬ�������������Ƹ���
	B.Parent::func(1);

	//1 c++������ ����func���֣���Ϊ����func�����Ѿ������ˣ����Ƹ��ǣ�������c++����������ȥ�Ҹ����4������func����
	//2 c++������ ֻ���������У�����func�������ҵ�������func��һ����2�������ģ�һ����3��������
	//3 c++������ ��ʼ����.... error c2661��"B::func" û�����غ�������4������ 

	system("pause");
	return 0;
}
