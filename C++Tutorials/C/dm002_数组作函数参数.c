//数组作函数参数

#include <stdio.h>
#include <string.h>

//排序

void maindm002m01()
{
	int a[] = { 33,34,65,12,25 };

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d\n", *(a + i));
	}

	int temp = 0;

	//排序 冒泡 从小到大
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		for (size_t j = i; j < sizeof(a) / sizeof(int); j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("Sort Arr\n");

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d\n", *(a + i));
	}

	system("pause");
}


//数组作函数参数，会退化为一个指针
//结论：
//		1、把数组的内存首地址和数组的有效长度传递给被调函数
//		2、实参arr和形参arr的数据类型本质不一样，形参中的数组，编译器会把它当成指针处理 这是C语言的特色
//		3、形参写在函数上和写在函数内是一样的，只不过是具有对外属性

//打印
//void printArr(int arr[], int count)//数组写法
void printArr(int* arr, int count)//指针写法
{
	for (size_t i = 0; i < count; i++)
	{
		printf("%d\n", *(arr + i));
	}
}

//排序
//void sortArr(int arr[], int count)
void sortArr(int* arr, int count)
{
	//实参arr和形参arr的数据类型本质不一样
	//形参中的数组，编译器会把它当成指针处理 这是C语言的特色

	int temp = 0;
	//排序 冒泡 从小到大
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i; j < count; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void maindm002m02()
{
	int a[] = { 33,34,65,12,25 };
	printArr(a, 5);
	sortArr(a, 5);
	printf("Sort Arr");
	printArr(a, 5);
	system("pause");
}