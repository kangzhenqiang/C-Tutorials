#include<iostream>

using namespace std;

//拷贝构造函数
class Location
{
public:
	Location();
	Location(double x, double y);
	Location(const Location& obj);//不加const作函数返回值时提示无相应copy构造函数
	~Location();

	double GetX()
	{
		return m_x;
	}

	double GetY()
	{
		return m_y;
	}


private:

	double m_x;
	double m_y;

};

Location::Location()
{
	m_x = 0;
	m_y = 0;
	cout << "initilize" << endl;
}

Location::Location(double x, double y)
{
	m_x = x;
	m_y = y;
	cout << "X and Y initilize" << endl;
}

Location::Location(const Location& obj)
{
	m_x = obj.m_x;//使用私有字段赋值
	m_y = obj.m_y;
	cout << "X and Y copy" << endl;
}



Location::~Location()
{
	cout << "X and Y 销毁" << endl;
}


void f(Location l)
{
	cout << l.GetX() << endl;
}

void playObj()
{
	Location a(5, 5);
	Location b = a;
	f(b);//b去初始化形参p，会调用copy构造函数
}

/// <summary>
/// 返回一个元素
/// </summary>
/// <returns></returns>

/* 结论1：函数返回值是一个元素（赋值类型），返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数）*/
// 结论2：匿名对象的去和留 
// 如果用匿名对象 初始化另一个类型的对象，匿名对象 转换为有名对象
// 如果用匿名对象 赋值给另一个同类型的对象，匿名对象被析构
//你这么写代码，设计编译器的大牛们就会给你返回一个新对象（没有名字 匿名对象）
Location GetLocation()
{
	Location a(5, 5);
	return a;
}


int maindy021()
{
	playObj();

	//用匿名对象初始化m 此时c++编译器 直接把匿名对象扶正 从匿名转成有名字了
	//如果用匿名对象 初始化另一个类型的对象，匿名对象 转换为有名对象
	Location c = GetLocation();//默认调用

	Location d;
	//如果用匿名对象 赋值给另一个同类型的对象，匿名对象被析构
	d = GetLocation();
	system("pause");
	return 0;
}