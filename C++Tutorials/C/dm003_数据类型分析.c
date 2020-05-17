#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//数据类型定义别名 typedef

typedef struct Teacher
{
	char name[64];
	int age;
} Teacher;//.c 中需要重命名，.cpp中不需要

typedef int u32;


void maindm003()
{
	int a;//告诉编译器分配4个字节的内容
	int b[10];//告诉编译器分配40个字节的内存

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d \n", b, b + 1, &b, &b + 1);

	printf("sizeof(a):%d\n", sizeof(a));//4

	printf("sizeof(b):%d\n", sizeof(b));//40

	//b+1 &b+1 结果不一样 b 和 &b 所代表的数据类型不一样
	//b 代表的数组首元素的地址
	//&b 代表的是整个数据的地址
	//b &b 是数组数据类型 （1.定义一个数组类型 2.数组指针 3.数组类型和数组指针类型的关系）=====>压死初学者的三座大山


	printf("u32:%d\n", sizeof(u32));


	system("pause");
}


//数据类型概念
//类型是对数据的抽象
//类型相同的数据有相同的表示形式、存储格式以及相关操作
//程序中使用的所有数据类型必定属于某一种数据类型
//数据类型：
	//简单类型：基本类型（整形 （int）、浮点型 （float）、字符型（char）、空类型(void)）、用户定义类型（枚举）
	//结构类型：数组（[]）、结构（struct）、联合(union)、类（class）
	//指针类型：*
//数据类型的本质思考
	//是为在编译器中方便表示现实中的事物模型
//数据类型的本质
	//数据类型可理解为创建变量的模具：固定内存大小的别名；

//数据类型的封装
//1.void 的字面意思是“无类型”，void * 则为“无类型指针”，void *可以指向任何类型的数据

//2.用法1：数据类型的封装
			//int InitHardEnv(void** hande);
			//典型的如内存操作函数memcpy和memset的函数原型为：
					// void* memcpy(void* dest,const void* src,size_t len);
					// void* memset(void* buffer, int c, size_t num);

//3.用法2：void修饰函数返回值和参数仅表示无
		//如果函数没有返回值，那么应该将其申明为void类型
		//如果函数没有参数，应该声明为void
			int function(void)
			{
				return 1;
			}

//4.void 指针得到意义
			//C 语言规定只有相同类型的指针才可以相互赋值
			//void* 指针作为左值用于“接收”任意类型的指针
			//void* 指针作为右值给其它指针类型需要强制转换
			//int *p=NULL;
			//char *p=(char*)malloc(sizeof(char)*20)

//5.不存在void类型的变量
			//C 语言没有定义void究竟是多大内存的别名

//6.扩展阅读void类型详解

//思考：函数可以看成一种数据类型吗？
