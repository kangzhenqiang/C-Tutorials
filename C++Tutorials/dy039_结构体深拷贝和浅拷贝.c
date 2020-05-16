
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Person
{
	char name[64];
	int age;
	char* alias;

} Person;

//浅拷贝
//编译器的=操作，指挥把指针变量的值从from copy到to,
//但不会把指针变量所指的内存空间给拷贝过去
//结构体中套一个1级指针或2级指针
//如过想执行深拷贝（cpoy），就显示分配内存
void copyPerson(Person* to, Person* from)
{
	*to = *from;
	//memcpy(to, from, sizeof(Person));
	//深拷贝
	to->alias = (char*)malloc(100);
	strcpy(to->alias, from->alias);
}

//典型深拷贝和浅拷贝
void maindy039()
{
	Person p1;
	Person p2;
	strcpy(p1.name, "kangzhenqiang");
	p1.alias = (char*)malloc(100);
	strcpy(p1.alias, "wangjing");

	copyPerson(&p2, &p1);

	if (p1.alias != NULL)
	{
		free(p1.alias);
		p1.alias = NULL;
	}

	if (p2.alias != NULL)
	{
		free(p2.alias);
		p2.alias = NULL;
	}

	system("pause");
}
