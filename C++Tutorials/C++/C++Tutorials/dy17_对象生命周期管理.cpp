/*
	类的构造和析构
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class  Test
{
public:
	Test();//构造函数
	~Test();//析构函数  清理对象 在对象析构时自动调用

private:

	int a;
	char* p = NULL;

};

Test::Test()//作用完成对属性的初始化工作
{
	a = 10;
	p = (char*)malloc(100);
	strcpy(p, "kangzhenqiang");
	cout << "我是构造函数" << endl;
}

Test::~Test()//释放资源
{
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
	cout << "我是析构函数" << endl;
}


//给对象搭建舞台，研究对象的行为

int objPlay()
{
	Test t1, t2;//析构，先创建的对象后释放

	return 0;
}

int maindy017()
{
	objPlay();
	system("pause");
	return 0;
}