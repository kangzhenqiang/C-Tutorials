
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


/*
   �������ͻ����﷨����
   ����һ����������
   int a[10]

   ����һ��ָ����������

   ���� һ��ָ�� �������͵�ָ�� ������ָ��
*/

int main()
{
	int a[10];//a�������������Ԫ�صĵ�ַ &a������������ĵ�ַ a+1 4 &a+1 40

	{
		typedef int(myTypeArray)[10];
		myTypeArray arr;
		arr[0] = 10;
		cout << arr[0] << endl;

	}

	{
		typedef int(*pType)[10];//int *p

		pType p;//sizeof(int) * 10
		p = &a;
		(*p)[0] = 20;
		cout << (*p)[0] << endl;
	}

	{
		//����һ��ָ�� ��ֵ��ĵ�ָ�� �������ָ��

		int(*Myp)[10];//���� ����c������ ���ҷ����ڴ�

		Myp = &a;

		(*Myp)[0] = 40;
		cout << (*Myp)[0] << endl;
	}

	system("pause");
	return 0;
}
