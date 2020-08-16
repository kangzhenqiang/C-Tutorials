
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class MyArray
{
public:
	MyArray(int len);
	~MyArray();

	int& operator[](int index);

	int GetLen();
	class eSize
	{
	public:
		eSize(int size)
		{
			m_size = size;
		}
		void printf()
		{
			cout << "size:" << m_size << endl;
		}
	protected:
		int m_size;
	};

	class eNegative :public eSize
	{
	public:
		eNegative(int size) :eSize(size)
		{
			m_size = size;
		}
	};
	class eZero :public eSize
	{
	public:
		eZero(int size) :eSize(size)
		{
			m_size = size;
		}
	};
	class eTooBig :public eSize
	{
	public:
		eTooBig(int size) :eSize(size)
		{
			m_size = size;
		}
	};
	class eTooSmall :public eSize
	{
	public:
		eTooSmall(int size) :eSize(size)
		{
			m_size = size;
		}
	};

private:
	int m_len;
	int* m_space;
};

MyArray::MyArray(int len)
{
	if (len < 0)
	{
		throw eNegative(len);
	}
	else if (len == 0)
	{
		throw eZero(len);
	}
	else if (len > 1000)
	{
		throw eTooBig(len);
	}
	else if (len < 3)
	{
		throw eTooSmall(len);
	}

	m_len = len;
	m_space = new int[len];
}

int& MyArray::operator[](int index)
{
	return m_space[index];
}

int MyArray::GetLen()
{
	return m_len;
}

MyArray::~MyArray()
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_len = 0;
		m_space = NULL;
	}
}

int main()
{
	try
	{
		MyArray arr(-5);
		for (size_t i = 0; i < arr.GetLen(); i++)
		{
			arr[i] = i + 1;
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	catch (MyArray::eSize& e)
	{
		e.printf();
	}
	catch (...)
	{

	}
	system("pause");
	return 0;
}


int main01()
{
	try
	{
		MyArray arr(5);

		for (size_t i = 0; i < arr.GetLen(); i++)
		{
			arr[i] = i + 1;
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	catch (const MyArray::eNegative& e)
	{

	}
	catch (const MyArray::eZero& e)
	{

	}
	catch (const MyArray::eTooBig& e)
	{

	}
	catch (const MyArray::eTooSmall& e)
	{

	}
	system("pause");
	return 0;
}
