#include<iostream>
using namespace std;

//常引用的技术架构
void miandy10001()
{
	//普通引用
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;

	//常引用
	int x = 10;
	const int& y = x;//常引用 是让变量引用只读属性 不能通过y去修改x
	
	//常引用 初始化 分为2种情况
	//1. 用变量 初始化 常应用
	{
		int n = 20;
		const int& m = n;
	}
	//2. 用字面量 初始化 常量引用
	{
		const int h = 10;//c++编译器把a放在符号表中
		//int& l = 40;//普通引用 引用一个字面量 请问字面量有没有内存地址 ？ 字面量没有内存
		//引用就是给内存取多个门牌号（多个别名）
		const int& j = 43;//c++ 编译器 会分配内存空间
	}

	system("pause");
}


struct  TeacherT
{
	char name[64];
	int age;
};

int printTeacherT(const TeacherT&t)
{
	//常量引用让实参变量拥有只读属性
	cout << t.age << endl;
	//t.age = 45;//报错
	return 0;
}

void maindy10002()
{
	TeacherT t;
	t.age = 36;
	printTeacherT(t);
	system("pause");
}