
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct AdvTeacher {
	char name[64];
	int age;
	int p;
	char* pName;
} AdvTeacher;

void maindy040001()
{
	AdvTeacher t1;
	//指针就是一个变量
	AdvTeacher* teacher = NULL;
	//strcpy(0,"aaaa");拷贝出错

	teacher - 1;//编译通过 运行通过 这句话是在cpu中计算

	{
		int offsize = (int)&(teacher->age);
		printf("offsize:%d\n", offsize);
	}

	system("pause");
}

void maindy040002()
{
	AdvTeacher t1;
	//指针就是一个变量
	AdvTeacher* teacher = NULL;
	//strcpy(0,"aaaa");拷贝出错

	teacher - 1;//编译通过 运行通过 这句话是在cpu中计算

	{
		int offsize = (int)&(((AdvTeacher*)0)->age);
		//int offsize = (int)&(teacher->age);
		printf("offsize:%d\n", offsize);
	}

	system("pause");
}
