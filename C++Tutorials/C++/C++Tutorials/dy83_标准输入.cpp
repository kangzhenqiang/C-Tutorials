
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>

using namespace std;

/*
	标准输入流对象 cin
		cin.get() //一次只能读取一个字符
		cin.get(一个参数) //读取一个字符
		cin.get(三分参数) //可以读取字符串
		cin.getline()
		cin.ignore()
		cin.peek()
		cin.putback()
*/

int main()
{
	int myInt;
	cin >> myInt;
	cout << myInt;

	char buf[1024];
	//遇到空格结束输入
	cin >> buf;
	cout << buf;
	 
	char ch;

	while ((ch=cin.get())!=EOF)
	{
		cout << ch << endl;
	}

	system("pause");
	return 0;
}
