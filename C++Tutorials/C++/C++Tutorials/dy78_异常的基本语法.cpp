
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	1.�����﷨
	2.�����쳣���ǿ纯��
	3.�����쳣��ɲ������ٴ��׳�
	4.�쳣��׽������ƥ�䣬���ǲ���ƥ��
	5.catch�쳣��ʱ�򣬰������ͽ���catch

	*/


void divide(int a, int b)
{
	if (b == 0)
	{
		throw b;//�׳� int �����쳣
	}
	cout << "divide�����" << a / b << endl;
}


void myDivide(int a, int b)
{
	divide(a, b);
}

int main()
{
	try
	{
		/*divide(10, 2);
		divide(10, 0);*/
		//myDivide(100, 0);

		throw "Z";
	}
	catch (int e)
	{
		cout << "�����" << endl;
	}
	catch (const std::exception&)
	{

	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	system("pause");
	return 0;
}
