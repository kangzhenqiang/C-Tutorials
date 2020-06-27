#include <iostream>

using namespace std;

/*
	类 封装有两层含义

	1. 把属性和方法进行封装
	2. 对属性和方法进行访问控制
	3. 类的内部和类的外部
	4. 类的访问控制关键字：
		public：修饰的成员变量和函数，可以在类的内部和类的外部访问
		private:修饰的成员变量和函数，可以只能在类的内部被访问，不能在类的外部访问
		protected:修饰的成员变量和函数，只能在类的内部被访问，不能在类的外部访问，用于继承里
*/


class MyCiircle
{
public:
	double m_r;//属性 成员函数
	double m_s;

public:
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}

	double get_S()
	{
		return 3.14 * m_r * m_r;
	}

protected:


private:

};

//封装的威力
//类封装成员比变量和成员函数 通过类的参数可以调用类的成员函数

void printMyCircle01(MyCiircle* pC)
{
	cout << pC->get_S() << endl;
	cout << pC->getR() << endl;
}

//引用
void printMyCircle02(MyCiircle& pC) 
{
	cout << pC.get_S() << endl;
	cout << pC.getR() << endl;
}

void printMyCircle03(MyCiircle pC)
{

}


//类的封装第一层含义
void maindy15001()
{
	MyCiircle c1;
	c1.setR(5);
	cout << c1.get_S() << endl;
	system("pause");
}

//类的封装第二次含义

class MyCicrleAdvance
{
private:
	double m_r;//属性 成员函数 默认时私有的
	double m_s;//类的私有成员和方法相当于银行密码不能被访问

public:
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}

	double get_S()
	{
		return 3.14 * m_r * m_r;
	}

protected:

};

void maindy15002()
{

	MyCiircle c1;
	c1.setR(5);

	MyCicrleAdvance c2;
	c2.getR();

	system("pause");
}

/*
	stuct 和 class 的区别
	*/

struct AAA
{
	int a;//默认属性是public的

public:

protected:

private:
		 
};

void miandy15003()
{
	AAA a;
	a.a;
}


