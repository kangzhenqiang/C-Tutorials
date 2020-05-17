#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



//数组
		//1）元素类型角度：数组是相同类型的变量的有序集合 测试指针变量占有内存空间大小
		//2）内存角度：连续的一大片的内存空间
//数组初始化：
		//1）数组元素的个数可以显示或隐式指定
		//2）分析数组初始化{0}和memset比较

//数组的技术盲点
//

void miandy030001()
{
	int a[] = { 1,2 };
	int b[100] = { 1,2 };

	int c[200] = { 0 };//编译时就已经确定 所有的值为零

	//对于一维数组规定：
	//c是首元素的地址 c+1 步长是4个字节
	//&c是整个数组的地址 &c+1 步长是800个字节
	memset(c, 0, sizeof(c));//显示的 重置内存块

	system("pause");
}

//怎么表达int a[10]这种数组类型？ int[]
//类型本质：固定内存块大小的别名

//数组类型
//1.数据类型分为基础、非基础，思考角度应发生变化
//2.C语言中的数组有自己的特定类型
	//数组的类型由其元素类型和数组大小共同决定

//定义数据类型
void maindy030002()
{
	typedef int(MyArray)[5];//定义了一个数据类型 数组数据类型
	int i = 0;
	MyArray myArray;//int myArray[5]

	for (int i = 0; i < 5; i++)
	{
		myArray[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", myArray[i]);
	}

	printf("myArray代表数组首元素地址:%d myArray+1:%d\n", myArray, myArray + 1);
	printf("&myArray代表整个数组地址:%d &myArray+1:%d\n", &myArray, &myArray + 1);

	system("pause");
	return;
}

//定义数组指针变量的方法
void maindy030003()
{
	char* myArray[] = { "11111","22222","33333" };//指针数组

	//数组指针 用一个指针 来指向一个数组

	typedef int(MyArrayType)[5];//定义了一个数据类型 数组数据类型
	MyArrayType myArr;//int myArr[5];//用类型定义变量

	int i = 0;
	MyArrayType* pArr;//定义一个指针变量 这个指针变量 指向一个数组

	{
		int a;
		int* p = NULL;
		p = &a;
	}

	{

		int myArray2[5];//相当于一级指针
		for ( i = 0; i < 5; i++)
		{
			myArray2[i] = i + 1;
		}

		pArr = &myArray2;

		for ( i = 0; i < 5; i++)
		{
			printf("%d\n", (*pArr)[i]);
		}
	}

	system("pause");
}

//定义数组指针变量的第二种方法
void maindy030004()
{
	//定义声明一个数组指针类型
	typedef int(*PArrayType)[5];
	PArrayType pArr;//告诉编译器 给我分配一个指针变量

	int c[5];

	pArr = &c;

	for (int i = 0; i < 5; i++)
	{
		(*pArr)[i] = i + 2;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*pArr)[i]);
	}
	system("pause");
}


//定义数组指针变量的第三种方法
//前两种方法 通过类型定义变量 比较麻烦
void maindy030005()
{
	int(*pMyArr)[5];//直接定义一个指向数组的变量
	int c[5];

	pMyArr = &c;

	for (int i = 0; i < 5; i++)
	{
		(*pMyArr)[i] = i + 2;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*pMyArr)[i]);
	}
	system("pause");
}



