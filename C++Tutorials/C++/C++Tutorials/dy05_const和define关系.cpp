#include<iostream>

using namespace std;


/*
	const和#define相同之处
	c++中const常量类似于宏定义

	const int a=5; 约等于 #define c 5;
	const 常量是由编译器处理的，提供类型检查和作用域检查
	const 定义是由作用域的
	*/

//const和#define相同之处
//#define是在编译之前处理的

void maindy05001()
{
	const int a = 10;
	int b = 20;

	//int array[a];

	//int array[a + b];
	//linux内核里面是支持的，原因 编译linux内核的gcc编译器支持
	//c和c++编译器不支持这种语法现象

	//限制作用域卸载

#define c 10 //定义宏


#undef c //卸载宏
	
}
