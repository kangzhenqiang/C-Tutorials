// C++Tutorials.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//包含C++的头文件
#include <iostream>

//使用命名空间 std 标准的命名空间（在这个命名空间中定义很多标准定义）
using namespace std;

int main01()
{
	//cout标准输出 
	//<<左移操作符 在c++中 功能的改造（增强）====>c++ 语言操作符重载
	//endl 换行
	std::cout << "Hello World!" << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


//标准输入和标注输出cin和cout始终写在操作符的左边

//求圆的面积
//用过程的方法
void main02()
{
	double r = 0;
	double s = 0;
	cout << "请输入圆的半径：";
	//cin代表标准输入
	cin >> r;
	cout << "r的值是：" << r << endl;

	s = 3.14 * r * r;
	cout << "圆形的面积是s：" << s << endl;
	system("pause");
}

typedef struct Circle
{

	/// <summary>
	/// 面积
	/// </summary>

	double m_s;
	/// <summary>
	/// 半径
	/// </summary>
	double m_r;

} Circle;


class MyCircle
{
public:
	MyCircle();
	~MyCircle();

	/// <summary>
	/// 成员函数，设置半径
	/// </summary>
	/// <param name="r"></param>
	void setR(double r)
	{
		m_r = r;
	}

	/// <summary>
	/// 成员函数，获取半径
	/// </summary>
	/// <returns></returns>
	double getR()
	{
		return m_r;
	}

	/// <summary>
	/// 成员函数，获取面积
	/// </summary>
	/// <returns></returns>
	double getS()
	{
		return 3.14 * m_r * m_r;
	}

private:
	/// <summary>
	/// 面积
	/// </summary>

	double m_s;
	/// <summary>
	/// 半径
	/// </summary>
	double m_r;
};

MyCircle::MyCircle()
{
}

MyCircle::~MyCircle()
{
}


//求圆的面积
//用面向对象的方法
//面向过程加工的是一个一个的函数
//面向对象建工的是一个一个的类

//类的执行调用过程 类执行过程分析===>类代码不是一步一步指向
//类是一个数据类型（规定大小内存块的别名），定义一个类，是一个抽象的概念，不会去给你分配内存

//c++编译器是如何区分c1对象，c2对象，c3对象调用了类的方法

//class类是一个数据类型和对象1：n关系

//学习C++的方法和面向过程方法是不一样的

//类是把属性和方法进行了封装
//封装、继承、多态

/*
	面向对象的分析 OOA
	面向对象的设计 OOD
	面向对象的编程 OOP
	面向对象的测试 OOT
	面向对象的围护 OOSM
*/

/*
	面向过程程序设计：数据结构+算法
	面向对象程序设计：根据显示世界的元素构件软件模型
*/

/*
	C++是C语言的加强，是一种更好的C语言
	C++是以C语言为基础，支持面向对象，对类型、函数、异常处理进行加强

	C语言常识  不要固步自封
*/

void main003()
{
	//实例化过程就是用类定义变量
	MyCircle c1, c2, c3;
	double r = 0;
	cout << "请输入C1圆的半径：";
	cin >> r;
	//给c1圆的属性赋值
	c1.setR(r);

	cout << "C1圆的面积是：" << c1.getS() << endl;

	cout << "请输入C2圆的半径：";
	cin >> r;
	//给c1圆的属性赋值
	c2.setR(r);

	cout << "C2圆的面积是：" << c2.getS() << endl;

	system("pause");
}
