
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//传统出错处理机制
int my_strcpy(char* to, char* from)
{
	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}
	//拷贝
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return 0;
}


void my_strcpy1(char* to, char* from)
{
	if (from == NULL)
	{
		throw 1;
	}
	if (to == NULL)
	{
		throw 2;
	}
	//拷贝
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

//throw char *
void my_strcpy2(char* to, char* from)
{
	if (from == NULL)
	{
		throw "数据源出错";
	}
	if (to == NULL)
	{
		throw "目标buf出错";
	}
	//拷贝
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}


class BadStringErr
{
public:
	BadStringErr() {
		cout << "构造函数" << endl;
	}

	BadStringErr(const BadStringErr& obj) {
		cout << "拷贝构造函数" << endl;
	}

	~BadStringErr() {
		cout << "析构函数" << endl;
	}

private:

};


void my_strcpy3(char* to, char* from)
{
	//if (from == NULL)
	//{
	//	throw BadStringErr();//会不会产生匿名对象
	//}
	//if (from == NULL)
	//{
	//	throw &(BadStringErr());//会不会产生匿名对象,会产生错误
	//}
	if (from == NULL)
	{
		throw  new BadStringErr();//会不会产生匿名对象,会产生错误
	}
	if (to == NULL)
	{
		throw BadStringErr();
	}
	//拷贝
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}


int main()
{
	int ret = 0;
	char buf[] = "kangzhenqiang";
	char buf1[1024];

	/*my_strcpy(buf1, buf);
	if (ret != 0)
	{
		switch (ret)
		{
		case 1:
			cout << "数据源出错" << endl;
		case 2:
			cout << "模板buf出错" << endl;
		case 3:
			cout << "copy过程出错" << endl;
		default:
			cout << "未知错误" << endl;
			break;
		}
	}
	cout << buf1 << endl;


	try
	{
		char buf2[1024];
		my_strcpy1(buf2, buf);
	}
	catch (int e)
	{

	}
	catch (...)
	{

	}

	try
	{
		char buf3[1024];
		my_strcpy2(buf3, NULL);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{

	}*/

	try
	{
		my_strcpy3(buf1, NULL);
	}
	//catch (BadStringErr e)//是把匿名对象copy给e，还是e,还是匿名对象
	//{
		/*
		结论 1：
			如果接收异常时候使用一个异常变量则copy构造异常变量

		*/
		//}

		//catch (BadStringErr& e)//是把匿名对象copy给e，还是e,还是匿名对象
		//{
		//	/*
		//	结论 2：
		//		使用引用的化会使用throw那个对象

		//	*/
		//}
	catch (BadStringErr* e)//是把匿名对象copy给e，还是e,还是匿名对象
	{
		/*
		结论 3：
			指针可以和引用元素写在一块，但是元素和引用不能写再一块

		*/
		delete e;
	}
	system("pause");
	return 0;
}

