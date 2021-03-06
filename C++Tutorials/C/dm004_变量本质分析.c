//变量概念
//概念：既能读又能写的内存对象，称为变量；若一旦初始化后不能修改的对象成为常量
//变量定义：类型 标识符，标识符，...，标识符；
//例如：
//		int x;
//		int wordCut, Radius, Height;
//		double FlightTime, Mileage, Speed;

//变量本质
//1.程序员通过变量来申请和命名内存空间 int a=0
//2.通过变量访问内心空间 (一段连续)内存空间的别名（是一个门牌号）
//3.修改变量的几种方法
	//1）直接
	//2）间接 内存有地址编号，拿到地址编号也可以修改内存
	//3）内存空间可以再取别名吗？
//4.数据类型和变量的关系
	//通过数据类型定义变量
//5.总结与思路
	//1.对内存，可读可写；
	//2.通过变量往内存读写数据;
	//3.不是向变量读写数据,而是向变量所代表的内存空间中写数据;
	//思考1：变量三要素（名称、大小、作用域），变量的生命周期？
	//思考2：c++编译器是如何管理函数1和函数2之间的关系？

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void maindm004()
{
	int a;
	int b;
	char* p;
	a = 10;//直接赋值
	printf("a:%d\n", a);

	*((int*)&a) = 200;//按照4个字节的方式操作内存

	printf("a:%d\n", a);

	p = &a;
	*p = 300;

	printf("a:%d\n", a);

	//对内存空间是可以取别名的
	system("pause");
}


