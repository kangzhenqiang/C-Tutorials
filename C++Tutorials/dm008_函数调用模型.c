//可能因为一些老的.c文件使用了strcpy,scanf,malloc等不安全的函数，而报警告和错误，而导致无法编译通过
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main函数中可以在栈上分配内存、可以在堆上分配内存、可以在全局区分配内存
//结论：可以被fa、fb使用
//fb中申请的内存，可以被main使用吗？
//1.fb中在栈上分配的内存，不能被fa和main函数使用
//2.fb中malloc的内存（堆），可以被main函数和fa函数使用
//3.fb中全局区分配“abcdefg”，内存是可以被fa和main函数使用的

//c++编译器会为每一个应用程序创建一个内存四区，相当于程序执行空间
void maindm008()
{
	 
	system("pause");
}