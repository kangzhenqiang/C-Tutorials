#include <iostream>

using namespace std;

class HeroFighter
{
public:
	HeroFighter();
	~HeroFighter();

	//不写virtual关键字 是静态联编  c++编译器根据HeroFighter类型，去执行 这个类型的power函数 在编译器编译阶段就已经决定函数的调用
	//动态联编：迟绑定：在运行的时候，根据具体对象（具体类型），执行不同对象的函数，表现成多态
	virtual int power()
	{
		return 10;
	}

private:

};

HeroFighter::HeroFighter()
{

}

HeroFighter::~HeroFighter()
{

}

class EnemyFighter
{
public:
	EnemyFighter();
	~EnemyFighter();

	int attck()
	{
		return 15;
	}

private:

};

EnemyFighter::EnemyFighter()
{
}

EnemyFighter::~EnemyFighter()
{
}

class AdvHeroFighter :public HeroFighter
{
public:
	AdvHeroFighter();
	~AdvHeroFighter();

	virtual int power()
	{
		return 20;
	}

private:

};

AdvHeroFighter::AdvHeroFighter()
{
}

AdvHeroFighter::~AdvHeroFighter()
{
}

void Play(HeroFighter* he, EnemyFighter* ef)
{
	if (he->power() > ef->attck())
	{
		cout << "主角赢了" << endl;
	}
	else
	{
		cout << "主角挂了" << endl;
	}
}


/*
	封装：突破c函数的概念... 用类做函数参数的时候，可以使用对象的属性和对象的方法
	继承：A B 代码复用...
	多态：可以使用未来...
	*/

/*
	实现多态的三个条件
		C语言中间接赋值是指针存在的最大意义
		是c语言的特有现象（1 定义两个变量 2 建立关联 3 *p在被调函数中间接的去修改实参的值）
		1、要有继承
		2、要有函数重写
		3、用父类指针（父类引用）指向子类对象
	*/

int main()
{
	HeroFighter he;
	AdvHeroFighter ad;
	EnemyFighter en;

	Play(&he, &en);
	Play(&ad, &en);
	system("pause");
	return 0;
}