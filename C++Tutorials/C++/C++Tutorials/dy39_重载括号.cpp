#include <iostream>

using namespace std;

class F
{
public:
	F();
	~F();

	int operator()(int a, int b)
	{
		return a + b;
	}

private:

};

F::F()
{
}

F::~F()
{
}


int main()
{
	F f;
	f(3, 5);
	cout << f(6, 6) << endl;
	//operator()(3,5)
	system("pause");
	return 0;
}