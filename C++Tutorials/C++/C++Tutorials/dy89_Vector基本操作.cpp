
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;


void VectorDisplay()
{
	vector<int> v;

	cout << "v length:" << v.size() << endl;
	//����Ԫ��
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);

	cout << "v front:" << v.front() << endl;

	//�޸�ͷ��Ԫ�ص�ֵ
	//��������ֵ����ֵ��Ӧ�÷���һ������
	v.front() = 11;
	v.back() = 55;

	//��ȡβ��Ԫ��
	while (v.size() > 0)
	{
		cout << v.back() << endl;
		v.pop_back();
	}
}

void VectorConstruct()
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);

	vector<int> v2 = v1;//�����ʼ��
	vector<int> v3(v1.begin(), v1.begin() + 3);

}

void printV(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void VectorRead()
{
	vector<int> v1(10);//��ǰ���ڴ�׼����

	for (size_t i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	printV(v1);
}

//push_backǿ������
void VectorPuchBack()
{
	vector<int> v1(10);//��ǰ���ڴ�׼����
	v1.push_back(100);
	printV(v1);
	cout << v1.size() << endl;
}


//������
/*
	1  3  5
	��it=v.end()ʱ��������ָ��ʼԪ��
	��it=v.end()ʱ���������Ѿ������꣬5�ĺ���

	���������ࣺ


	*/
void VectorIterator()
{
	vector<int> v(10);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = i + 1;
	}

	//�������
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//�������
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}

}

//ɾ��Ԫ�أ�����Ԫ��
void VectorDelete()
{
	vector<int> v(10);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = i + 1;
	}

	//����ɾ��
	v.erase(v.begin(), v.begin() + 3);
	printV(v);

	//ָ��λ��ɾ��
	v.erase(v.begin());
	printV(v);

	//����Ԫ�ص�ֵ
	v[1] = 2;
	v[2] = 2;
	printV(v);

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == 2)
		{
			it = v.erase(it);//�� ɾ����������ָ���Ԫ�ر�ɾ��ʱ��eraseɾ����������it�Զ����ƶ�
		}
		else
		{
			it++;
		}
	}

	printV(v);

	v.insert(v.begin(), 100);
	v.insert(v.end(), 200);
	printV(v);

}


int main()
{
	/*VectorDisplay();
	VectorConstruct();
	VectorRead();
	VectorPuchBack();
	VectorIterator();*/
	VectorDelete();
	system("pause");
	return 0;
}
