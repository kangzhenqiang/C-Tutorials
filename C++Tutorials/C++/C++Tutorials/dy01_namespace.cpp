#include <iostream>

using namespace std;

/*
	1. iostream �ļ���û�������ע��std ��Ҫ���ǳ���Ա�ֹ���д
	2. �����дusing namespace std; ��Ҫ��ʾ������std
	3. ���������ռ�
	4. ʹ�������ռ�
	*/

namespace namespaceA {
	int a=10;
}

namespace namespaceB {
	int a=20;
	namespace namespaceC {
		struct  Teacher
		{
			string name;
			int age;
		};
	}
}

void maindy001()

{
	cout << "namespace test" << endl;
	cout << namespaceA::a << endl;

	namespaceB::namespaceC::Teacher t1;

	t1.name = "kangzhenqiang";
	t1.age = 32;

	cout << t1.name << endl;
	cout << t1.age << endl;

	system("pause");
}

/*
	1. ��ʹ��<iostream>��ʱ�򣬸�ͷ�ļ�û�ж���ȫ�������ռ䣬����ʹ��namespace std��������Ҫ��ʾʹ��std;
	2. c++��׼Ϊ�˺�c���𿪣�ҲΪ����ȷʹ�������ռ䣬�涨ͷ�ļ������ú�׺.h
	3. c++�����ռ�Ķ��� namespace name{...}
	*/

