
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const char* pfname = "C:/Users/Administrator/Desktop/out.txt";
	ofstream fout(pfname,ios::out);//��������Ժ��ļ�����
	fout << "kangzhenqiang" << endl;
	fout << "����ǿ" << endl;
	fout.close();

	//���ļ�
	char buf[1024];
	ifstream fin(pfname,ios::in);
	char ch;
	while ((ch=fin.get())!=EOF)
	{
		cout << ch;
	} 
	fin.close();

	system("pause");
	return 0;
}
