
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	�㷨������Ҫ����ɾ���ļ����ָ��
	ÿһ��ָ���ھ���ļ����cpu�����е�ʱ���ǹ̶���
	ͨ���������n�Ĳ���Ķ��پͿ����Ƶ����㷨�ĸ��Ӷ�

	*/

/*
	��˹��ʽ���
*/
int sum(int n)// 2 O(2)
{
	int ret = 0;//1��
	if (n>0)
	{
		ret = n * (n + 1) / 2;//1��
	}
	return ret;
}


int main()
{
	int s= sum(50);
	cout << s << endl;
	system("pause");
	return 0;
}
