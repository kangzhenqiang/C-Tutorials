#include <iostream>

using namespace std;

/*
	1. new delete 操作符 c++的语法 mallco free是c的语法

	2. new 基础类型变量 分配数组变量 分配类对象 分配到堆上

	3. 基本语法
	
	*/

class TT
{
public:
	TT(int a);
	~TT();

private:
	int m_a;
};

TT::TT(int a)
{
	m_a = a;
}

TT::~TT()
{
}


int maindy026()
{
	//基础类型

	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	free(p);

	int* c = new int;//分配基础类型
	*c = 30;
	delete c;

	int* cc = new int(40);
	delete cc;

	//分配数组

	int* pp = (int*)malloc(sizeof(int) * 10);
	pp[0] = 1;
	free(pp);

	int* pArr = new int[10];
	pArr[0] = 10;

	delete[] pArr;

	//分配一个对象
	TT* t = (TT*)malloc(sizeof(TT));
	free(t);

	TT* tt = new TT(5);
	delete tt;

	return 0;
}