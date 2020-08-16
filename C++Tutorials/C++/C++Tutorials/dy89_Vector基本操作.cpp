
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;


void VectorDisplay()
{
	vector<int> v;

	cout << "v length:" << v.size() << endl;
	//插入元素
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);

	cout << "v front:" << v.front() << endl;

	//修改头部元素的值
	//函数返回值当左值，应该返回一个引用
	v.front() = 11;
	v.back() = 55;

	//获取尾部元素
	while (v.size() > 0)
	{
		cout << v.back() << endl;
		v.pop_back();
	}
}

void VectorConstruct()
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);

	vector<int> v2 = v1;//对象初始化
	vector<int> v3(v1.begin(), v1.begin() + 3);

}

void printV(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void VectorRead()
{
	vector<int> v1(10);//提前把内存准备好

	for (size_t i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	printV(v1);
}

//push_back强化记忆
void VectorPuchBack()
{
	vector<int> v1(10);//提前把内存准备好
	v1.push_back(100);
	printV(v1);
	cout << v1.size() << endl;
}


//迭代器
/*
	1  3  5
	当it=v.end()时，迭代器指向开始元素
	当it=v.end()时，迭代器已经遍历完，5的后面

	迭代器种类：


	*/
void VectorIterator()
{
	vector<int> v(10);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = i + 1;
	}

	//正向遍历
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//逆向遍历
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}

}

//删除元素，插入元素
void VectorDelete()
{
	vector<int> v(10);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = i + 1;
	}

	//区间删除
	v.erase(v.begin(), v.begin() + 3);
	printV(v);

	//指定位置删除
	v.erase(v.begin());
	printV(v);

	//根据元素的值
	v[1] = 2;
	v[2] = 2;
	printV(v);

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == 2)
		{
			it = v.erase(it);//当 删除迭代器所指向的元素被删除时，erase删除函数会让it自动下移动
		}
		else
		{
			it++;
		}
	}

	printV(v);

	v.insert(v.begin(), 100);
	v.insert(v.end(), 200);
	printV(v);

}


int main()
{
	/*VectorDisplay();
	VectorConstruct();
	VectorRead();
	VectorPuchBack();
	VectorIterator();*/
	VectorDelete();
	system("pause");
	return 0;
}
