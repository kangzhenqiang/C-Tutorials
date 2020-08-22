
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

/*
	map 元素添加、遍历、删除基本操作
	*/
void mapInsertAndIterator()
{
	map<int, string> maps;

	//插入
	//方法 1
	maps.insert(pair<int, string>(1, "kangzhenqiang"));
	maps.insert(pair<int, string>(2, "wangjing"));
	//方法 2
	maps.insert(make_pair(3, "haohongmei"));
	maps.insert(make_pair(4, "zhangyaoyao"));
	//方法 3
	maps.insert(map<int, string>::value_type(5, "kangzhenqiang"));
	maps.insert(map<int, string>::value_type(6, "wangjing"));
	//方法 4
	maps[7] = "haohongmei";
	maps[8] = "zhangyaoyao";

	//容器遍历
	for (map<int, string>::iterator it = maps.begin(); it != maps.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	while (!maps.empty())
	{
		map<int, string>::iterator it = maps.begin();
		cout << it->first << " " << it->second << endl;
		maps.erase(it);
	}
}

/*四种插入方法异同*/

void mapInsert()
{
	map<int, string> maps;

	//插入
	//方法 1
	pair<map<int, string>::iterator, bool> pair1 = maps.insert(pair<int, string>(1, "kangzhenqiang"));
	if (pair1.second)
	{
		cout << "插入 1 成功" << endl;
	}
	else
	{
		cout << "插入 1 失败" << endl;
	}
	pair<map<int, string>::iterator, bool> pair2 = maps.insert(pair<int, string>(2, "wangjing"));
	if (pair1.second)
	{
		cout << "插入 2 成功" << endl;
	}
	else
	{
		cout << "插入 2 失败" << endl;
	}
	//方法 2
	pair<map<int, string>::iterator, bool> pair3 = maps.insert(make_pair(3, "haohongmei"));
	if (pair1.second)
	{
		cout << "插入 3 成功" << endl;
	}
	else
	{
		cout << "插入 3 失败" << endl;
	}
	pair<map<int, string>::iterator, bool> pair4 = maps.insert(make_pair(4, "zhangyaoyao"));
	if (pair1.second)
	{
		cout << "插入 4 成功" << endl;
	}
	else
	{
		cout << "插入 4 失败" << endl;
	}
	//方法 3
	pair<map<int, string>::iterator, bool> pair5 = maps.insert(map<int, string>::value_type(5, "kangzhenqiang"));
	if (pair1.second)
	{
		cout << "插入 5 成功" << endl;
	}
	else
	{
		cout << "插入 5 失败" << endl;
	}
	pair<map<int, string>::iterator, bool> pair6 = maps.insert(map<int, string>::value_type(6, "wangjing"));
	if (pair1.second)
	{
		cout << "插入 6 成功" << endl;
	}
	else
	{
		cout << "插入 6 失败" << endl;
	}
	//方法 4
	maps[7] = "haohongmei";
	maps[8] = "zhangyaoyao";

	//前三种方法返回的都是pair,若key已经存在则报错
	//方法4 若已经存在则覆盖
}

/*map 查找*/
void mapFind()
{
	map<int, string> maps;

	//插入
	//方法 1
	pair<map<int, string>::iterator, bool> pair1 = maps.insert(pair<int, string>(1, "kangzhenqiang"));
	if (pair1.second)
	{
		cout << "插入 1 成功" << endl;
	}
	else
	{
		cout << "插入 1 失败" << endl;
	}
	pair<map<int, string>::iterator, bool> pair2 = maps.insert(pair<int, string>(2, "wangjing"));
	if (pair1.second)
	{
		cout << "插入 2 成功" << endl;
	}
	else
	{
		cout << "插入 2 失败" << endl;
	}

	//方法 2
	pair<map<int, string>::iterator, bool> pair3 = maps.insert(make_pair(3, "haohongmei"));
	if (pair1.second)
	{
		cout << "插入 3 成功" << endl;
	}
	else
	{
		cout << "插入 3 失败" << endl;
	}
	pair<map<int, string>::iterator, bool> pair4 = maps.insert(make_pair(4, "zhangyaoyao"));
	if (pair1.second)
	{
		cout << "插入 4 成功" << endl;
	}
	else
	{
		cout << "插入 4 失败" << endl;
	}

	map<int, string>::iterator it = maps.find(1);
	if (it == maps.end())
	{
		cout << "key 1 value not extist" << endl;
	}
	else
	{
		cout << it->first << " " << it->second << endl;
	}

	pair<map<int, string>::iterator, map<int, string>::iterator> myPair = maps.equal_range(3);
	/*
		第一个迭代器 >= 5 的位置
		第二个迭代器 = 5 的位置
		*/
	if (myPair.first == maps.end())
	{
		cout << "第一个迭代器 >= 3 的位置不存在" << endl;
	}
	else
	{
		cout << myPair.first->first << '\t' << myPair.first->second << endl;
	}

	if (myPair.second == maps.end())
	{
		cout << "第二个迭代器 > 3 的位置不存在" << endl;
	}
	else
	{
		cout << myPair.second->first << '\t' << myPair.second->second << endl;
	}

}

int main()
{
	mapInsertAndIterator();
	mapInsert();
	mapFind();


	system("pause");
	return 0;
}
