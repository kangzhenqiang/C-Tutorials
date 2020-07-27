#include<iostream>

using namespace std;

/*
	多继承 第一种能解决 第二种不能解决（需要手动添加作用域）
	加virtual关键字C++编译器会给变量偷偷增加属性
*/


class B
{
public:
	B();
	~B();

private:

};

B::B()
{
	cout << "B构造函数" << endl;
}

B::~B()
{
}

class B1:public B
{
public:
	B1();
	~B1();

private:
	 
};

B1::B1()
{
}

B1::~B1()
{
}

class B2 :virtual public B
{
public:
	B2();
	~B2();

private:

};

B2::B2()
{
}

B2::~B2()
{
}

class C:public B1,public B2
{
public:
	C();
	~C();

private:
};

C::C()
{
}

C::~C()
{
}


class H
{
public:
	H();
	~H();
	int m_k;
private:
	
};

H::H()
{
	m_k = 0;
}

H::~H()
{
}

class K
{
public:
	K();
	~K();
	int m_k;
private:
	
};

K::K()
{
	m_k = 0;
}

K::~K()
{
}


class D:public K,public H
{
public:
	D();
	~D();

private:
};

D::D()
{
}

D::~D()
{
}

int main()
{
	C c;
	D d;

	system("pause");
	return 0;
}