#include <iostream>

using namespace std;

/*
	1. new delete c++操作符 mallco free是c的函数

	2. new 基础类型变量 分配数组变量 分配类对象 分配到堆上

	3. 基本语法

	4. 区别：
			mallco 只是分配内存 不会调用构造函数 new分配内存并初始化对象
			free 只是释放内存 不会调用类的析构函数
	5. 结论：
			
	*/

class TTT
{
public:
	TTT(int a);
	~TTT();

private:
	int m_a;
};

TTT::TTT(int a)
{
	m_a = a;
}

TTT::~TTT()
{
	cout << "析构" << endl;
}


int maindy027()
{
	//基础类型

	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	delete p;

	int* c = new int;//分配基础类型
	*c = 30;
	free(c);

	int* cc = new int(40);
	free(cc);

	//分配数组

	int* pp = (int*)malloc(sizeof(int) * 10);
	pp[0] = 1;
	delete[] pp;

	int* pArr = new int[10];
	pArr[0] = 10;

	free(pArr);

	//分配一个对象
	TTT* t = (TTT*)malloc(sizeof(TTT));
	delete t;

	TTT* tt = new TTT(5);
	free(tt);

	system("pause");
	return 0;
}