
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

using namespace std;


void ListOperate()
{
	list<int> l;
	cout << "List count:" << l.size() << endl;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}
	cout << "List count:" << l.size() << endl;

	list<int>::iterator it = l.begin();

	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = l.begin();
	//list �����������
	it++;
	//it=it + 5;//��֧������ķ���
	//����Ԫ��
	l.insert(it, 100);//����100�����Ǹ�λ��

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����1�� 
		//����Ľڵ�index ����Ǵ�0��Ԫ��λ�ÿ�ʼ
		//��3��λ�ò���Ԫ�أ���ԭ����3��λ�ñ��4��λ�ã�ԭ����4��λ�ñ��5��λ��

	//ɾ��Ԫ�� �����ҿ�

	it = l.begin();
	it++;
	it++;
	it++;
	l.erase(l.begin(), it);
	l.remove(10);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	ListOperate();

	system("pause");
	return 0;
}
