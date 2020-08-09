
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	C风格的强制类型转换(Type Cast)很简单，不管什么类型的转换统统是：TYPE b = (TYPE)a

	C++风格的类型转换提供了4中类型转换操作符来应对不同场合的应用：

		static_cast 静态类型转换，如 int 转换成 char

		reinterpreter_cast 重新解释类型

		dynamic_cast 命名上理解是动态类型转换，如子类和父类之间的多态类型转换

		const_cast 字面上理解就是去const属性

		4中类型转换的格式：
		TYPE B = static_cast<TYPE>(a)

	*/


class Aninal
{
public:
	virtual void cry() = 0;
private:

};


class Dog :public Aninal
{
public:
	virtual void cry()
	{
		cout << "汪汪" << endl;
	}

	void doHome()
	{
		cout << "看家" << endl;
	}

private:

};


class Cat :public Aninal
{
public:
	virtual void cry()
	{
		cout << "喵喵" << endl;
	}

	void doThing()
	{
		cout << "抓老鼠" << endl;
	}

private:

};


void playObj(Aninal* base)
{
	base->cry();
	//dynamic_cast 运行时类型识别

	Dog* dog = dynamic_cast<Dog*>(base);

	if (dog != NULL)
	{
		dog->doHome();
	}

	Cat* cat = dynamic_cast<Cat*>(base);

	if (cat != NULL)
	{
		cat->doThing();
	}

}

class Tree
{
public:

private:

};


//const char* p 的const修饰 让p指向的内存空间 变成只读属性
void printBuf(const char *p)
{
	//p[0] = 'x';
	char* p1 = NULL;

	p1 = const_cast<char*>(p);
	
	p1[0] = 'Z';
}

/*
	类型转换：
		结论1 程序员要清楚的知道，要转的变量，类型转换前是什么类型，类型转换后是什么类型，转换后有什么后果
		结论2 一般情况下，不建议进行类型转换，避免进行类型转换
*/


int main()
{
	char buf[] = "kangzhenqiang";

	//静态变量不允许修改
	const char* my = "wangjing";

	//程序员 要确保 p所指向的内存空间 确实能修改，如果不能修改会带来灾难性后果
	printBuf(buf);
	printBuf(my);
	cout << buf << endl;
	return 0;
}


int mian02()
{
	Dog d;
	Cat c;

	Aninal* base = NULL;

	base = static_cast<Aninal*>(&d);//让c++编译器在编译的时候进行类型检测

	base = reinterpret_cast<Aninal*>(&c);//强制类型转换

	Tree t;

	{

		//base = static_cast<Aninal*>(&t);//让c++编译器在编译的时候进行类型检测

		base = reinterpret_cast<Aninal*>(&t);//强制类型转换 重新解释 强制类型转换的味道

	}



	playObj(&d);

	playObj(&c);
	return 0;
}


int main01()
{
	/*C风格*/
	double dPi = 3.1415926;
	int num1 = (int)dPi;//C类型转换
	int num2 = static_cast<int>(dPi);//静态类型转换 编译的时候c++编译器会做类型检查
	int num3 = dPi;//c语言中 隐式类型转换的地方均可使用static_cast<>()进行类型转换

	//char *p =====> int *
	const char* p1 = "kangzhenqiang";

	const int* p2 = NULL;

	//p2 = static_cast<int*> (p1);//使用static_cast<TYPE>(),编译器编译时，会做类型检查，若有错误 提示错误

	//p2 = reinterpret_cast<int*>(p1);//若不同类型之间，进行强制类型转换，用reinterpret_cast()进行重新编译

	system("pause");
	return 0;
}
