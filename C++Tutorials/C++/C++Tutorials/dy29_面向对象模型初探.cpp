#include <iostream>

using namespace std;

class D1
{
public:
	D1();
	~D1();

private:
	int m_a;
	int m_b;
};

D1::D1()
{
	m_a = 0;
	m_b = 0;
}

D1::~D1()
{
}

class D2
{
public:
	D2();
	~D2();

	int getValue()
	{
		return 0;
	}

private:
	int m_a;
	int m_b;
	static int m_c;
};

struct S1
{
	int a;
	int b;
};

struct S2
{
	int a;
	int b;
	static int c;
	int getValue()
	{
		return 0;
	}
};

D2::D2()
{
	m_a = 0;
	m_b = 0;
}

D2::~D2()
{
}


int maindy029()
{
	return 0;
}