
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>

using namespace std;

/*
	��׼���������� cin
		cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
		cin.get(һ������) //��ȡһ���ַ�
		cin.get(���ֲ���) //���Զ�ȡ�ַ���
		cin.getline()
		cin.ignore()
		cin.peek()
		cin.putback()
*/

int main()
{
	int myInt;
	cin >> myInt;
	cout << myInt;

	char buf[1024];
	//�����ո��������
	cin >> buf;
	cout << buf;
	 
	char ch;

	while ((ch=cin.get())!=EOF)
	{
		cout << ch << endl;
	}

	system("pause");
	return 0;
}
