#include <iostream>

using namespace std;

class Kangzhenqiang
{
public:
	Kangzhenqiang(const Kangzhenqiang& obj);
	Kangzhenqiang(int a);
	~Kangzhenqiang();

private:

};

Kangzhenqiang::Kangzhenqiang(const Kangzhenqiang& obj)
{

}

Kangzhenqiang::Kangzhenqiang(int a)
{

}

Kangzhenqiang::~Kangzhenqiang()
{
}

//当类中定义了拷贝构造函数时，c++编译器不会提供无参构造函数
//当类中定义了有参拷贝函数时，c++编译器不会提供无参构造函数

//在定义类时，只要你写了构造函数，则必须要用

int maindy023()
{
	//Kangzhenqiang t;//调用无参构造函数

	return 0;
}