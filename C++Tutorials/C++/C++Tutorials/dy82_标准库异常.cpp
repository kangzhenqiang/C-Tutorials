
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class MyExcept :public exception
{
public:
	MyExcept(const char* p);
	~MyExcept();

	_NODISCARD virtual char const* what() const
	{
		cout << "my error:" << m_p << endl;
		return m_p;
	}

private:
	const char* m_p;
};

MyExcept::MyExcept(const char* p)
{
	this->m_p = p;
}

MyExcept::~MyExcept()
{
}

int main()
{
	try
	{
		throw MyExcept("�쳣");
	}
	catch (const MyExcept& e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "δ֪" << endl;
	}
	system("pause");
	return 0;
}
