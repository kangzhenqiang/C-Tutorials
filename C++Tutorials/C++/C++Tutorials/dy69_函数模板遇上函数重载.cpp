
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//�����Ͳ��������������Ա����
template<typename T>
void myswap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	cout << "����ģ�庯��" << endl;
}

//��ͨ����
void myswap(int a, char c)
{
	cout << "a:" << a << " " << "c:" << c;
	cout << "������ͨ����" << endl;
}



int main()
{
	int a = 10;
	int b = 20;
	myswap<int>(a, b);//���ú���ģ�壨���ʣ����Ͳ����������������ϸ�����ͽ���ƥ�䣬��������Զ�����ת��
	myswap(a, b);

	myswap(a, 'k');//��ͨ�������͵��ã����Խ�����ʽ������ת��

	system("pause");
	return 0;
}
