
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>
#include<vector>
#include<list>
#include<set>
#include<functional>
#include <algorithm>


using namespace std;


/*
	算法：
		函数对象：重载了函数调用操作符的类，其对象常称为函数对（function object）

*/


/*
	函数对象 类重载（）操作符
	*/

//for_each算法中，函数对象做函数参数
//for_each算法中，函数对象做返回值
template<typename T>
class ShowElemt
{
public:
	ShowElemt()
	{
		n = 0;
	}

	void operator()(T& obj)
	{
		n++;
		//printN();
		cout << obj << endl;
	}

	void printN()
	{
		cout << n << endl;
	}
private:
	int n;
};


template<typename T>
void Show(T& t)
{
	cout << t << endl;
}

void ShowShow(int& a)
{
	cout << a << endl;
}

/*
	函数对象 定义： 函数对象和普通函数的异同
	*/


	//函数对象是属于类对象，能突破函数的概念，能保持调用状态信息
int main()
{
	int a = 10;
	ShowElemt<int> showElem;
	showElem(a);//函数对象的（）执行很像一个函数 仿函数

	Show<int>(a);
	ShowShow(a);

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//for_each(v.begin(), v.end(), ShowElemt<int>());//匿名对象 匿名仿函数


	//for_each(v.begin(), v.end(), ShowShow);//通过回调函数 谁使用for_each谁去填写回调函数的入口地址

	ShowElemt<int> show;
	//函数对象 做函数参数
	//for_eache算法的 函数传递是元素传递，不是引用传递
	show = for_each(v.begin(), v.end(), show);//匿名对象 匿名仿函数

	cout << "通过for_each算法返回值看调用的次数" << endl;
	
	show.printN();

	//for_each返回的对象
	//结论 要点：分清楚stl算法返回的值是迭代器还是 谓词（函数对象）是stl算法入门的重要点
	system("pause");
	return 0;
}
