#include <iostream>

using namespace std;
//构造函数中调用构造函数是危险行为
class AA
{
public:
	AA(int a);
	~AA();

private:

};

AA::AA(int a)
{
}

AA::~AA()
{
}

class BB
{
public:
	BB(int a, int b);
	BB(int a, int b, int m, int n);
	~BB();

private:
	int m_a;
	int m_b;
	AA m_a1;
	AA m_a2;
	const int c;
};

//1 构造函数的初始化列表 解决：在B类中 组合了一个A类对象（A类设计了构造函数）
//根据构造函数的调用规则 设计A的构造函数，必须要用；没有机会初始化AA

BB::BB(int a, int b) :m_a1(10), m_a2(5), c(0)
{
	m_a = 0;
	m_b = 0;
}

BB::BB(int a, int b, int m, int n) :m_a1(m), m_a2(n), c(0)
{
	m_a = 0;
	m_b = 0;
}


BB::~BB()
{
}


//2 先执行 被组合对象的构造函数
//如果组合对象有多个，按照定义顺序，而不是按照初始化列表的顺序
//析构函数和构造函数的调用顺序相反 
//3 被组合对象的构造顺序 与 定义的顺序有关系，与初始化列表的顺序没有关系

//4 初始化列表用来给const属性赋值
int maindy024()
{
	BB b(1, 2);
	BB b1(1, 2, 3, 5);
	return 0;
}