
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>
#include<vector>
#include<list>
#include<set>
#include<functional>
#include <algorithm>


using namespace std;


/*
	�㷨��
		�������������˺������ò��������࣬����󳣳�Ϊ�����ԣ�function object��

*/


/*
	�������� �����أ���������
	*/

//for_each�㷨�У�������������������
//for_each�㷨�У���������������ֵ
template<typename T>
class ShowElemt
{
public:
	ShowElemt()
	{
		n = 0;
	}

	void operator()(T& obj)
	{
		n++;
		//printN();
		cout << obj << endl;
	}

	void printN()
	{
		cout << n << endl;
	}
private:
	int n;
};


template<typename T>
void Show(T& t)
{
	cout << t << endl;
}

void ShowShow(int& a)
{
	cout << a << endl;
}

/*
	�������� ���壺 �����������ͨ��������ͬ
	*/


	//���������������������ͻ�ƺ����ĸ���ܱ��ֵ���״̬��Ϣ
int main()
{
	int a = 10;
	ShowElemt<int> showElem;
	showElem(a);//��������ģ���ִ�к���һ������ �º���

	Show<int>(a);
	ShowShow(a);

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//for_each(v.begin(), v.end(), ShowElemt<int>());//�������� �����º���


	//for_each(v.begin(), v.end(), ShowShow);//ͨ���ص����� ˭ʹ��for_each˭ȥ��д�ص���������ڵ�ַ

	ShowElemt<int> show;
	//�������� ����������
	//for_eache�㷨�� ����������Ԫ�ش��ݣ��������ô���
	show = for_each(v.begin(), v.end(), show);//�������� �����º���

	cout << "ͨ��for_each�㷨����ֵ�����õĴ���" << endl;
	
	show.printN();

	//for_each���صĶ���
	//���� Ҫ�㣺�����stl�㷨���ص�ֵ�ǵ��������� ν�ʣ�����������stl�㷨���ŵ���Ҫ��
	system("pause");
	return 0;
}
