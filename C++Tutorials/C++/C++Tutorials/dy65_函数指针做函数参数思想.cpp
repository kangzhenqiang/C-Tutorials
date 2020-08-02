
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


//任务的实现者
int add(int a, int b)
{
	cout << "add" << endl;
	int sum = a + b;
	return sum;
}

//任务的实现者
int sub(int a, int b)
{
	cout << "add" << endl;
	int sub = a - b;
	return sub;
}

typedef int (*MyPointerFuncAdd)(int a, int b);//对应c#中的委托

//任务调用者
int mainOp(MyPointerFuncAdd func)
{
	int sum = func(1, 5);
	return sum;
}

//函数指针类型起到的作用是把函数的参数、函数返回值提前约定
int mainOpOp(int(*MyPointerFuncAdd)(int a, int b))
{
	int sum = MyPointerFuncAdd(1, 5);
	return sum;
}


//任务的调用和任务的实现分开
int main()
{
	//c语言中什么变量必须放在开头

	//直接调用
	add(1, 3);

	//间接调用
	MyPointerFuncAdd myFunc = add;
	myFunc(4, 5);

	mainOp(add);

	mainOp(sub);

	mainOpOp(add);

	system("pause");
	return 0;
}
