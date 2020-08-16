
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const char* pfname = "C:/Users/Administrator/Desktop/out.txt";
	ofstream fout(pfname,ios::out);//输出流可以和文件关联
	fout << "kangzhenqiang" << endl;
	fout << "康振强" << endl;
	fout.close();

	//读文件
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
