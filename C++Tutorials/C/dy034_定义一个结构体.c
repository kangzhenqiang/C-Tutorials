
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//定义一个结构体类型
//定义了一个数据类型 固定大小内存块的别名 还没有分配内存

//类型定义
typedef struct  Teacher
{
	char name[64];
	int age;
	int id;
} Teacher;


#pragma region  定义变量的三种方法
Teacher t;

//定义类型的同事定义变量
struct  Student
{
	char name[64];
	int age;
	int id;
} s1, s2;

struct
{
	char name[64];
	int age;
	int id;
} s3, s4;
#pragma endregion

#pragma region 初始化变量方法

Teacher teacher = { "kangzhenqiang",31,01 };

struct  Man
{
	char name[64];
	int age;
	int id;
} s5 = { "kang",32,02 };

struct
{
	char name[64];
	int age;
	int id;
} s6 = { "wang",32,003 };

#pragma endregion

void maindy034001()
{
	//用类型定义变量
	Teacher t1;//告诉编译器分配内存
	Teacher t2 = { "kangzhenqiang",32,001 };

	t1.age = 31;//t1. 操作符是干什么 有没有操作内存
				//是寻址操作 计算age相对于t1大变量的偏移量 ===> 计算cpu中进行
				//没有操作内存
	strcpy(t1.name, "kangzhenqiang");
	printf("t1.name:%s\n", t1.name);

	//通过指针的方式操作内存空间
	{
		Teacher* p = NULL;
		p = &t2;
		printf("p->age:%d\n", p->age);
		printf("p->name:%s\n", p->name);
	}

	system("pause");
}

void copyTeacher(Teacher to, Teacher from)
{
	to = from;
}

void copyTeacher02(Teacher* to, Teacher* from)
{
	//（*to） = （*from);
	*to = *from;
}

//内存四区模型

void maindy034002()
{
	Teacher t1 = { "kangzhenqiang",32,02 };
	Teacher t2;
	Teacher t3;

	t2 = t1;//=号操作下 编译器的行为

	//编译器给我们提供简单 = 号 赋值操作 我们要顺从

	printf("t2.name:%s\n", t2.name);
	printf("t2.age:%d\n", t2.age);

	copyTeacher02(&t3, &t1);

	printf("t3.name:%s\n", t3.name);
	printf("t3.age:%d\n", t3.age);


	system("pause");
}
