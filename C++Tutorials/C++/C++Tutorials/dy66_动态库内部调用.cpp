
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	dll框架 

		1. 在动态库内部
			需要提前定义好一套接口（函数指针类型定义）

		2. 在动态库外部
			发布一套接口协议（发布.h）

		3. 厂商 根据你的.h 实现函数原型 （编写子任务）

		4. 把厂商函数入口地址 注入到 框架中

		5. 在框架中，回调第三方的任务

	*/


int main()
{

	system("pause");
	return 0;
}
