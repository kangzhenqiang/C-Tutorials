#include <iostream>

using namespace std;

/*
	1. 若你填写参数，使用你填写的，不填写默认
	2. 在默认参数规则，如果默认参数出现，那么右边的都必须有默认参数

	*/

void myPrint(int x = 3)
{
	cout << x << endl;
}

/*
	函数占位参数
		函数占位参数调用时必须写够参数
	*/


void myFun001(int a, int b, int)
{
	cout << a << b << endl;
}

/*
	默认参数和占位参数
	*/

void myFun002(int a, int b, int = 0)
{
	cout << a << b << endl;
}

void maindy12001()
{
	myPrint();
	myPrint(5);

	myFun001(1, 2, 6);

	myFun002(1, 2);//ok
	myFun002(1, 2, 3);//ok
	system("pause");
}