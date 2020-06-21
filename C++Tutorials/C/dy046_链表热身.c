
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
struct Teacher
{
	char name[64];
	int id;
	char* p;
	char** p2;
};


typedef struct Teacher Teacher;
*/

typedef struct Student
{
	char name[64];
	int id;
} Student;

typedef struct Teacher
{
	char name[64];
	int id;
	char* p;
	char** p2; 
	Student s;
	Student* ps;
} Teacher;




//1 结构体中嵌套一个结构体
//2 结构体得指针
//3 结构中套一个 自己类型得结构体元素是不行的
//数据类型得本质，固定大小内存块得别名
//4 结构体中套一个指向自己类型的指针

//在自己类型大小还没有确定的情况下 引用自己类型的元素 是不正确的
//结构体不饿能嵌套定义（确定不了数据类型的分配不了内存）

typedef struct AdcTeacger {
	char name[64];
	int id;
	struct AdcTeacger* adcTeacher;
} AdcTeacger;


//函数的嵌套调用 和 结构数据类型嵌套定义不是一回事

void maindy046()
{
	char* p = NULL;
	system("pause");
}
