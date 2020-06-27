#include<iostream>
using namespace std;


struct Dog
{
	char name[64];
	int age;
};

//在被调用函数获取一个内存块
void getDog(Dog** p)
{
	Dog* tempDog = NULL;
	if (p == NULL)
	{
		return;
	}
	tempDog = (Dog*)malloc(sizeof(Dog));
	if (tempDog == NULL)
	{
		return;
	}
	strcpy_s(tempDog->name, "HiHi");
	tempDog->age = 5;
	//p是实参的地址， *实参的地址去间接的修改实参的值
	*p = tempDog;
}

//释放内存空间
void freeDog(Dog** p)
{
	if (p != NULL)
	{
		free(p);
		*p = NULL;
	}
}

//指针引用
int getDogDog(Dog*& p)
{
	p = (Dog*)malloc(sizeof(Dog));
	strcpy_s(p->name, "HeiHei");
	p->age = 6;
	return 0;
}

void maindy09001()
{
	Dog* p = NULL;
	//1. c语言中的二级指针
	getDog(&p);
	cout << p->name << endl;
	cout << p->age << endl;
	freeDog(&p);

	//2. c++中的引用（指针的引用）
	//引用的本质 间接赋值后2个条件让c++编译器帮我们程序要做了
	getDogDog(p);
	cout << p->name << endl;
	cout << p->age << endl;
	freeDog(&p);

	system("pause");
}