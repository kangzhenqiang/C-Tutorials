#include <iostream>

using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

//指针所指向的内存空间不能被修改
int operatorTeacher(const Teacher* pTeacher)
{
	//pTeacher->age = 10;
	pTeacher = NULL;
	return 0;
}

//指针变量本身的内存空间不能被修改
int operatorTeacherConst(Teacher* const pTeacher)
{
	pTeacher->age = 10;
	//pTeacher = NULL;
	return 0;
}

//指针变量本身的内存空间和指向的内存空间都不能被修改
int operatorTeacherConstConst(const Teacher* const pTeacher)
{
	//pTeacher->age = 10;
	//pTeacher = NULL;
	return 0;
}


void maindy04001()
{
	//一样
	const int a = 5;
	int const b = 10;

	//const int* c;//const修饰的指针指向的内存空间，不能被修改
	//const int* const d;

	//c语言中的const是个冒牌货

	/*
	//a好像是一个常量
	const int a = 10;
	*/
	int* p = NULL;
	p = (int*)&a;
	*p = 20;

	/*
		const在c++中是一个真正的常量
		c++中符号表 key:a value:10
		p = （int*）&a;再次分配内存空间
		
		C语言中const变量
			c语言中const变量是只读变量，有自己的存储空间
		c++中的const常量
			可能分配存储空间，也可能不分配存储空间
			当const常量为全局，并且需要在其它文件中使用
			当使用&操作符取cosnt常量地址
	*/

	printf("a:%d\n", a);

	system("pause");
	return;
}