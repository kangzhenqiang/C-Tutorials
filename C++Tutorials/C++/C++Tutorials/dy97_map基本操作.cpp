
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

/*
	map Ԫ����ӡ�������ɾ����������
	*/
void mapInsertAndIterator()
{
	map<int, string> maps;

	//����
	//���� 1
	maps.insert(pair<int, string>(1, "kangzhenqiang"));
	maps.insert(pair<int, string>(2, "wangjing"));
	//���� 2
	maps.insert(make_pair(3, "haohongmei"));
	maps.insert(make_pair(4, "zhangyaoyao"));
	//���� 3
	maps.insert(map<int, string>::value_type(5, "kangzhenqiang"));
	maps.insert(map<int, string>::value_type(6, "wangjing"));
	//���� 4
	maps[7] = "haohongmei";
	maps[8] = "zhangyaoyao";

	//��������
	for (map<int, string>::iterator it = maps.begin(); it != maps.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	while (!maps.empty())
	{
		map<int, string>::iterator it = maps.begin();
		cout << it->first << " " << it->second << endl;
		maps.erase(it);
	}
}

/*���ֲ��뷽����ͬ*/

void mapInsert()
{
	map<int, string> maps;

	//����
	//���� 1
	pair<map<int, string>::iterator, bool> pair1 = maps.insert(pair<int, string>(1, "kangzhenqiang"));
	if (pair1.second)
	{
		cout << "���� 1 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 1 ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> pair2 = maps.insert(pair<int, string>(2, "wangjing"));
	if (pair1.second)
	{
		cout << "���� 2 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 2 ʧ��" << endl;
	}
	//���� 2
	pair<map<int, string>::iterator, bool> pair3 = maps.insert(make_pair(3, "haohongmei"));
	if (pair1.second)
	{
		cout << "���� 3 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 3 ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> pair4 = maps.insert(make_pair(4, "zhangyaoyao"));
	if (pair1.second)
	{
		cout << "���� 4 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 4 ʧ��" << endl;
	}
	//���� 3
	pair<map<int, string>::iterator, bool> pair5 = maps.insert(map<int, string>::value_type(5, "kangzhenqiang"));
	if (pair1.second)
	{
		cout << "���� 5 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 5 ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> pair6 = maps.insert(map<int, string>::value_type(6, "wangjing"));
	if (pair1.second)
	{
		cout << "���� 6 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 6 ʧ��" << endl;
	}
	//���� 4
	maps[7] = "haohongmei";
	maps[8] = "zhangyaoyao";

	//ǰ���ַ������صĶ���pair,��key�Ѿ������򱨴�
	//����4 ���Ѿ������򸲸�
}

/*map ����*/
void mapFind()
{
	map<int, string> maps;

	//����
	//���� 1
	pair<map<int, string>::iterator, bool> pair1 = maps.insert(pair<int, string>(1, "kangzhenqiang"));
	if (pair1.second)
	{
		cout << "���� 1 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 1 ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> pair2 = maps.insert(pair<int, string>(2, "wangjing"));
	if (pair1.second)
	{
		cout << "���� 2 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 2 ʧ��" << endl;
	}

	//���� 2
	pair<map<int, string>::iterator, bool> pair3 = maps.insert(make_pair(3, "haohongmei"));
	if (pair1.second)
	{
		cout << "���� 3 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 3 ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> pair4 = maps.insert(make_pair(4, "zhangyaoyao"));
	if (pair1.second)
	{
		cout << "���� 4 �ɹ�" << endl;
	}
	else
	{
		cout << "���� 4 ʧ��" << endl;
	}

	map<int, string>::iterator it = maps.find(1);
	if (it == maps.end())
	{
		cout << "key 1 value not extist" << endl;
	}
	else
	{
		cout << it->first << " " << it->second << endl;
	}

	pair<map<int, string>::iterator, map<int, string>::iterator> myPair = maps.equal_range(3);
	/*
		��һ�������� >= 5 ��λ��
		�ڶ��������� = 5 ��λ��
		*/
	if (myPair.first == maps.end())
	{
		cout << "��һ�������� >= 3 ��λ�ò�����" << endl;
	}
	else
	{
		cout << myPair.first->first << '\t' << myPair.first->second << endl;
	}

	if (myPair.second == maps.end())
	{
		cout << "�ڶ��������� > 3 ��λ�ò�����" << endl;
	}
	else
	{
		cout << myPair.second->first << '\t' << myPair.second->second << endl;
	}

}

int main()
{
	mapInsertAndIterator();
	mapInsert();
	mapFind();


	system("pause");
	return 0;
}
